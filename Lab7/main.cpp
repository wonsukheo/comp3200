#include "Lab7.h"
#include <iostream>

using namespace std;
using namespace lab7;

int main()
{
	std::vector<int> keys = { 1, 2, 3, 3 };

	std::vector<char> values = { 'a', 'b', 'c', 'd' };

	std::map<int, char> result = lab7::ConvertVectorsToMap(keys, values);

	for (std::map<int, char>::iterator iter = result.begin(); iter != result.end(); ++iter)
	{
		std::cout << iter->first << iter->second << std::endl;
	}
}