#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;
		
		unsigned int mSize = keys.size() < values.size() ? keys.size() : values.size();
		typename std::vector<K>::const_iterator p = keys.begin();
		typename std::vector<V>::const_iterator q = values.begin();

		while (mSize-- != 0)
		{
			m.insert(std::pair<K, V>(*p++, *q++));
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;

		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->first);
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;

		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->second);
		}

		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;

		for (typename std::vector<T>::const_reverse_iterator iter = v.rbegin(); iter != v.rend(); ++iter)
		{
			rv.push_back(*iter);
		}

		return rv;
	}

	template <class InputIterator, typename T>
	InputIterator myFind(InputIterator first, InputIterator last, const T& val)
	{
		while (first != last)
		{
			if (*first == val)
			{
				return first;
			}

			++first;
		}

		return last;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;

		for (typename std::vector<T>::const_iterator iter = v1.begin(); iter != v1.end(); ++iter)
		{
			if (combined.empty())
			{
				combined.push_back(*iter);
				continue;
			}

			if (::myFind(combined.begin(), combined.end(), *iter) == combined.end())
			{
				combined.push_back(*iter);
			}
		}

		for (typename std::vector<T>::const_iterator iter = v2.begin(); iter != v2.end(); ++iter)
		{
			if (combined.empty())
			{
				combined.push_back(*iter);
				continue;
			}

			if (::myFind(combined.begin(), combined.end(), *iter) == combined.end())
			{
				combined.push_back(*iter);
			}
		}

		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;

		for (typename std::map<K, V>::const_iterator iter = m1.begin(); iter != m1.end(); ++iter)
		{
			if (combined.empty())
			{
				combined.insert(std::pair<K, V>(iter->first, iter->second));
				continue;
			}

			if (::myFind(combined.begin(), combined.end(), *iter) == combined.end())
			{
				combined.insert(std::pair<K, V>(iter->first, iter->second));
			}
		}

		for (typename std::map<K, V>::const_iterator iter = m2.begin(); iter != m2.end(); ++iter)
		{
			if (combined.empty())
			{
				combined.insert(std::pair<K, V>(iter->first, iter->second));
				continue;
			}

			if (::myFind(combined.begin(), combined.end(), *iter) == combined.end())
			{
				combined.insert(typename std::pair<K, V>(iter->first, iter->second));
			}
		}

		return combined;
	}

	template <typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		typename std::vector<T>::const_iterator iter = v.begin();

		if (!v.empty())
		{
			os << *iter++;
		}

		for (; iter != v.end(); ++iter)
		{
			os << ", " << *iter;
		}

		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			os << "{ " << iter->first << ", " << iter->second << " }" << std::endl;
		}

		return os;
	}
}
