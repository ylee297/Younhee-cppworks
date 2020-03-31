#include <algorithm>
#include <math.h>
#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		:	Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		double weights = GetTotalWeight();
		unsigned int leftParam = int(round(pow((2.0 * weights) + 400.0 - double(weights / 15.0), 3.0)));
		return max(leftParam, unsigned int(0));
	}


	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	void Motorcycle::Move()
	{
		if (mNumOfMove % 6 != 0)
		{
			mDistance += GetMaxSpeed();
		}
		mNumOfMove++;
	}

}