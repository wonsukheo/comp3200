#include "SquareLawn.h"
#include "MyMath.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int length)
		: RectangleLawn(length, length)
	{
	}

	unsigned int SquareLawn::GetArea() const
	{
		return mWidth * mWidth;
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		return MyMath::Ceil(mWidth * 4 / mFenceWidth);
	}

	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		return MyMath::Ceil(fenceType / 100 * GetMinimumFencesCount() / 4);
	}
}