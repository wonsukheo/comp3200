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
		double temp = -pow((mPassengersWeight / 15.0), 3) + 2.0 * mPassengersWeight + 400;

		return temp > 20 ? static_cast<unsigned int>(temp + 0.5) : 20;
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