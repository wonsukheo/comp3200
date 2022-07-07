#pragma once

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
		const bool Get(const unsigned int index) const;
		const bool operator[](const unsigned int index) const;
		int GetIndex(const bool element) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		uint32_t mData;
		size_t mSize;
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mData(0)
		, mSize(0)
	{
	}

	template<size_t N>
	bool FixedVector<bool, N>::Add(const bool element)
	{
		if (mSize == N)
		{
			return false;
		}

		mData |= element << mSize++;

		return true;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Remove(const bool element)
	{
		int index = GetIndex(element);

		if (index == -1)
		{
			return false;
		}

		mData >>= 1;

		if (index == 0)
		{
			--mSize;
			return true;
		}

		if (element == true)
		{
			mData -= static_cast<uint32_t>(pow(2, index - 1));
		}
		else
		{
			mData += static_cast<uint32_t>(pow(2, index - 1));
		}

		--mSize;

		return true;
	}

	template<size_t N>
	const bool FixedVector<bool, N>::Get(const unsigned int index) const
	{
		uint32_t temp = mData >> index;

		return temp % 2 == 0 ? false : true;
	}

	template<size_t N>
	const bool FixedVector<bool, N>::operator[](const unsigned int index) const
	{
		uint32_t temp = mData >> index;

		return temp % 2 == 0 ? false : true;
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(const bool element) const
	{
		size_t index = 0;

		uint32_t temp = mData;
		
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
