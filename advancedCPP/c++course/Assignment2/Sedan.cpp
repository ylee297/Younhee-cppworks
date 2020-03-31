#include "Sedan.h"
#include "Trailer.h"

namespace assignment2
{
	Sedan::Sedan()
		:	Vehicle(4)
	{
		mbConnected = false;
		mTrailer = nullptr;
	}

	Sedan::~Sedan()
	{
		delete mTrailer;
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (trailer == nullptr || mbConnected)
		{
			return false;
		}

		mTrailer = trailer;
		mbConnected = true;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer == nullptr)
		{
			return false;
		}
		mTrailer = nullptr;
		mbConnected = false;
		return true;
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int weights = GetTotalWeight();
		if (mbConnected)
		{
			weights += mTrailer->GetWeight();
		}
		unsigned int speed = 0;
		if (weights <= 80)
		{
			speed = 480;
		}
		else if (weights > 80 && weights <= 160)
		{
			speed = 458;
		}
		else if (weights > 160 && weights <= 260)
		{
			speed = 400;
		}
		else if (weights > 260 && weights <= 350)
		{
			speed = 380;
		}
		else if (weights > 350)
		{
			speed = 300;
		}
		return speed;
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	void Sedan::Move()
	{
		if (mTrailer == nullptr)
		{
			if (mNumOfMove % 6 != 0)
			{
				mDistance += GetMaxSpeed();
			}
			mNumOfMove++;
		}
		else
		{
			if (!(mNumOfMove % 7 == 0 || mNumOfMove % 7 == 6))
			{
				mDistance += GetMaxSpeed();
			}
			mNumOfMove++;
		}

	}

	Trailer* Sedan::GetTrailer() const
	{
		return mTrailer;
	}

	Sedan& Sedan::operator=(const Sedan& rhs)
	{
		mMaxPassengersCount = rhs.GetMaxPassengersCount();
		mNumOfPassengers = rhs.GetPassengersCount();

		mPeople = new const Person * [mMaxPassengersCount];
		for (unsigned int i = 0; i < mNumOfPassengers; i++)
		{
			mPeople[i] = new Person(rhs.GetPassenger(i)->GetName2(), rhs.GetPassenger(i)->GetWeight());
		}

		if (rhs.mbConnected)
		{
			mTrailer = rhs.GetTrailer();
		}

		return *this;
	}

}