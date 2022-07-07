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
		
		enum { LEN = 32 };
		uint32_t mData[(N + LEN - 1) / LEN];
		size_t mSize;
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
	{
		for (int i = 0; i < N / LEN + 1; ++i)
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

		if (index == -1)
		{
			return false;
		}

		bool firstData = mData[index / LEN] % 2 == 0 ? false : true;

		mData[index / LEN] >>= 1;

		if (index % 32 == 0)
		{
			goto push;
		}

		if (firstData == true)
		{
			mData[index / LEN] += static_cast<uint32_t>(pow(2, index - 1));
		}
		else
		{
			mData[index / LEN] -= static_cast<uint32_t>(pow(2, index - 1));
		}

		//push from next mData[next index]
	push:
		size_t i = index / LEN;

		while (i < (mSize - 1) / LEN)
		{
			bool firstElement = Get((i + 1) * 32);

			if (firstElement == true)
			{
				mData[i] += static_cast<uint32_t>(pow(2, LEN - 1));
			}

			mData[++i] >>= 1;
		}

		--mSize;

		return true;
	}

	template<size_t N>
	const bool FixedVector<bool, N>::Get(const unsigned int index) const
	{
		uint32_t temp = mData[index / LEN] >> index % LEN;

		return temp % 2 == 0 ? false : true;
	}

	template<size_t N>
	const bool FixedVector<bool, N>::operator[](const unsigned int index) const
	{
		uint32_t temp = mData[index / LEN] >> index;

		return temp % 2 == 0 ? false : true;
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(const bool element) const
	{
		size_t index = 0;

		uint32_t temp = mData[index];

		while (index < mSize)
		{
			if (temp % 2 == element)
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
