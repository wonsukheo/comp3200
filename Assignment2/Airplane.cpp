#include <cmath>

#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
		, mRestCount(REST_COUNT)
	{
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int driveSpeed = GetDriveSpeed();

		return flySpeed > driveSpeed ? flySpeed : driveSpeed;
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		return  static_cast<unsigned int>(200 * exp((-static_cast<int>(mPassengersWeight) + 800) / static_cast<double>(500)) + 0.5);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		return  static_cast<unsigned int>(4 * exp((-static_cast<int>(mPassengersWeight) + 400) / static_cast<double>(70)) + 0.5);
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane result(mMaxPassengersCount + boat.mMaxPassengersCount);
		
		memcpy(result.mPassengers, mPassengers, sizeof(Person*) * mPassengersCount);

		memcpy(result.mPassengers + mPassengersCount, boat.mPassengers, sizeof(Person*) * boat.mPassengersCount);

		result.mPassengersCount = mPassengersCount + boat.mPassengersCount;

		result.mPassengersWeight = mPassengersWeight + boat.mPassengersWeight;

		delete this;
		delete &boat;

		return result;
	}
}