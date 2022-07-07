#pragma once

namespace lab8
{
	template<bool, size_t N>
	class FixedBoolVector
	{
	public:
		FixedBoolVector();
		FixedBoolVector(const FixedBoolVector& other) = default;
		~FixedBoolVector() = default;

		bool Add(const bool element);
		bool Remove(const bool element);
		const bool& Get(const unsigned int index) const;
		const bool& operator[](const unsigned int index) const;
		int GetIndex(const bool element) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		int32_t mData;
		const size_t mCapacity;
		size_t mSize;
	};

	template<bool T, size_t N>
	FixedBoolVector<T, N>::FixedBoolVector()
		: mCapacity(N)
		, mData(0)
		, mSize(0)
	{
	}

	template<bool T, size_t N>
	bool FixedBoolVector<T, N>::Add(const bool element)
	{
		if (mSize == mCapacity)
		{
			return false;
		}

		mData |= element << mSize++;

		return true;
	}

	template<bool T, size_t N>
	bool FixedBoolVector<T, N>::Remove(const bool element)
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

	template<bool T, size_t N>
	const bool& FixedBoolVector<T, N>::Get(const unsigned int index) const
	{
		int32_t temp = mData >> mSize - 1 - index;

		return temp % 2 == 0 ? false : true;
	}

	template<bool T, size_t N>
	const bool& FixedBoolVector<T, N>::operator[](const unsigned int index) const
	{
		int32_t temp = mData >> mSize - 1 - index;

		return temp % 2 == 0 ? false : true;
	}

	template<bool T, size_t N>
	int FixedBoolVector<T, N>::GetIndex(const bool element) const
	{
		size_t index = 0;

		int32_t temp = mData;
		
		while (index < mSize)
		{
			if (static_cast<bool>(temp % 2) == element)
			{
				return index;
			}

			temp >>= 1;

			++index;
		}

		return -1;
	}

	template<bool T, size_t N>
	size_t FixedBoolVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template<bool T, size_t N>
	size_t FixedBoolVector<T, N>::GetCapacity() const
	{
		return mCapacity;
	}
}
