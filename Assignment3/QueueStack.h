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
		QueueStack(const QueueStack& other) = default;
		~QueueStack() = default;

		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();

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
}