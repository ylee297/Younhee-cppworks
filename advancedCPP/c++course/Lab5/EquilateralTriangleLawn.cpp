#include <math.h>
#include "EquilateralTriangleLawn.h"
#include "eFenceType.h"
#include "eGrassType.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int sideLength)
	{
		mArea = int((sqrt(3) / 4) * pow(sideLength, 2));
		mNumOfSodRoll = int(ceil(mArea / 0.3));
		mNumOfFence = int(ceil((3.0 * sideLength) / 0.25));
		mRound = 3 * sideLength;
	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return mArea;
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return mNumOfFence;
	}
	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
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