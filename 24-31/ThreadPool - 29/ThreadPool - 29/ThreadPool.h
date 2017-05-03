#pragma once

#include <functional>
#include <thread>
#include <queue>
#include <mutex>
#include <memory>
#include <condition_variable>

template<class T>
struct DataModel
{
	bool isReady;
	T data;

	DataModel() :isReady(false) {}
};

class ThreadPool
{
public:


	class Worker
	{
	private:
		bool isEnabled;
		std::condition_variable cv;
		std::queue<std::function<void()>> workerTasks;
		std::mutex	mMutex;
		std::thread	mThread;

	public:
		Worker() : isEnabled(true), workerTasks(), mThread(&Worker::WorkFunction, this) {};
		~Worker();

		void AppendFunction(std::function<void()>);		// attach function to a worker
		size_t GetTasksAmount();						// get amount of tasks
		bool isEmpty();									// check wether there is no tasks left 

	private:	
		void WorkFunction();								// working on tasks
	};


	ThreadPool(size_t = 1);
	~ThreadPool() {}

	template<class DataType, class FunctionType, class... ARGS>
	std::shared_ptr<DataModel<DataType>> runAsync(FunctionType task, ARGS... _args)
	{
		std::function<DataType()> rfn = std::bind(task, _args...);
		std::shared_ptr<DataModel<DataType>> pData(new DataModel<DataType>());
		std::function<void()> fn = [=](){ pData->data = rfn(); pData->isReady = true;};
		auto pWorker = getFreeWorker();
		pWorker->AppendFunction(fn);
		return pData;
	}

	template<class FunctionType, class... ARGS>
	inline void runAsync(FunctionType task, ARGS... _args)
	{
		auto pWorker = getFreeWorker();
		pWorker->AppendFunction(std::bind(task, _args...));
	}

private:

	std::shared_ptr<Worker> getFreeWorker()
	{
		std::shared_ptr<Worker> pWorker;
		size_t minTasks = UINT32_MAX;

		// searching for the worker with minimum tasks
		for (auto &it : workers)
		{
			if (it->isEmpty())
			{
				return it;
			}
			else if (minTasks > it->GetTasksAmount())
			{
				minTasks = it->GetTasksAmount();
				pWorker = it;
			}
		}

		return pWorker;
	}

	std::vector<std::shared_ptr<Worker>> workers;
};