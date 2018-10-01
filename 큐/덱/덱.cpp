#include "CircularDeque.h"

int main()
{
	CircularDeque deq;

	for (int i = 1; i < 10; i++)
	{
		if (i % 2)
			deq.addFront(i);
		else
			deq.addRear(i);
	}

	deq.display();

	deq.deleteFront();
	deq.deleteRear();
	deq.deleteFront();

	deq.display();

	CircularDeque deq1;

	deq1.addFront(1);
	deq1.addFront(2);
	deq1.display();
	deq1.deleteFront();
	deq1.deleteRear();
	//deq1.addRear(3);
	deq1.display();

	return 0;
}