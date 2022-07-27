#pragma once

#include <memory>
#include <vector>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		~Storage() = default;

		Storage(const Storage<T>& other);
		Storage(Storage<T>&& other);
		Storage& operator=(const Storage<T>& other);
		Storage& operator=(Storage<T>&& other);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		std::unique_ptr<T[]> mArray;
		unsigned int mSize;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mSize(length)
		, mArray(std::make_unique<T[]>(length))
	{
		memset(mArray.get(), 0, sizeof(T) * mSize);
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mSize(length)
		, mArray(std::make_unique<T[]>(length))
	{
		auto p = mArray.get();

		for (unsigned int i = 0; i < mSize; ++i)
		{
			*p++ = initialValue;
		}
	}

	template<typename T>
	Storage<T>::Storage(const Storage<T>& other)
		: mSize(other.mSize)
		, mArray(std::make_unique<T[]>(mSize))
	{
		for (unsigned int i = 0; i < mSize; ++i)
		{
			mArray[i] = other.mArray[i];
		}
	}

	template<typename T>
	Storage<T>::Storage(Storage<T>&& other)
		: mSize(other.mSize)
		, mArray(std::move(other.mArray))
	{
		other.mSize = 0;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(const Storage<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		if (mSize != other.mSize)
		{
			mSize = other.mSize;

			mArray = std::make_unique<T[]>(mSize);
		}

		for (unsigned int i = 0; i < mSize; ++i)
		{
			mArray[i] = other.mArray[i];
		}
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage<T>&& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mSize = other.mSize;

		mArray = std::move(other.mArray);

		other.mSize = 0;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index >= mSize)
		{
			return false;
		}

		mArray[index] = data;

		return true;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return std::move(mArray);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mSize;
	}
}