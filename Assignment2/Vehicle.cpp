#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount)
		, mPassengersCount(0)
		, mPassengersWeight(0)
	{
		mPassengers = static_cast<const Person**>(malloc(sizeof(Person*) * maxPassengersCount));
	}

	Vehicle::Vehicle(Vehicle& other)
		: mMaxPassengersCount(other.mMaxPassengersCount)
		, mPassengersCount(other.mPassengersCount)
		, mPassengersWeight(other.mPassengersWeight)
	{
		mPassengers = static_cast<const Person**>(malloc(sizeof(Person*) * other.mMaxPassengersCount));
	
		if (mPassengers != NULL)
		{
			memcpy(mPassengers, other.mPassengers, sizeof(Person*) * mPassengersCount);
		}
	}

	Vehicle::~Vehicle()
	{
		delete[] *mPassengers;

		delete mPassengers;
	}

	Vehicle& Vehicle::operator=(Vehicle& other)
	{
		if (this == &other)
		{
			return *this;
		}

		delete[] mPassengers;

		mMaxPassengersCount = other.mMaxPassengersCount;
		mPassengersCount = other.mPassengersCount;
		mPassengersWeight = other.mPassengersWeight;

		mPassengers = static_cast<const Person**>(malloc(sizeof(Person*) * other.mMaxPassengersCount));

		if (mPassengers != NULL)
		{
			memcpy(mPassengers, other.mPassengers, sizeof(Person*) * mPassengersCount);
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
		if (i >= mPassengersCount)
		{
			return false;
		}

		mPassengersWeight -= (*(mPassengers + i))->GetWeight();

		delete *(mPassengers + i);

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