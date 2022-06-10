#include "Motorcycle.h"
#include <cmath>

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(MAX_PASSENGER_COUNT)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		unsigned int temp = static_cast<unsigned int>((-pow(static_cast<double>(mPassengersWeight) / 15, 3) + 2 * mPassengersWeight + 400) + 0.5);

		return temp > 20 ? temp : 20;
	}
}