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
		mPassengers = static_cast<const Person**>(malloc(sizeof(Person*) * maxPassengersCount));
	}

	Vehicle::Vehicle(unsigned int maxPassengersCount, int status)
		: mMaxPassengersCount(maxPassengersCount)
		, mPassengersCount(0)
		, mPassengersWeight(0)
		, mStatus(status)
		, mTravelDistance(0)
	{
		mPassengers = static_cast<const Person**>(malloc(sizeof(Person*) * maxPassengersCount));
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mMaxPassengersCount(other.mMaxPassengersCount)
		, mPassengersCount(other.mPassengersCount)
		, mPassengersWeight(other.mPassengersWeight)
		, mStatus(other.mStatus)
		, mTravelDistance(other.mTravelDistance)
	{
		mPassengers = static_cast<const Person**>(malloc(sizeof(Person*) * other.mMaxPassengersCount));
	
		if (mPassengers != NULL)
		{
			unsigned int i = 0;

			while (i < mPassengersCount)
			{
				mPassengers[i] = new Person(*(other.mPassengers[i]));

				i++;
			}
		}
	}

	Vehicle::~Vehicle()
	{
		delete[] mPassengers;

		//delete mPassengers;
	}

	Vehicle& Vehicle::operator=(const Vehicle& other)
	{
		if (this == &other)
		{
			return *this;
		}

		delete[] *mPassengers;
		delete mPassengers;

		mMaxPassengersCount = other.mMaxPassengersCount;
		mPassengersCount = other.mPassengersCount;
		mPassengersWeight = other.mPassengersWeight;
		mStatus = other.mStatus;
		mTravelDistance = other.mTravelDistance;

		mPassengers = static_cast<const Person**>(malloc(sizeof(Person*) * other.mMaxPassengersCount));

		if (mPassengers != NULL)
		{
			const Person* start_p = *(other.mPassengers);
			const Person* p = start_p;
			const Person* q = *mPassengers;

			while (static_cast<unsigned int>(p - start_p) < mPassengersCount)
			{
				q = new Person(*p++);
				++q;
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