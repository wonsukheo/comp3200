#pragma once

#include "Vehicle.h"
#include "IDrivable.h"
#include "Trailer.h"



namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
		const static unsigned int MAX_PASSENGER_COUNT = 4;

		const static int TRAVEL = 5;
		const static int RESTED = -1;
		const static int TRAILER_RESTED = -2;

	public:
		Sedan();
		~Sedan();

		Sedan(const Sedan& other);
		Sedan& operator=(const Sedan& other);

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;

		void Travel();

	private:
		const Trailer* mTrailer;
		int mRested;
	};
}