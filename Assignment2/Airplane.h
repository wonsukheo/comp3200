#pragma once

#include "Vehicle.h"
#include "Boatplane.h"
#include "IDrivable.h"
#include "IFlyable.h"

namespace assignment2
{
	class Boat;
	class Boatplane;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
		friend class Boat;

		const static int TRAVEL = 1;
		const static int RESTED = -3;

	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		unsigned int GetMaxSpeed() const;
		unsigned int GetFlySpeed() const;
		unsigned int GetDriveSpeed() const;

		Boatplane operator+(Boat& boat);	
	
		void Travel();
	};
}