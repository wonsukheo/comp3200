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
		Point** p = mPoints;
		Point* const* pp = other.mPoints;

		while (p - mPoints < mCount)
		{
			*p = new Point((*pp)->mX, (*pp)->mY);

			++p;
			++pp;
		}
	}

	void PolyLine::operator=(const PolyLine& other)
	{
		if (this == &other)
		{
			return;
		}

		delete[] mPoints;

		Point** p = mPoints;
		Point* const* pp = other.mPoints;

		mCount = other.mCount;

		while (p - mPoints < mCount)
		{
			*p = new Point((*pp)->mX, (*pp)->mY);

			++p;
			++pp;
		}
	}

	PolyLine::~PolyLine()
	{
		Point** p = mPoints;

		while (p - mPoints < mCount)
		{
			delete *p++;
		}
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCount == MAX_COUNT)
		{
			return false;
		}

		mPoints[mCount++] = new Point(x, y);

		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mCount == MAX_COUNT)
		{
			return false;
		}

		mPoints[mCount++] = new Point(point->mX, point->mY);

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mCount)
		{
			return false;
		}

		delete mPoints[i];

		Point** p = mPoints + i;

		while (p - mPoints < mCount - 1)
		{
			*p = *(p + 1);
			++p;
		}

		*p = NULL;

		--mCount;

		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mCount < 1)
		{
			return false;
		}

		Point* const* p = mPoints;

		float minX = (*p)->mX;
		float minY = (*p)->mY;

		float maxX = minX;
		float maxY = minY;

		++p;

		while (p - mPoints < mCount)
		{
			if ((*p)->mX < minX)
			{
				minX = (*p)->mX;
			}

			if ((*p)->mY < minY)
			{
				minY = (*p)->mY;
			}

			if ((*p)->mX > maxX)
			{
				maxX = (*p)->mX;
			}

			if ((*p)->mY > maxY)
			{
				maxY = (*p)->mY;
			}

			++p;
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