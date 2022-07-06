namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		bool Add(T t);

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
	bool FixedVector<T, N>::Add()
	{

	}
}



