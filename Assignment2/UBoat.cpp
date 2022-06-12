#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(MAX_PASSENGER_COUNT, TRAVEL)
	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		unsigned int sailSpeed = GetSailSpeed();
		unsigned int diveSpeed = GetDiveSpeed();

		return sailSpeed > diveSpeed ? sailSpeed : diveSpeed;
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		double temp = 550 - mPassengersWeight / 10.0;

		return temp > 200 ? static_cast<unsigned int>(temp + 0.5) : 200;
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		return static_cast<unsigned int>(500 * log((mPassengersWeight + 150) / 150.0) + 30 + 0.5);
	}

	void UBoat::Travel()
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