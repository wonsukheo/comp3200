#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount, TRAVEL)
	{
	}

	Boatplane::Boatplane(const Boatplane& other)
		: Vehicle(other)
	{
	}

	Boatplane& Boatplane::operator=(const Boatplane& other)
	{
		Vehicle::operator=(other);

		return *this;
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int sailSpeed = GetSailSpeed();

		return flySpeed > sailSpeed ? flySpeed : sailSpeed;
	}

	unsigned int Boatplane::GetFlySpeed() const
	{

		return static_cast<unsigned int>(150 * exp(-(static_cast<int>(mPassengersWeight) + 500) / 300.0) + 0.5);
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		double temp = 800 - 1.7 * mPassengersWeight;

		return temp > 20 ? static_cast<unsigned int>(temp + 0.5) : 20;
	}

	void Boatplane::Travel()
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