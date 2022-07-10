#pragma once

#include <iostream>

namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		FixedVector(const FixedVector& other) = default;
		~FixedVector() = default;

		bool Add(const bool element);
		bool Remove(const bool element);
		bool Get(const unsigned int index) const;
		bool operator[](const unsigned int index) const;
		int GetIndex(const bool element) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		enum { LEN = 32 };
		uint32_t mData[(N + LEN - 1) / LEN];
		size_t mSize;
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
	{
		int iter = N / LEN == 0 ? 1 : N / LEN;

		for (int i = 0; i < iter; ++i)
		{
			mData[i] = 0;
		}
	}

	template<size_t N>
	bool FixedVector<bool, N>::Add(const bool element)
	{
		if (mSize == N)
		{
			return false;
		}

		mData[mSize / LEN] |= element << mSize;

		++mSize;

		return true;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Remove(const bool element)
	{
		int index = GetIndex(element);
		unsigned int dataIndex = index / LEN;

		if (index == -1)
		{
			return false;
		}

		mData[dataIndex] >>= 1;

		if (index % LEN == 0)
		{
			goto push;
		}
		else
		{
			if (element == true)
			{
				mData[dataIndex] &= ~(1 << (index - 1));
			}
			else
			{
				mData[dataIndex] |= (1 << (index - 1));
			}
		}

	push:
		while (dataIndex < (mSize - 1) / LEN)
		{
			bool firstElement = Get(LEN * (dataIndex + 1));

			if (firstElement == true)
			{
				mData[dataIndex] |= (1 << (LEN * (dataIndex + 1) - 1));
			}
			else
			{
				mData[dataIndex] &= ~(1 << (LEN * (dataIndex + 1) - 1));
			}

			mData[++dataIndex] >>= 1;
		}

		--mSize;

		return true;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Get(const unsigned int index) const
	{
		uint32_t temp = mData[index / LEN] >> index % LEN;

		return temp % 2 == 0 ? false : true;
	}

	template<size_t N>
	bool FixedVector<bool, N>::operator[](const unsigned int index) const
	{
		return Get(index);
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(const bool element) const
	{
		size_t index = 0;

		uint32_t temp = mData[index];

		while (index < mSize)
		{			
			if (static_cast<bool>(temp & 1) == element)
			{
				return index;
			}

			temp >>= 1;

			++index;

			if (index % LEN == 0)
			{
				temp = mData[index / LEN];
			}
		}

		return -1;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}
}
