#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mInstance = NULL;

	DeusExMachina::DeusExMachina()
		: mVehicleCount(0)
	{
		memset(mVehicles, 0, sizeof(Vehicle*) * MAX_ALLOWED_VEHICLE);
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mInstance == NULL)
		{
			mInstance = new DeusExMachina();
		}

		return mInstance;
	}

	DeusExMachina::~DeusExMachina()
	{
		delete mInstance;
	}

	void DeusExMachina::Travel() const
	{
		unsigned int i = 0;

		while (i < mVehicleCount)
		{
			mVehicles[i]->Travel();

			++i;
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mInstance == NULL)
		{
			return false;
		}

		if (mVehicleCount >= MAX_ALLOWED_VEHICLE)
		{
			return false;
		}

		mVehicles[mVehicleCount++] = vehicle;

		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mVehicleCount)
		{
			return false;
		}

		while (i < mVehicleCount - 1)
		{
			mVehicles[i] = mVehicles[i + 1];

			++i;
		}

		mVehicles[i] = NULL;

		mVehicleCount--;

		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mVehicleCount == 0)
		{
			return NULL;
		}

		unsigned int max = 0;
		unsigned int maxIndex = 0;

		unsigned int i = 0;

		Vehicle* p = *mVehicles;

		while (i < mVehicleCount)
		{
			if (p->mTravelDistance > max)
			{
				max = p->mTravelDistance;
				maxIndex = i;
			}

			p = *(mVehicles + ++i);
		}

		return mVehicles[maxIndex];
	}
}