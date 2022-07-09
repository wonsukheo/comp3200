#pragma once

#include <stack>
#include <limits>

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
		static const uint32_t INIT_CAPACITY = 16;

	public:
		SmartStack();
		SmartStack(const T& other) = default;
		~SmartStack() = default;

		void Push(T number);
		T Pop();
		T Peek();
		T GetMax();
		T GetMin();
		T GetSum();
		double GetSumDouble();
		double GetAverage();
		double GetVariance();

	private:		
		std::stack<T> mElements;
		std::stack<T> mMax;
		std::stack<T> mMin;

		uint32_t mSize;
	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mSize(0)
	{
	}

	template<typename T>
	void SmartStack<T>::Push(T number)
	{
		mElements.push(number);

		if (mMax.empty())
		{
			mMax.push(number);
		}
		else
		{
			if (number > mMax.top())
			{
				mMax.push(number);
			}
			else
			{
				mMax.push(mMax.top());
			}
		}

		if (mMin.empty())
		{
			mMin.push(number);
		}
		else
		{
			if (number < mMin.top())
			{
				mMin.push(number);
			}
			else
			{
				mMin.push(mMin.top());
			}
		}

		++mSize;
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T val = mElements.top();

		mElements.pop();
		mMax.pop();
		mMin.pop();
		
		--mSize;

		return val;
	}

	template<typename T>
	T SmartStack<T>::Peek()
	{
		return mElements.top();
	}

	template<typename T>
	T SmartStack<T>::GetMax()
	{
		return mSize == 0 ? std::numeric_limits<T>::max() : mMax.top();
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		return mSize == 0 ? std::numeric_limits<T>::min() : mMin.top();
	}

	template<typename T>
	double SmartStack<T>::GetAverage()
	{
		return GetSumDouble() / mSize;
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		return static_cast<T>(GetSumDouble());
	}

	template<typename T>
	double SmartStack<T>::GetSumDouble()
	{
		double sum = 0;
		std::stack<T> temp;

		for (int i = 0; i < mSize; ++i)
		{
			sum += mElements.top();
			temp.push(mElements.top());

			mElements.pop();
		}

		for (int i = 0; i < mSize; ++i)
		{
			mElements.push(temp.top());

			temp.pop();
		}

		return sum;
	}

	template<typename T>
	double SmartStack<T>::GetVariance()
	{

	}
}