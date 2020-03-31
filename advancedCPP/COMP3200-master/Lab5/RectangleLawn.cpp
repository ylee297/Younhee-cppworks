#include <math.h>
#include "RectangleLawn.h"
#include "eFenceType.h"
#include "eGrassType.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
	{
		mArea = width * height;
		mNumOfSodRoll = int(ceil(mArea / 0.3));
		mNumOfFence = int(ceil((2.0 * width + 2.0 * height) / 0.25));
		mRound = 2 * width + 2 * height;
	}

	unsigned int RectangleLawn::GetArea() const
	{
		return mArea;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		return mNumOfFence;
	}
	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
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