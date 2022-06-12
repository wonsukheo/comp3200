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
		unsigned int temp = static_cast<unsigned int>(550 - static_cast<double>(mPassengersWeight) / 10 + 0.5);

		return temp > 200 ? temp : 200;
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		return static_cast<unsigned int>(500 * log(static_cast<double>(mPassengersWeight + 150) / 150) + 30 + 0.5);
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