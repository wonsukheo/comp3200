#include "MyMath.h"

namespace lab5
{
	unsigned int MyMath::Ceil(double value)
	{
		int intValue = static_cast<int>(value);

		if (value == static_cast<double>(intValue))
		{
			return intValue;
		}

		return intValue + 1;
	}
}