#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
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
		return static_cast<unsigned int>(150 * exp((static_cast<int>(mPassengersWeight) + 500) / static_cast<double>(300)) + 0.5);
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		unsigned int temp = static_cast<unsigned int>(800 - 1.7 * mPassengersWeight + 0.5);

		return temp > 20 ? temp : 20;
	}
}