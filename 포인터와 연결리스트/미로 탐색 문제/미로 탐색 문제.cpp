#include "Maze.h"

int main()
{
	Maze maze;

	maze.load("maze.txt");
	maze.print();
	maze.searchExit();
	printf("\n");
	maze.print();
	printf("\n연산횟수 : %d번\n", maze.i);

	return 0;
}