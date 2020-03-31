#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		:   mMaxPassengersCount(maxPassengersCount),
			mNumOfPassengers(0),
			mNumOfMove(1),
			mDistance(0)
	{
		mPeople = new const Person*[mMaxPassengersCount];
	}
	Vehicle::Vehicle(Vehicle& rhs)
		:	mMaxPassengersCount(rhs.GetMaxPassengersCount()),
			mNumOfPassengers(rhs.GetPassengersCount()),
			mNumOfMove(1),
			mDistance(0)
	{
		mPeople = new const Person * [mMaxPassengersCount];

		for (unsigned int i = 0; i < mNumOfPassengers; i++)
		{
			mPeople[i] = new Person(rhs.GetPassenger(i)->GetName2(), rhs.GetPassenger(i)->GetWeight());
		}
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < mNumOfPassengers; i++)
		{
			delete mPeople[i];
		}
		delete []mPeople;
	}


	bool Vehicle::AddPassenger(const Person* person)
	{
		for (unsigned int i = 0; i < mNumOfPassengers; i++)
		{
			if (person == mPeople[i])
			{
				return false;
			}
		}

		if (person == nullptr || mNumOfPassengers == mMaxPassengersCount)
		{
			return false;
		}

		mPeople[mNumOfPassengers] = person;
		mNumOfPassengers++;

		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i + 1 > mNumOfPassengers || mNumOfPassengers <= 0)
		{
			return false;
		}

		delete mPeople[i];
		for (unsigned int k = i; k < mNumOfPassengers - 1; k++)
		{
			mPeople[k] = mPeople[k + 1];
		}

		mNumOfPassengers--;
		mPeople[mNumOfPassengers] = nullptr;

		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mNumOfPassengers;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		return mPeople[i];
	}

	void Vehicle::ClearPassengers()
	{
		for (unsigned int i = 0; i < mNumOfPassengers; i++)
		{
			mPeople[i] = nullptr;
		}
		mNumOfPassengers = 0;
	}

	unsigned int Vehicle::GetTotalWeight() const
	{
		unsigned int weights = 0;
		for (unsigned int i = 0; i < mNumOfPassengers; i++)
		{
			weights += mPeople[i]->GetWeight();
		}
		return weights;
	}	

	unsigned int Vehicle::GetDistance() const
	{
		return mDistance;
	}


	unsigned int Vehicle::GetMaxSpeed() const
	{
		return 0;
	}

	void Vehicle::Move()
	{
	}

	Vehicle& Vehicle::operator=(const Vehicle& rhs)
	{
		mMaxPassengersCount = rhs.GetMaxPassengersCount();
		mNumOfPassengers = rhs.GetPassengersCount();

		mPeople = new const Person * [mMaxPassengersCount];
		for (unsigned int i = 0; i < mNumOfPassengers; i++)
		{
			mPeople[i] = new Person(rhs.GetPassenger(i)->GetName2(), rhs.GetPassenger(i)->GetWeight());
		}

		return *this;
	}

}