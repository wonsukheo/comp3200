#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount)
		, mPassengersCount(0)
		, mPassengersWeight(0)
		, mStatus(0)
		, mTravelDistance(0)

	{
		mPassengers = new const Person*[mMaxPassengersCount];
	}

	Vehicle::Vehicle(unsigned int maxPassengersCount, int status)
		: Vehicle(maxPassengersCount)
	{
		mStatus = status;
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mMaxPassengersCount(other.mMaxPassengersCount)
		, mPassengersCount(other.mPassengersCount)
		, mPassengersWeight(other.mPassengersWeight)
		, mStatus(other.mStatus)
		, mTravelDistance(other.mTravelDistance)
	{
		mPassengers = new const Person*[other.mMaxPassengersCount];
	
		if (mPassengers != NULL)
		{
			const Person** p = mPassengers;
			const Person** q = other.mPassengers;

			while (p - mPassengers < static_cast<int>(mPassengersCount))
			{
				*p++ = new Person(**q++);
			}
		}
	}

	Vehicle::~Vehicle()
	{	
		for (int i = 0; i < mPassengersCount; ++i)
		{
			delete mPassengers[i];
		}

		delete mPassengers;
	}

	Vehicle& Vehicle::operator=(const Vehicle& other)
	{
		if (this == &other)
		{
			return *this;
		}

		for (int i = 0; i < mPassengersCount; ++i)
		{
			delete mPassengers[i];
		}

		delete mPassengers;

		mMaxPassengersCount = other.mMaxPassengersCount;
		mPassengersCount = other.mPassengersCount;
		mPassengersWeight = other.mPassengersWeight;
		mStatus = other.mStatus;
		mTravelDistance = other.mTravelDistance;

		mPassengers = new const Person*[other.mMaxPassengersCount];

		if (mPassengers != NULL)
		{
			const Person** p = mPassengers;
			const Person** q = other.mPassengers;

			while (p - mPassengers < static_cast<int>(mPassengersCount))
			{
				*p++ = new Person(**q++);
			}
		}

		return *this;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mPassengersCount == mMaxPassengersCount)
		{
			return false;
		}

		*(mPassengers + mPassengersCount++) = person;

		mPassengersWeight += person->GetWeight();

		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= mPassengersCount || mPassengersCount > mMaxPassengersCount)
		{
			return false;
		}

		const Person* p = *(mPassengers + i);

		mPassengersWeight -= p->GetWeight();

		delete p;

		while (i < mPassengersCount - 1)
		{
			*(mPassengers + i) = *(mPassengers + i + 1);

			++i;
		}

		*(mPassengers + i) = NULL;

		--mPassengersCount;

		return true;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		return i >= mPassengersCount ? NULL : *(mPassengers + i);
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPassengersCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}
}