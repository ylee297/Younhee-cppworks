#pragma once
#include "Vehicle.h"
#include "ISailable.h"
#include "IDivable.h"

namespace assignment2
{
	class UBoat : public Vehicle, public IDivable, public ISailable
	{
	public:
		UBoat();
		~UBoat();
		unsigned int GetMaxSpeed() const;
		unsigned int GetDiveSpeed() const;
		unsigned int GetSailSpeed() const;

		void Move();

	};
}