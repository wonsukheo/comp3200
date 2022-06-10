#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	unsigned int Boat::GetSailSpeed() const
	{
		unsigned int temp = 800 - 10 * mPassengersWeight;

		return temp > 20 ? temp : 20;
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane result(mMaxPassengersCount + plane.mMaxPassengersCount);

		memcpy(result.mPassengers, mPassengers, sizeof(Person*) * mPassengersCount);

		memcpy(result.mPassengers + mPassengersCount, plane.mPassengers, sizeof(Person*) * plane.mPassengersCount);

		result.mPassengersCount = mPassengersCount + plane.mPassengersCount;

		result.mPassengersWeight = mPassengersWeight + plane.mPassengersWeight;

		delete this;
		delete &plane;

		return result;
	}
}