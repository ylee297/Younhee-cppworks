#pragma once

#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(Vehicle& rhs);
		~Vehicle();

		virtual unsigned int GetMaxSpeed() const;
		virtual void Move();

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		void ClearPassengers();
		unsigned int GetTotalWeight() const;
		unsigned int GetDistance() const;

		virtual Vehicle& operator=(const Vehicle& rhs);

	protected:
		Person const** mPeople;
		unsigned int mMaxPassengersCount;
		unsigned int mNumOfPassengers;
		unsigned int mNumOfMove;
		unsigned int mDistance;
	};
}