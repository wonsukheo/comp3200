#include "TimeSheet.h"

#include <math.h>

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mMaxEntries(maxEntries)
		, mEntryCount(0)
	{
		mName = new char[strlen(name) + 1];
		strcpy(mName, name);

		mNameString = new std::string(mName);

		mWorkHours = new unsigned int[mMaxEntries];
	}

	TimeSheet::TimeSheet(const TimeSheet& other)
		: mMaxEntries(other.mMaxEntries)
		, mEntryCount(other.mEntryCount)
	{
		mName = new char[strlen(other.mName) + 1];
		strcpy(mName, other.mName);

		mNameString = new std::string(mName);

		mWorkHours = new unsigned int[mMaxEntries];
		memcpy(mWorkHours, other.mWorkHours, sizeof(unsigned int) * mEntryCount);
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mName;
		delete[] mWorkHours;
		delete mNameString;
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mMaxEntries = other.mMaxEntries;
		mEntryCount = other.mEntryCount;

		delete[] mName;
		delete[] mWorkHours;
		delete mNameString;

		mName = new char[strlen(other.mName) + 1];
		strcpy(mName, other.mName);

		mNameString = new std::string(mName);

		mWorkHours = new unsigned int[mMaxEntries];
		memcpy(mWorkHours, other.mWorkHours, sizeof(unsigned int) * mMaxEntries);

		return *this;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours < 1 || timeInHours > 10)
		{
			return;
		}

		if (mEntryCount == mMaxEntries)
		{
			return;
		}

		mWorkHours[mEntryCount++] = static_cast<unsigned int>(timeInHours);
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (mEntryCount == 0 || index >= mEntryCount)
		{
			return -1;
		}

		return mWorkHours[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		int sum = 0;
		unsigned int* p = mWorkHours;

		while (p - mWorkHours < static_cast<int>(mEntryCount))
		{
			sum += *p++;
		}

		return sum;
	}

	float TimeSheet::GetAverageTime() const
	{
		return mEntryCount == 0 ? 0.0f : static_cast<float>(GetTotalTime()) / mEntryCount;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		if (mEntryCount == 0)
		{
			return 0.0f;
		}

		float avg = GetAverageTime();

		float variance = 0.0f;

		unsigned int* p = mWorkHours;

		while (p - mWorkHours < static_cast<int>(mEntryCount))
		{
			variance += (*p - avg) * (*p - avg);
			++p;
		}

		variance /= mEntryCount;

		return static_cast<float>(sqrt(variance));
	}

	const std::string& TimeSheet::GetName() const
	{
		return *mNameString;
	}
}