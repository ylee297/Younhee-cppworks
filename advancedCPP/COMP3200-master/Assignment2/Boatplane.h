#pragma once
#include "Vehicle.h"
#include "ISailable.h"
#include "IFlyable.h"


namespace assignment2
{
	class Airplane;
	class Boat;

	class Boatplane : public Vehicle, public ISailable, public IFlyable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		Boatplane(unsigned int maxPassengersCount, Airplane& airplane, Boat& boat) ;
		~Boatplane();

		unsigned int GetFlySpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetMaxSpeed() const;

		void Move();
	};
}