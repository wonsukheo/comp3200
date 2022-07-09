#pragma once

#include <queue>
#include <stack>

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		QueueStack(QueueStack& other);
		~QueueStack();

		QueueStack& operator=(QueueStack& other);
		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();

	private:
		unsigned int mMaxStackSize;
		std::queue<std::stack<T>> mStackQueue;
		uint32_t mCount;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mCount(0)
	{
	}

	template<typename T>
	QueueStack<T>::QueueStack(QueueStack<T>& other)
		: mMaxStackSize(maxStackSize)
		, mCount(0)
	{
		for (int i = 0; i <= mCount;)
		{
			std::stack<T>& firstStack = other.mStackQueue.front();
			std::stack<T> temp = new std::stack<T>;
			std::stack<T> temp2 = new std::stack<T>;

			while (!firstStack.empty())
			{
				T num = firstStack.top();

				firstStack.pop();

				temp.push(num);
				temp2.push(num);

				++i;
			}

			other.mStackQueue.pop();
			other.mStackQueue.push(temp2);

			mStackQueue.push(temp);

			delete firstStack;
		}
	}

	template<typename T>
	QueueStack& QueueStack<T>::operator=(QueueStack& other)
	{
		
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
		while (!mStackQueue.empty())
		{
			delete mStackQueue.front();

			mStackQueue.pop();
		}
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mStackQueue.empty())
		{
			mStackQueue.push(new std::stack<T>);
		}

		std::stack<T>& currentStack = mStackQueue.back();
		
		if (currentStack.size() == mMaxStackSize)
		{
			mStackQueue.push(new std::stack<T>);

			currentStack = mStackQueue.back();
		}

		currentStack.push(number);
		++mCount;

		return void;
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		std::stack<T>& frontStack = mStackQueue.front();

		return frontStack.top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		std::stack<T>& frontStack = mStackQueue.front();

		T ret = frontStack.top();

		frontStack.pop();
		--mCount;

		return ret;
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		T max = std::numeric_limits<T>::min();
		
		if (mCount == 0)
		{
			return max;
		}

		for (int i = 0; i <= mCount;)
		{
			std::stack<T>& firstStack = mStackQueue.front();
			std::stack<T> temp = new std::stack<T>;

			while (!firstStack.empty())
			{
				T num = firstStack.top();

				max = num > max ? num : max;

				firstStack.pop();

				temp.push(num);

				++i;
			}

			mStackQueue.pop();
			mStackQueue.push(temp);

			delete firstStack;
		}

		return max;
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();

		if (mCount == 0)
		{
			return min;
		}

		for (int i = 0; i <= mCount;)
		{
			std::stack<T>& firstStack = mStackQueue.front();
			std::stack<T> temp = new std::stack<T>;

			while (!firstStack.empty())
			{
				T num = firstStack.top();

				min = num < min ? num : min;

				firstStack.pop();

				temp.push(num);

				++i;
			}

			mStackQueue.pop();
			mStackQueue.push(temp);

			delete firstStack;
		}

		return min;
	}

	template<typename T>
	double QueueStack<T>::GetAverage()
	{
		double sum = 0;

		if (mCount == 0)
		{
			return sum;
		}

		for (int i = 0; i <= mCount;)
		{
			std::stack<T>& firstStack = mStackQueue.front();
			std::stack<T> temp = new std::stack<T>;

			while (!firstStack.empty())
			{
				sum += firstStack.top();

				firstStack.pop();

				temp.push(num);

				++i;
			}

			mStackQueue.pop();
			mStackQueue.push(temp);

			delete firstStack;
		}

		return sum / mCount;
	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{
		double sum = 0;

		if (mCount == 0)
		{
			return static_cast<T>(sum);
		}

		for (int i = 0; i <= mCount;)
		{
			std::stack<T>& firstStack = mStackQueue.front();
			std::stack<T> temp = new std::stack<T>;

			while (!firstStack.empty())
			{
				sum += firstStack.top();

				firstStack.pop();

				temp.push(num);

				++i;
			}

			mStackQueue.pop();
			mStackQueue.push(temp);

			delete firstStack;
		}

		return static_cast<T>(sum);
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount()
	{
		return mCount;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount()
	{
		return mStackQueue.size();
	}
}