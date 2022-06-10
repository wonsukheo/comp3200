#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mInstance = NULL;

	DeusExMachina::DeusExMachina()
		: mVehicleCount(0)
	{
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mInstance == NULL)
		{
			mInstance = new DeusExMachina();

			return mInstance;
		}

		return mInstance;
	}

	void DeusExMachina::Travel() const
	{
		Vehicle* p = mVehicles[0];

		while (p - mVehicles[0] < MAX_ALLOWED_VEHICLE)
		{
			p->
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mVehicleCount >= MAX_ALLOWED_VEHICLE)
		{
			return false;
		}

		mVehicles[mVehicleCount] = vehicle;

		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mVehicleCount)
		{
			return false;
		}

		Vehicle** p = mVehicles + i;

		while (p - mVehicles < mVehicleCount)
		{
			*p = *(p + 1);

			++p;
		}

		*p = NULL;

		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		return NULL;
	}
}