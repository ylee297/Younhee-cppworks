
#include <math.h>
#include <algorithm>
#include "Boat.h"
#include "Airplane.h"


using namespace std;
namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		:   Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		return Boatplane(mMaxPassengersCount + boat.GetMaxPassengersCount(), *this, boat);
	}


	unsigned int Airplane::GetFlySpeed() const
	{
		unsigned int weights = GetTotalWeight();
		return int(round(200 * pow(exp(1.0), (800.0 - weights) / 500.0)));
	}
	unsigned int Airplane::GetDriveSpeed() const
	{
		unsigned int weights = GetTotalWeight();
		return int(round(4 * pow(exp(1.0), (400.0 - weights) / 70.0)));
	}
	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int driveSpeed = GetDriveSpeed();
		return max(flySpeed, driveSpeed);
	}

	void Airplane::Move()
	{
		if (mNumOfMove % 4 == 1)
		{
			mDistance += GetMaxSpeed();
		}
		mNumOfMove++;
	}
}