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
		bool mElements[N];
		const size_t mCapacity;
		size_t mSize;
	};

	template<bool B, size_t N>
	FixedBoolVector<B, N>::FixedBoolVector()
		: mCapacity(N)
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

		mElements[mSize++] = element;

		return true;
	}

	template<bool B, size_t N>
	bool FixedBoolVector<B, N>::Remove(const bool element)
	{
		bool* p = mElements;

		while (static_cast<unsigned int>(p - mElements) < mSize)
		{
			if (*p == element)
			{
				while (p - mElements < mSize - 1)
				{
					*p = *(p + 1);

					++p;
				}

				--mSize;

				return true;
			}

			++p;
		}

		return false;
	}

	template<bool B, size_t N>
	bool FixedBoolVector<B, N>::Get(const unsigned int index) const
	{
		//static_assert(index < mSize);

		return mElements[index];
	}

	template<bool B, size_t N>
	bool FixedBoolVector<B, N>::operator[](const unsigned int index) const
	{
		//static_assert(index < mSize);

		return mElements[index];
	}

	template<bool B, size_t N>
	int FixedBoolVector<B, N>::GetIndex(const bool t) const
	{
		const bool* p = mElements;

		while (static_cast<unsigned int>(p - mElements) < mSize)
		{
			if (*p == t)
			{
				return p - mElements;
			}

			++p;
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
