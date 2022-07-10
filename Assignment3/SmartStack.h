#pragma once

#include <stack>
#include <limits>

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();
		SmartStack(const SmartStack& other) = default;
		~SmartStack() = default;

		void Push(T number);
		T Pop();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();

	private:		
		std::stack<T> mNumStack;
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;
		double mSum;
		double mSumSquared;
		uint32_t mCount;
	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mCount(0)
		, mSum(0)
		, mSumSquared(0)
	{
	}
	/*
	template<typename T>
	SmartStack<T>::SmartStack(const SmartStack& other)
		: mCount(other.mCount)
		, mSum(other.mSum)
		, mSumSquared(other.mSumSquared)
	{
		mNumStack = other.mNumStack;
		mMinStack = other.mMinStack;
		mMaxStack = other.mMaxStack;
	}
	*/
	template<typename T>
	void SmartStack<T>::Push(T number)
	{
		mNumStack.push(number);

		if (mMaxStack.empty())
		{
			mMaxStack.push(number);
		}
		else
		{
			if (number > mMaxStack.top())
			{
				mMaxStack.push(number);
			}
			else
			{
				mMaxStack.push(mMaxStack.top());
			}
		}

		if (mMinStack.empty())
		{
			mMinStack.push(number);
		}
		else
		{
			if (number < mMinStack.top())
			{
				mMinStack.push(number);
			}
			else
			{
				mMinStack.push(mMinStack.top());
			}
		}

		mSum += static_cast<double>(number);
		mSumSquared += number * number;
		++mCount;
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T val = mNumStack.top();

		mNumStack.pop();
		mMaxStack.pop();
		mMinStack.pop();
		
		mSum -= val;
		mSumSquared -= val * val;
		--mCount;

		return val;
	}

	template<typename T>
	T SmartStack<T>::Peek()
	{
		return mNumStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMax()
	{
		return mCount == 0 ? std::numeric_limits<T>::lowest() : mMaxStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		return mCount == 0 ? std::numeric_limits<T>::max() : mMinStack.top();
	}
	
	template<typename T>
	double SmartStack<T>::GetAverage()
	{
		return mSum / mCount;
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		return static_cast<T>(mSum);
	}

	template<typename T>
	double SmartStack<T>::GetVariance()
	{
		return mSumSquared / mCount - (mSum / mCount * mSum / mCount);
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation()
	{
		return sqrt(mSumSquared / mCount - (mSum / mCount * mSum / mCount));
	}

	template<typename T>
	unsigned int SmartStack<T>::GetCount()
	{
		return mCount;
	}
}