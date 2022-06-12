#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class Vehicle;

	class DeusExMachina
	{
		const static unsigned int MAX_ALLOWED_VEHICLE = 10;

	public:
		static DeusExMachina* GetInstance();

		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
		Vehicle* GetVehicle(unsigned int i);

	private:
		static DeusExMachina* mInstance;

		Vehicle* mVehicles[MAX_ALLOWED_VEHICLE];
		unsigned int mVehicleCount;

		DeusExMachina();
		~DeusExMachina();
	};
}