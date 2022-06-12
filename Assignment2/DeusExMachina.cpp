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
		//delete mVehicles;

		mInstance = NULL;
	}

	Vehicle* DeusExMachina::GetVehicle(unsigned int i)
	{
		if (i < mVehicleCount)
		{
			return mVehicles[i];
		}

		return NULL;
	}

	void DeusExMachina::Travel() const
	{
		Vehicle* const* p = mVehicles;

		while (p - mVehicles < static_cast<int>(mVehicleCount))
		{
			(*p)->Travel();

			++p;
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

		Vehicle** p = mVehicles + i;

		while (p - mVehicles < static_cast<int>(mVehicleCount - 1))
		{
			*p = *(p + 1);

			++p;
		}

		p = NULL;

		--mVehicleCount;

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

		Vehicle* const* p = mVehicles;

		while (p - mVehicles < static_cast<int>(mVehicleCount))
		{
			if ((*p)->mTravelDistance > max)
			{
				max = (*p)->mTravelDistance;
				maxIndex = p - mVehicles;
			}

			++p;
		}

		return mVehicles[maxIndex];
	}
}