#include "Point.h"

namespace lab4
{
	Point::Point()
		: mX(0)
		, mY(0)
	{
	}

	Point::Point(float x, float y)
		: mX(x)
		, mY(y)
	{
	}

	Point::Point(const Point& other)
		: mX(other.mX)
		, mY(other.mY)
	{
	}

	Point Point::operator+(const Point& other) const
	{
		return Point(mX + other.mX, mY + other.mY);
	}

	Point Point::operator-(const Point& other) const
	{
		return Point(mX - other.mX, mY - other.mY);
	}

	Point Point::operator*(float operand) const
	{
		return Point(mX * operand, mY * operand);
	}

	Point operator*(const float scala, const Point& rhs)
	{
		return rhs * scala;
	}

	void Point::operator=(const Point& other)
	{
		mX = other.mX;
		mY = other.mY;
	}

	float Point::Dot(const Point& other) const
	{
		return mX * other.mX + mY * other.mY;
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}
}