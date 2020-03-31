#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		~DeusExMachina();

		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
		Vehicle* GetVehicle(unsigned int i) const;
		Vehicle** GetVehicles() const;
	private:
		DeusExMachina();
		unsigned int mSize = 0;
		Vehicle** mVehicles = new  Vehicle*[10];
	};
}