
#include <math.h>
#include <algorithm>
#include "Airplane.h"
#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		:	Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		return Boatplane(mMaxPassengersCount + plane.GetMaxPassengersCount(), plane, *this);
	}

	unsigned int Boat::GetSailSpeed() const
	{
		unsigned int weights = GetTotalWeight();
		return max(800 - 10 * weights, (unsigned)20);
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	void Boat::Move()
	{
		if (mNumOfMove % 3 != 0)
		{
			mDistance += GetMaxSpeed();
		}
		mNumOfMove++;
	

	}
}