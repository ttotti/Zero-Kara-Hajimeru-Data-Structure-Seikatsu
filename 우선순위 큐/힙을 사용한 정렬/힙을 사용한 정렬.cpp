#include "MaxHeap.h"
#include <cstdlib>

int main()
{
	MaxHeap heap;
	int data[10];

	for (int i = 0; i < 10; i++)
	{
		data[i] = rand() % 45;
	}

	printf("\n정렬전: ");

	for (int i = 0; i < 10; i++)
		printf("%3d", data[i]);

	heapSort(data, 10);

	printf("\n정렬후: ");

	for (int i = 0; i < 10; i++)
	{
		printf("%3d", data[i]);
	}

	printf("\n");

	return 0;
}