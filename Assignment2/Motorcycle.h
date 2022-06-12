#pragma once

#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	const unsigned int MAX_PASSENGER_COUNT = 2;

	class Motorcycle : public Vehicle, public IDrivable
	{
		const static int TRAVEL = 5;
		const static int RESTED = -1;

	public:
		Motorcycle();
		~Motorcycle();

		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;

		void Travel();

	private:
	};
}
