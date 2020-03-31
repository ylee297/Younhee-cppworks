#include <math.h>
#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		double pricePerMeter;
		switch (grassType)
		{
		case 0:
			pricePerMeter = 8;
			break;
		case 1:
			pricePerMeter = 5;
			break;
		case 2:
			pricePerMeter = 3;
			break;
		case 3:
			pricePerMeter = 2.5;
			break;
		case 4:
			pricePerMeter = 4.5;
			break;
		default:
			pricePerMeter = 0;
		}

		
		
		return int(ceil(pricePerMeter * mArea));
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		return mNumOfSodRoll;
	}
}