#pragma once

#include <queue>
#include <stack>

#include "SmartStack.h"

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		QueueStack(QueueStack<T>& other) = default;
		~QueueStack() = default;

		void Enqueue(T number);	
		T Peek();
		T Dequeue();	
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount() const;
		unsigned int GetStackCount() const;
		
	private:
		unsigned int mMaxStackSize;
		std::queue<SmartStack<T>> mStackQueue;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
	{
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mMaxStackSize == 0)
		{
			return;
		}

		if (mStackQueue.empty())
		{
			mStackQueue.push(SmartStack<T>());
		}

		SmartStack<T>& currentStack = mStackQueue.back();
		
		if (currentStack.GetCount() == mMaxStackSize)
		{
			mStackQueue.push(SmartStack<T>());

			mStackQueue.back().Push(number);

			return;
		}

		currentStack.Push(number);

		return;
	}
	
	template<typename T>
	T QueueStack<T>::Peek()
	{
		SmartStack<T>& frontStack = mStackQueue.front();

		return frontStack.Peek();
	}
	
	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		SmartStack<T>& frontStack = mStackQueue.front();

		T ret = frontStack.Peek();

		frontStack.Pop();

		if (frontStack.GetCount() == 0)
		{
			mStackQueue.pop();
		}

		return ret;
	}

	
	template<typename T>
	T QueueStack<T>::GetMax() 
	{
		T max = std::numeric_limits<T>::lowest();
		
		if (mStackQueue.empty())
		{
			return max;
		}

		for (unsigned int i = 0; i < mStackQueue.size(); ++i)
		{
			SmartStack<T> firstStack(mStackQueue.front());

			T data = firstStack.GetMax();
			max = data > max ? data : max;

			mStackQueue.pop();

			mStackQueue.push(firstStack);
		}

		return max;
	}
	
	template<typename T>
	T QueueStack<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();

		if (mStackQueue.empty())
		{
			return min;
		}

		for (unsigned int i = 0; i < mStackQueue.size(); ++i)
		{
			SmartStack<T> firstStack = mStackQueue.front();

			T data = firstStack.GetMin();
			min = data < min ? data : min;

			mStackQueue.pop();

			mStackQueue.push(firstStack);
		}

		return min;
	}
	
	template<typename T>
	double QueueStack<T>::GetAverage()
	{
		double sum = 0;

		if (mStackQueue.empty())
		{
			return 0;
		}

		for (unsigned int i = 0; i < mStackQueue.size(); ++i)
		{
			SmartStack<T> firstStack = mStackQueue.front();

			sum += static_cast<double>(firstStack.GetSum());

			mStackQueue.pop();

			mStackQueue.push(firstStack);
		}

		return sum / GetCount();
	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{
		double sum = 0;

		if (mStackQueue.empty())
		{
			return 0;
		}

		for (unsigned int i = 0; i < mStackQueue.size(); ++i)
		{
			SmartStack<T> firstStack = mStackQueue.front();

			sum += static_cast<double>(firstStack.GetSum());

			mStackQueue.pop();

			mStackQueue.push(firstStack);
		}

		return static_cast<T>(sum);
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount() const
	{
		unsigned int count = 0;

		if (mStackQueue.empty())
		{
			return 0;
		}

		SmartStack<T> stack = mStackQueue.front();
		
		count += stack.GetCount();

		if (mStackQueue.size() > 1)
		{
			stack = mStackQueue.back();

			count += stack.GetCount();
		}

		if (mStackQueue.size() > 2)
		{
			count += mMaxStackSize * (mStackQueue.size() - 2);
		}

		return count;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount() const
	{
		return mStackQueue.size();
	}
}