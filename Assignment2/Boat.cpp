#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount, TRAVEL)
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
		double temp = 800 - 10.0 * mPassengersWeight;

		return temp > 20 ? static_cast<unsigned int>(temp + 0.5) : 20;
	}

	void Boat::Travel()
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

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane result(mMaxPassengersCount + plane.mMaxPassengersCount);

		memcpy(result.mPassengers + mPassengersCount, plane.mPassengers, sizeof(Person*) * plane.mPassengersCount);
		memcpy(result.mPassengers, mPassengers, sizeof(Person*) * mPassengersCount);

		result.mPassengersCount = mPassengersCount + plane.mPassengersCount;
		result.mPassengersWeight = mPassengersWeight + plane.mPassengersWeight;

		memset(mPassengers, 0, sizeof(Person*) * mPassengersCount);
		mPassengersWeight = 0;
		mPassengersCount = 0;

		memset(plane.mPassengers, 0, sizeof(Person*) * plane.mPassengersCount);
		plane.mPassengersWeight = 0;
		plane.mPassengersCount = 0;

		return result;
	}
}