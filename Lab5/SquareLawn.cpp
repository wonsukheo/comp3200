#include "SquareLawn.h"
#include "MyMath.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int length)
		: mLength(length)
	{
	}

	unsigned int SquareLawn::GetArea() const
	{
		return mLength * mLength;
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		return MyMath::Ceil(mLength * 4 / mFenceWidth);
	}

	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		return MyMath::Ceil(fenceType / 100 * GetMinimumFencesCount() / 4);
	}
}