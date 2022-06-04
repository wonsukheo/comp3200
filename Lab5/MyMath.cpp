#include "MyMath.h"

namespace lab5
{
	unsigned int MyMath::Ceil(float value)
	{
		int intValue = static_cast<int>(value);

		if (value == static_cast<float>(intValue))
		{
			return intValue;
		}

		return intValue + 1;
	}
}