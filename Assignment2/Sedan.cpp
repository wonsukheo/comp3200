#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(MAX_PASSENGER_COUNT, TRAVEL)
		, mTrailer(NULL)
		, mRested(RESTED)
	{
	}

	Sedan::~Sedan()
	{
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mTrailer != NULL)
		{
			return false;
		}

		mTrailer = trailer;
		mRested = TRAILER_RESTED;

		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer == NULL)
		{
			return false;
		}
		
		delete mTrailer;

		mTrailer = NULL;
		mRested = RESTED;

		return true;
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int totalWeight = mTrailer == NULL ? mPassengersWeight : mPassengersWeight + mTrailer->GetWeight();

		if (totalWeight > 350)
		{
			return 300;
		}
		else if (totalWeight > 260)
		{
			return 380;
		}
		else if (totalWeight > 160)
		{
			return 400;
		}
		else if (totalWeight > 80)
		{
			return 458;
		}

		return 480;
	}

	void Sedan::Travel()
	{
		if (mStatus > 0)
		{
			--mStatus;

			mTravelDistance += GetMaxSpeed();

			return;
		}

		--mStatus;

		if (mStatus == mRested)
		{
			mStatus = TRAVEL;
		}
	}
}