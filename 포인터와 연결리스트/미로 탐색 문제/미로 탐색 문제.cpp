#include "Maze.h"

int main()
{
	Maze maze;

	maze.load("maze.txt");
	maze.print();
	maze.searchExit();
	printf("\n");
	maze.print();
	printf("\n����Ƚ�� : %d��\n", maze.i);

	return 0;
}