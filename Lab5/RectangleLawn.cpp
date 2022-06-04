#include "RectangleLawn.h"
#include "MyMath.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
		: mWidth(width)
		, mHeight(height)
	{
	}

	unsigned int RectangleLawn::GetArea() const
	{
		return mWidth * mHeight;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		return MyMath::Ceil((mWidth + mHeight) * 2 / mFenceWidth);
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		return MyMath::Ceil(fenceType / 100 * GetMinimumFencesCount() / 4);
	}
}