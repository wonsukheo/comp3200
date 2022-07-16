#pragma once

#include <vector>
#include <memory>

namespace lab9
{
	template<typename T>
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize);
		~ObjectPool() = default;
		ObjectPool(const T& other) = delete;
		ObjectPool& operator=(const T& other) = delete;

		T* Get();
		void Return(T* ptr);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();
	private:
		size_t mMaxPoolSize;
		std::vector<std::unique_ptr<T>> mObjects;
	};

	template<typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
	{
	}

	template<typename T>
	T* ObjectPool<T>::Get()
	{
		if (mObjects.empty())
		{
			return new T();
		}

		auto it = mObjects.begin();

		T* retPtr = it->release();

		mObjects.erase(mObjects.begin());

		return retPtr;
	}

	template<typename T>
	void ObjectPool<T>::Return(T* ptr)
	{
		if (mObjects.size() == mMaxPoolSize)
		{
			delete ptr;
		}

		mObjects.push_back(std::unique_ptr<T>(ptr));
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
