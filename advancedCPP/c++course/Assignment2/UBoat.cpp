#include <math.h>
#include <algorithm>
#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		:	Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		unsigned int weights = GetTotalWeight();
		return unsigned int(round(max(550 - (weights / 10.0), 200.0)));
	}
	unsigned int UBoat::GetDiveSpeed() const
	{
		unsigned int weights = GetTotalWeight();
		return int(round(500 * log((weights + 150.0) / 150.0) + 30));
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		return max(GetSailSpeed(), GetDiveSpeed());
	}

	void UBoat::Move()
	{
		if (mNumOfMove % 6 == 1 || mNumOfMove % 6 == 2)
		{
			mDistance += GetMaxSpeed();
		}
		mNumOfMove++;	
	}
}