#pragma once

#include <vector>

namespace lab9
{
	template<typename T>
	class ObjectPool final
	{
	public:
		ObjectPool(size_t maxPoolSize);
		~ObjectPool();
		ObjectPool(const T& other) = delete;
		ObjectPool& operator=(const T& other) = delete;

		T* Get();
		void Return(T* ptr);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		size_t mMaxPoolSize;
		std::vector<T*> mObjects;
	};

	template<typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
	{
		mObjects.reserve(maxPoolSize);
	}

	template<typename T>
	ObjectPool<T>::~ObjectPool()
	{
		for (auto it = mObjects.begin(); it != mObjects.end(); ++it)
		{
			delete *it;
		}
	}

	template<typename T>
	T* ObjectPool<T>::Get()
	{
		if (mObjects.empty())
		{
			return new T();
		}

		T* ret = mObjects[0];

		mObjects.erase(mObjects.begin());

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
			mObjects.push_back(ptr);
		}
		
	}

	template<typename T>
	size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mObjects.size();
	}

	template<typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxPoolSize;
	}
}
