#include "Motorcycle.h"
#include <cmath>

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(MAX_PASSENGER_COUNT, TRAVEL)
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

	void Motorcycle::Travel()
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
}