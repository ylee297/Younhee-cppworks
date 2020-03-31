#pragma once
#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable 
	{
	public:
		Sedan();
		~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();
		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;
		Trailer* GetTrailer() const;

		void Move();
		Sedan& operator=(const Sedan& rhs);
	private:
		Trailer* mTrailer;
		bool mbConnected;
	};
}