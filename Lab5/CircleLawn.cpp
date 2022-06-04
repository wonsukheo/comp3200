#include "CircleLawn.h"

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int radius)
		: mRadius(radius)
	{
	}

	unsigned int CircleLawn::GetArea() const
	{
		return static_cast<unsigned int>(mRadius * mRadius * 3.14 + 0.5);
	}
}