#pragma once

#include "Vehicle.h"
#include "IDivable.h"
#include "ISailable.h"

namespace assignment2
{
	class UBoat : public Vehicle, public IDivable, public ISailable
	{
		const static int TRAVEL = 2;
		const static int RESTED = -4;
		const static unsigned int MAX_PASSENGER_COUNT = 50;

	public:
		UBoat();
		~UBoat();

		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetDiveSpeed() const;

		void Travel();

	private:

	};
}
