#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mCount(0)
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mCount(other.mCount)
	{
		memcpy(mPoints, other.mPoints, sizeof(Point) * MAX_COUNT);
	}
	/*
	PolyLine::~PolyLine()
	{
	}
	*/
	void PolyLine::operator=(const PolyLine& other)
	{
		if (this == &other)
		{
			return;
		}

		mCount = other.mCount;
		
		memcpy(mPoints, other.mPoints, sizeof(Point) * MAX_COUNT);
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCount == MAX_COUNT)
		{
			return false;
		}

		mPoints[mCount].mX = x;
		mPoints[mCount].mY = y;

		++mCount;

		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mCount == MAX_COUNT)
		{
			return false;
		}

		mPoints[mCount].mX = point->mX;
		mPoints[mCount].mY = point->mY;

		++mCount;

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (mCount == 0 || i > mCount)
		{
			return false;
		}

		Point* p = mPoints + i;

		while (p - mPoints < static_cast<int>(mCount))
		{
			*p = *(p + 1);
			++p;
		}

		p->mX = 0;
		p->mY = 0;

		--mCount;

		return true;
	}
	
	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		float minX = mPoints[0].mX;
		float minY = mPoints[0].mY;

		float maxX = minX;
		float maxY = minY;

		if (mCount < 2)
		{
			return false;
		}

		for (int i = 1; i < static_cast<int>(mCount); ++i)
		{
			if (mPoints[i].mX < minX)
			{
				minX = mPoints[i].mX;
			}

			if (mPoints[i].mY < minY)
			{
				minY = mPoints[i].mY;
			}

			if (mPoints[i].mX > maxX)
			{
				maxX = mPoints[i].mX;
			}

			if (mPoints[i].mY > maxY)
			{
				maxY = mPoints[i].mY;
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

		return &mPoints[i];
	}
}