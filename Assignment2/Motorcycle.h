#pragma once

#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	const unsigned int MAX_PASSENGER_COUNT = 2;

	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		~Motorcycle();

		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;
	};
}
