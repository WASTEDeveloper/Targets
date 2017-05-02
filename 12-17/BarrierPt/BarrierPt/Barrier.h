#pragma once

#include <condition_variable>

class Barrier {
public:
	explicit Barrier(std::size_t iCount) :
		mThreshold(iCount), mCount(iCount), mGeneration(0) { 
		if(iCount == 0) throw std::invalid_argument("count cannot be zero.");
	};

	bool Wait() {
		std::unique_lock<std::mutex> lLock(mMutex);
		auto lGen = mGeneration;
		if (!--mCount) {
			mGeneration++;
			mCount = mThreshold;
			mCond.notify_all();
			return true;
		}

		while (lGen == mGeneration) mCond.wait(lLock);
		return false;
	}

private:
	std::mutex mMutex;
	std::condition_variable mCond;

	std::size_t mThreshold;
	std::size_t mCount;

	std::size_t mGeneration;
};