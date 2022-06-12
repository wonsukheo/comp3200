#pragma once

#include "Person.h"
#include "DeusExMachina.h"

namespace assignment2
{
	class Vehicle
	{
		friend class DeusExMachina;

	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(unsigned int maxPassengersCount, int status);
		Vehicle(const Vehicle& other);
		
		~Vehicle();
		
		Vehicle& operator=(const Vehicle& other);

		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);

		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		
		virtual void Travel() = 0;

	protected:
		unsigned int mMaxPassengersCount;
		unsigned int mPassengersCount;
		unsigned int mPassengersWeight;
		int mStatus;
		unsigned int mTravelDistance;

		const Person** mPassengers;
		
	private:
	};
}
