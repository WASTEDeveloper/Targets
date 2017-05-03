#include "ThreadPool.h"

void ThreadPool::Worker::WorkFunction()
{
	// when thread is awaken look for a job
	while (isEnabled)
	{
		std::unique_lock<std::mutex> mlocker(mMutex);

		cv.wait(mlocker, [&]() { return !workerTasks.empty() || !isEnabled; });

		// looking for a job
		while (!workerTasks.empty())
		{
			std::function<void()> fn = workerTasks.front();

			mlocker.unlock();
			fn();

			mlocker.lock();
			workerTasks.pop();
		}
	}
}

ThreadPool::Worker::~Worker()
{
	isEnabled = false;
	cv.notify_one();
	mThread.join();
}

void ThreadPool::Worker::AppendFunction(std::function<void()> fn)
{
	std::unique_lock<std::mutex> locker(mMutex);
	workerTasks.push(fn);
	cv.notify_one();
}

size_t ThreadPool::Worker::GetTasksAmount()
{
	std::unique_lock<std::mutex> locker(mMutex);
	return workerTasks.size();
}

bool ThreadPool::Worker::isEmpty()
{
	std::unique_lock<std::mutex> locker(mMutex);
	return workerTasks.empty();
}

ThreadPool::ThreadPool(size_t threadsNumber)
{
	if (threadsNumber == 0)
		throw std::logic_error("threads number at least 1!");
	for (size_t i = 0; i<threadsNumber; i++)
	{
		std::shared_ptr<Worker> pWorker(new Worker);
		workers.push_back(pWorker);
	}
}