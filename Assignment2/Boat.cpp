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
		unsigned int temp = static_cast<unsigned int>(800 - static_cast<double>(10) * mPassengersWeight + 0.5);

		return temp > 20 ? temp : 20;
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

		memcpy(result.mPassengers, mPassengers, sizeof(Person*) * mPassengersCount);

		memcpy(result.mPassengers + mPassengersCount, plane.mPassengers, sizeof(Person*) * plane.mPassengersCount);

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