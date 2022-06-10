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
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();

		unsigned int GetMaxSpeed() const;
		unsigned int GetFlySpeed() const;
		unsigned int GetSailSpeed() const;

	private:
	};
}