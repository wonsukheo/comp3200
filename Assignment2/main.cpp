#include <cassert>
#include <iostream>

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
using namespace std;

int main()
{
	Person* p = new Person("Bob", 85);
	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 78);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);

	Airplane a(5);
	a.AddPassenger(p);
	a.AddPassenger(p2);
	a.AddPassenger(p3);

	Boat b(5);
	b.AddPassenger(p4);
	b.AddPassenger(p5);
	b.AddPassenger(p6);

	Boatplane bp = a + b; // Boat + Airplane인 것에 유의
	unsigned int result = bp.GetPassengersCount() ; // 6 반환
	assert(result == 6);

	result = bp.GetMaxPassengersCount(); // 10 반환
	assert(result == 10);

	result = a.GetPassengersCount(); // 0 반환
	assert(result == 0);

	result = b.GetPassengersCount(); // 0 반환
	assert(result == 0);

	return 0;
}