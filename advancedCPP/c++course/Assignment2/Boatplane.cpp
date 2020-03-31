
#include <algorithm>
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		:	Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}

	Boatplane::Boatplane(unsigned int maxPassengersCount, Airplane& airplane, Boat& boat)
		:	Vehicle(maxPassengersCount)
	{
		for (unsigned int i = 0; i < airplane.GetPassengersCount(); i++)
		{
			AddPassenger(airplane.GetPassenger(i));
		}
		airplane.ClearPassengers();

		for (unsigned int i = 0; i < boat.GetPassengersCount(); i++)
		{
			AddPassenger(boat.GetPassenger(i));
		}
		boat.ClearPassengers();
	}



	unsigned int Boatplane::GetFlySpeed() const
	{
		unsigned int weights = 0;
		for (unsigned int i = 0; i < mNumOfPassengers; i++)
		{
			weights += mPeople[i]->GetWeight();
		}
		return int(round(150 * pow(exp(1.0), (500.0 - weights) / 300.0)));
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		unsigned int weights = GetTotalWeight();
		return max(unsigned int(round(800.0 - 1.7 * double(weights))), unsigned(20));
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		return max(GetFlySpeed(), GetSailSpeed());
	}


	void Boatplane::Move()
	{
		if (mNumOfMove % 4 == 1)
		{
			mDistance += GetMaxSpeed();
		}
		mNumOfMove++;
	}
}