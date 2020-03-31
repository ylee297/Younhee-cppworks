#include <math.h>
#include "CircleLawn.h"
#include "eFenceType.h"
#include "eGrassType.h"

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int radius)
	{
		mArea = int(round(3.14 * pow(radius, 2)));
		mNumOfSodRoll = int(ceil(mArea / 0.3));
	}

	unsigned int CircleLawn::GetArea() const
	{
		return mArea;
	}
}