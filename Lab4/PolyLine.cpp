#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mCount(0)
	{
		memset(mPoints, 0, sizeof(Point*) * MAX_COUNT);
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mCount(other.mCount)
	{
		memcpy(mPoints, other.mPoints, sizeof(Point*) * MAX_COUNT);
	}
	
	void PolyLine::operator=(const PolyLine& other)
	{
		if (this == &other)
		{
			return;
		}

		mCount = other.mCount;
		
		memcpy(mPoints, other.mPoints, sizeof(Point*) * MAX_COUNT);
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCount == MAX_COUNT)
		{
			return false;
		}

		mPoints[mCount] = new Point(x, y);

		++mCount;

		return true;
	}

	PolyLine::~PolyLine()
	{
		unsigned int i = 0;

		while (i < mCount)
		{
			delete mPoints[i];

			mPoints[i++] = NULL;
		}

		mCount = 0;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mCount == MAX_COUNT || point == NULL)
		{
			return false;
		}

		mPoints[mCount] = point;

		++mCount;

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mCount)
		{
			return false;
		}

		while (i != mCount - 1)
		{
			delete mPoints[i];
			mPoints[i] = mPoints[i + 1];
		}

		delete mPoints[i];
		mPoints[i] = NULL;

		return true;
	}
	
	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		float minX = mPoints[0]->mX;
		float minY = mPoints[0]->mY;

		float maxX = minX;
		float maxY = minY;

		if (mCount < 1)
		{
			return false;
		}

		for (int i = 1; i < static_cast<int>(mCount); ++i)
		{
			if (mPoints[i]->mX < minX)
			{
				minX = mPoints[i]->mX;
			}

			if (mPoints[i]->mY < minY)
			{
				minY = mPoints[i]->mY;
			}

			if (mPoints[i]->mX > maxX)
			{
				maxX = mPoints[i]->mX;
			}

			if (mPoints[i]->mY > maxY)
			{
				maxY = mPoints[i]->mY;
			}
		}

		if (minX < maxX && minY < maxY)
		{
			outMin->mX = minX;
			outMin->mY = minY;

			outMax->mX = maxX;
			outMax->mY = maxY;
		}

		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (mCount == 0 || i >= mCount)
		{
			return NULL;
		}

		return mPoints[i];
	}
}