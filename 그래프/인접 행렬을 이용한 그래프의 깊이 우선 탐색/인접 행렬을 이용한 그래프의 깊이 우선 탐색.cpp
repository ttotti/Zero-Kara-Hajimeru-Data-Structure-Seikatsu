#include "SrchAMGraph.h"

int main()
{
	SrchAMGraph g;

	g.load("graph.txt");
	printf("±×·¡ÇÁ(graph.txt)\n");
	g.display();

	printf("DFS ==> ");
	g.resetVisited();
	g.DFS(0);
	printf("\n");

	return 0;
}