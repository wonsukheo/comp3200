#include "Lawn.h"
#include "MyMath.h"

namespace lab5
{
	const double Lawn::mSodRollWidth = 0.3;

	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		return MyMath::Ceil(grassType * GetArea() / static_cast<double>(100));
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		return MyMath::Ceil(GetArea() / mSodRollWidth);
	}
}