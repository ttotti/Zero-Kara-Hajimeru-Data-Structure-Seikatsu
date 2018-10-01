#include "Students.h"
#include "Simulation.h"
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	Simulation sim;
	
	sim.inputParameter();
	sim.run();
	sim.printStat();

	return 0;
}