#pragma once

#include <queue>

namespace lab9
{
	template<typename T>
	class ObjectPool 
	{
	public:
		ObjectPool(size_t maxPoolSize);
		virtual ~ObjectPool();
		ObjectPool(const T& other) = delete;
		ObjectPool& operator=(const T& other) = delete;

		T* Get();
		void Return(T* ptr);
		size_t GetFreeObjectCount() const;
		size_t GetMaxFreeObjectCount() const;

	private:
		const size_t mMaxPoolSize;
		std::queue<T*> mObjects;
	};

	template<typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
	{
	}

	template<typename T>
	ObjectPool<T>::~ObjectPool()
	{
		while (!mObjects.empty())
		{
			T* object = mObjects.front();

			mObjects.pop();

			delete object;
		}
	}

	template<typename T>
	T* ObjectPool<T>::Get()
	{
		if (mObjects.empty())
		{
			return new T();
		}

		T* ret = mObjects.front();

		mObjects.pop();

		return ret;
	}

	template<typename T>
	void ObjectPool<T>::Return(T* ptr)
	{
		if (mObjects.size() == mMaxPoolSize)
		{
			delete ptr;
		}
		else
		{
			mObjects.push(ptr);
		}
		
	}

	template<typename T>
	size_t ObjectPool<T>::GetFreeObjectCount() const
	{
		return mObjects.size();
	}

	template<typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount() const
	{
		return mMaxPoolSize;
	}
}
