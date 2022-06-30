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

		for (std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->first);
		}

		return v;
	}
}
