#pragma once

namespace lab8
{
	template<bool B, size_t N>
	class FixedBoolVector
	{
	public:
		FixedBoolVector();
		FixedBoolVector(const FixedBoolVector& other) = default;
		~FixedBoolVector() = default;

		bool Add(const bool element);
		bool Remove(const bool element);
		bool Get(const unsigned int index) const;
		bool operator[](const unsigned int index) const;
		int GetIndex(const bool element) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		uint32_t mData;
		const size_t mCapacity;
		size_t mSize;
	};

	template<bool B, size_t N>
	FixedBoolVector<B, N>::FixedBoolVector()
		: mCapacity(N)
		, mData(0)
		, mSize(0)
	{
	}

	template<bool B, size_t N>
	bool FixedBoolVector<B, N>::Add(const bool element)
	{
		if (mSize == mCapacity)
		{
			return false;
		}

		mData |= element << mSize++;

		return true;
	}

	template<bool B, size_t N>
	bool FixedBoolVector<B, N>::Remove(const bool element)
	{
		int index = GetIndex(element);

		if (index == -1)
		{
			return false;
		}

		mData >>= 1;
		
		if (element == true)
		{
			mData -= pow(2, index - 1);
		}
		else
		{
			mData += pow(2, index - 1);
		}

		--mSize;

		return true;
	}

	template<bool B, size_t N>
	bool FixedBoolVector<B, N>::Get(const unsigned int index) const
	{
		uint32_t temp = mData >> mSize - 1 - index;

		return temp % 2 == 0 ? false : true;
	}

	template<bool B, size_t N>
	bool FixedBoolVector<B, N>::operator[](const unsigned int index) const
	{
		uint32_t temp = mData >> mSize - 1 - index;

		return temp % 2 == 0 ? false : true;
	}

	template<bool B, size_t N>
	int FixedBoolVector<B, N>::GetIndex(const bool element) const
	{
		size_t index = 0;

		uint32_t temp = mData;
		
		while (index < mSize)
		{
			if (temp % 2 == element)
			{
				return index;
			}

			temp >>= 1;

			++index;
		}

		return -1;
	}

	template<bool B, size_t N>
	size_t FixedBoolVector<B, N>::GetSize() const
	{
		return mSize;
	}

	template<bool B, size_t N>
	size_t FixedBoolVector<B, N>::GetCapacity() const
	{
		return mCapacity;
	}
}
