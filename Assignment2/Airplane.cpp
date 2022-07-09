#include <cmath>

#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount, TRAVEL)
	{
	}

	Airplane::~Airplane()
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
		return  static_cast<unsigned int>(200 * exp((-static_cast<int>(mPassengersWeight) + 800) / 500.0) + 0.5);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		return  static_cast<unsigned int>(4 * exp((-static_cast<int>(mPassengersWeight) + 400) / 70.0) + 0.5);
	}

	void Airplane::Travel()
	{
		if (mStatus > 0)
		{
			--mStatus;

			mTravelDistance += GetMaxSpeed();

			return;
		}

		--mStatus;

		if (mStatus == RESTED)
		{
			mStatus = TRAVEL;
		}
	}

	Boatplane& Airplane::operator+(Boat& boat)
	{
		Boatplane result(mMaxPassengersCount + boat.mMaxPassengersCount);
		
		memcpy(result.mPassengers, mPassengers, sizeof(Person*) * mPassengersCount);

		memcpy(result.mPassengers + mPassengersCount, boat.mPassengers, sizeof(Person*) * boat.mPassengersCount);

		result.mPassengersCount = mPassengersCount + boat.mPassengersCount;

		result.mPassengersWeight = mPassengersWeight + boat.mPassengersWeight;

		memset(mPassengers, 0, sizeof(Person*) * mPassengersCount);
		mPassengersWeight = 0;
		mPassengersCount = 0;

		memset(boat.mPassengers, 0, sizeof(Person*) * boat.mPassengersCount);
		boat.mPassengersWeight = 0;
		boat.mPassengersCount = 0;

		return result;
	}
}