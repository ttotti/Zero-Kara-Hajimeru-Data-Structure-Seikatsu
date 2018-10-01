#include <ctime>
#include <Windows.h>
#include "BankSimulator.h"

int main()
{
	//srand((unsigned int)time(NULL));
	srand(GetTickCount());

	BankSimulator sim;
	sim.readSimlationParameters();
	sim.run();
	sim.printStat();

	return 0;
}