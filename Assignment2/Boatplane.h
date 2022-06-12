#pragma once

#include "Vehicle.h"
#include "ISailable.h"
#include "IFlyable.h"
#include "Airplane.h"
#include "Boat.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public ISailable, public IFlyable
	{
		friend class Airplane;
		friend class Boat;

		const static int TRAVEL = 1;
		const static int RESTED = -3;

	public:
		Boatplane(unsigned int maxPassengersCount);
		Boatplane(const Boatplane& other);

		Boatplane& operator=(const Boatplane& other);

		~Boatplane();

		unsigned int GetMaxSpeed() const;
		unsigned int GetFlySpeed() const;
		unsigned int GetSailSpeed() const;

		void Travel();
	};
}