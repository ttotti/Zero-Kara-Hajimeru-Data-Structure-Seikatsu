#include "SrchALGraph.h"

int main()
{
	SrchALGraph g;

	g.load("graph.txt");
	printf("�׷���(graph.txt)\n");
	g.display();

	printf("DFS ==> ");
	g.resetVisited();
	g.BFS(0);
	printf("\n");

	return 0;
}