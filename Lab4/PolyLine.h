#pragma once

#include "Point.h"

namespace lab4
{
	const unsigned int MAX_COUNT = 10;

	class PolyLine
	{
	public:
		PolyLine();
		PolyLine(const PolyLine& other);
		~PolyLine();

		bool AddPoint(float x, float y);
		bool AddPoint(const Point* point);
		bool RemovePoint(unsigned int i);
		bool TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const;

		const Point* operator[](unsigned int i) const;
		void operator=(const PolyLine& other);
		
	private:
		unsigned int mCount;

		const Point* mPoints[MAX_COUNT];
	};
}
