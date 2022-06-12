#include <cassert>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"

using namespace assignment2;

int main()
{
	signed int s = 10;
	unsigned int u = 50;
	unsigned int mPassengersWeight = 1000;
	
	unsigned int temp = static_cast<unsigned int>(800 - 1.7 * mPassengersWeight + 0.5);

	double temp2 = 800 - 1.7 * mPassengersWeight + 0.5;
}