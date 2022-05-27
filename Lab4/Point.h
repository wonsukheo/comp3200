#pragma once

namespace lab4
{
	class Point
	{
		friend Point operator*(const float scala, const Point& rhs);
		friend class PolyLine;
	public:
		Point();
		Point(float x, float y);
		Point(const Point& other);
		//~Point();

		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		Point operator*(float operand) const;
		void operator=(const Point& other);

		float Dot(const Point& other) const;

		float GetX() const;
		float GetY() const;

	private:
		float mX;
		float mY;
	};
}
