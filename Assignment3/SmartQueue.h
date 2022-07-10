#pragma once
#include <queue>

namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		SmartQueue(const SmartQueue& other) = default;
		~SmartQueue() = default;

		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();

	private:
		std::queue<T> mNumberQueue;
		double mSum;
		double mSumSquared;

		uint32_t mCount;
	};

	template<typename T>
	SmartQueue<T>::SmartQueue()
		: mCount(0)
		, mSum(0)
		, mSumSquared(0)
	{
	}

	template<typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		mNumberQueue.push(number);

		mSum += number;
		mSumSquared += number * number;
		++mCount;

		return;
	}

	template<typename T>
	T SmartQueue<T>::Peek()
	{
		return mNumberQueue.front();
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		T ret = mNumberQueue.front();
		
		mNumberQueue.pop();

		mSum -= ret;
		mSumSquared -= ret * ret;
		--mCount;

		return ret;
	}

	template<typename T>
	T SmartQueue<T>::GetMax()
	{
		T max = std::numeric_limits<T>::lowest();

		if (mCount == 0)
		{
			return max;
		}

		std::queue<T> temp = mNumberQueue;

		while (!temp.empty())
		{
			if (temp.front() > max)
			{
				max = temp.front();
			}

			temp.pop();
		}

		return max;
	}

	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();

		if (mCount == 0)
		{
			return min;
		}

		std::queue<T> temp = mNumberQueue;

		while (!temp.empty())
		{
			if (temp.front() < min)
			{
				min = temp.front();
			}

			temp.pop();
		}

		return min;
	}

	template<typename T>
	double SmartQueue<T>::GetAverage()
	{
		return mSum / mCount;
	}

	template<typename T>
	T SmartQueue<T>::GetSum()
	{
		return static_cast<T>(mSum);
	}

	template<typename T>
	double SmartQueue<T>::GetVariance()
	{
		return mSumSquared / mCount - (mSum / mCount * mSum / mCount);
	}

	template<typename T>
	double SmartQueue<T>::GetStandardDeviation()
	{
		return sqrt(mSumSquared / mCount - (mSum / mCount * mSum / mCount));
	}

	template<typename T>
	unsigned int SmartQueue<T>::GetCount()
	{
		return mCount;
	}
}
