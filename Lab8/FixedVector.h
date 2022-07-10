namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		FixedVector(const FixedVector& other) = default;
		~FixedVector() = default;
		
		bool Add(const T& t);
		bool Remove(const T& t);
		T Get(const unsigned int index) const;
		T& operator[](const unsigned int index) const;
		int GetIndex(const T& t) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		T mElements[N];
		const size_t mCapacity;
		size_t mSize;
	};

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mCapacity(N)
		, mSize(0)
	{
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& t)
	{
		if (mSize == mCapacity)
		{
			return false;
		}

		mElements[mSize++] = t;

		return true;
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& t)
	{
		T* p = mElements;
		
		while (static_cast<unsigned int>(p - mElements) < mSize)
		{
			if (*p == t)
			{
				while (static_cast<unsigned int>(p - mElements) < mSize - 1)
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
	
	template<typename T, size_t N>
	T FixedVector<T, N>::Get(const unsigned int index) const
	{
		//static_assert(index < mSize);

		return mElements[index];
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator[](const unsigned int index) const
	{	
		//static_assert(index < mSize);

		return mElements[index];
	}

	template<typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& t) const
	{
		const T* p = mElements;

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

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return mCapacity;
	}
}