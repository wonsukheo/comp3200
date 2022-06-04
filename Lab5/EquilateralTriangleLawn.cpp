#include "EquilateralTriangleLawn.h"
#include "Math.h"
#include "MyMath.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int length)
		: mLength(length)
	{
	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return static_cast<unsigned int>(mLength * mLength / 4 * sqrt(3) + 0.5);
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return MyMath::Ceil(mLength * 3 / mFenceWidth);
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		return MyMath::Ceil(fenceType / 100 * GetMinimumFencesCount() / 4);
	}
}