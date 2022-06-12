#pragma once

#include "Boatplane.h"

namespace assignment2
{
	class Airplane;
	class Boatplane;

	class Boat : public Vehicle, public ISailable
	{
		friend class Airplane;

		const static int TRAVEL = 2;
		const static int RESTED = -1;

	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();

		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;

		Boatplane operator+(Airplane& plane);

		void Travel();
	};
}
