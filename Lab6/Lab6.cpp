#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}

		int sum = 0;
		
		const int* p = &v[0];
		const int* q = &v[v.size() - 1];

		while (true)
		{
			sum += *p;

			if (p++ == q)
			{
				break;
			}
		}

		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return INT_MAX;
		}

		int min = v[0];

		const int* p = &v[1];
		const int* q = &v[v.size() - 1];

		while (true)
		{
			min = *p < min ? *p : min;

			if (p++ == q)
			{
				break;
			}
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return INT_MIN;
		}

		int max = v[0];

		const int* p = &v[1];
		const int* q = &v[v.size() - 1];

		while (true)
		{
			max = *p > max ? *p : max;

			if (p++ == q)
			{
				break;
			}
		}

		return max;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0.f;
		}

		return Sum(v) / static_cast<float>(v.size());
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		std::vector<int> occurrence;
		occurrence.reserve(v.size());
		occurrence.assign(v.size(), 0);

		for (int i = 0; i < v.size(); ++i)
		{
			for (int j = 0; j < v.size(); ++j)
			{
				if (v[i] == v[j])
				{
					++occurrence[i];
					break;
				}
			}
		}

		int max = 0;
		int index = 0;

		for (int i = 0; i < occurrence.size(); ++i)
		{
			if (occurrence[i] > max)
			{
				max = occurrence[i];
				index = i;
			}
		}

		return v.at(index);
	}

	void SortDescending(std::vector<int>& v)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			int maxValue = v[i];
			int maxIndex = i;

			for (int j = i + 1; j < v.size(); ++j)
			{
				if (v[j] > maxValue)
				{
					maxValue = v[j];
					maxIndex = j;
				}
			}

			v[maxIndex] = v[i];
			v[i] = maxValue;
		}
	}

}