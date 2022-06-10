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

		const static unsigned int REST_COUNT = 1;

	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		unsigned int GetMaxSpeed() const;
		unsigned int GetFlySpeed() const;
		unsigned int GetDriveSpeed() const;

		Boatplane operator+(Boat& boat);

	private:
		unsigned int mRestCount;
	};
}