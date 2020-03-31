#include "DeusExMachina.h"
#include "Vehicle.h"

using namespace std;

namespace assignment2
{
	DeusExMachina* DeusExMachina::GetInstance()
	{
		static DeusExMachina* mMachina = new DeusExMachina();
		return mMachina;
	}

	DeusExMachina::DeusExMachina()
	{
	}

	DeusExMachina::~DeusExMachina()
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			delete mVehicles[i];
		}
		delete []mVehicles;
	}

	void DeusExMachina::Travel() const
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			mVehicles[i]->Move();
		}

	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (vehicle == nullptr || mSize == 10)
		{
			return false;
		}

		mVehicles[mSize] = vehicle;
		mSize++;

		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i + 1 > mSize || mSize == 0)
		{
			return false;
		}

		delete mVehicles[i];
		for (unsigned int k = i; k < mSize - 1; k++)
		{
			mVehicles[k] = mVehicles[k + 1];
		}

		mSize--;
		mVehicles[mSize] = nullptr;

		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mSize == 0)
		{
			return NULL;
		}

		Vehicle* maxVehicle = mVehicles[0];
		for (unsigned int i = 1; i < mSize - 1; i++)
		{
			if (maxVehicle->GetDistance() < mVehicles[i]->GetDistance())
			{
				maxVehicle = mVehicles[i];
			}
		}

		maxVehicle->GetMaxSpeed();
		return maxVehicle;
	}

	Vehicle** DeusExMachina::GetVehicles() const
	{
		return mVehicles;
	}

	Vehicle* DeusExMachina::GetVehicle(unsigned int i) const
	{
		return mVehicles[i];
	}

}