#include <math.h>
#include "SquareLawn.h"
#include "RectangleLawn.h"
#include "eFenceType.h"
#include "eGrassType.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int width)
		:	RectangleLawn(width, width)
	{
		mArea = int(pow(width, 2));
		mNumOfSodRoll = int(ceil(mArea / 0.3));
		mNumOfFence = int(ceil((4.0 * width) / 0.25));
		mRound = 4 * width;
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		return mNumOfFence;
	}
	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		double pricePerMeter;

		switch (fenceType)
		{
		case 0:
			pricePerMeter = 6;
			break;
		case 1:
			pricePerMeter = 7;
			break;
		default:
			pricePerMeter = 0;
		}

		return int(pricePerMeter * mRound);
	}
}