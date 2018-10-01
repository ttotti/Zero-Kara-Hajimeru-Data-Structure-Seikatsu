#include "AdjMatGraph.h"

int main()
{
	// 새로운 그래프 객체 생성
	AdjMatGraph g;

	// 정점 삽입 : 'A' 'B', ...
	for (int i = 0; i < 8; i++)
	{
		g.inserVertex('A' + i);
	}

	//// 간선 삽입
	//// A - B
	//g.insertEdge(0, 1);
	//// A - D
	//g.insertEdge(0, 3);
	//// B - C
	//g.insertEdge(1, 2);
	//// B - D
	//g.insertEdge(1, 3);
	//// C - D
	//g.insertEdge(2, 3);

	g.insertEdge(0, 1);
	g.insertEdge(0, 2);

	g.insertEdge(1, 0);
	g.insertEdge(1, 3);

	g.insertEdge(2, 0);
	g.insertEdge(2, 3);
	g.insertEdge(2, 4);

	g.insertEdge(3, 1);
	g.insertEdge(3, 2);
	g.insertEdge(3, 5);

	g.insertEdge(4, 2);
	g.insertEdge(4, 6);
	g.insertEdge(4, 7);

	g.insertEdge(5, 3);

	g.insertEdge(6, 4);
	g.insertEdge(6, 7);

	g.insertEdge(7, 4);
	g.insertEdge(7, 6);

	printf("인접 행렬로 표현한 그래프\n");
	// 그래프 출력 -> 화면(stdout)으로 출력
	g.display();

	// 그래프 g를 파일에 저장
	g.store("graph.txt");

	// 그래프 g를 초기화
	g.reset();

	// 파일에서 그래프 정보를 읽어 g설정
	g.load("graph.txt");
	printf("인접 행렬로 표현한 그래프 (파일 : graph.txt)\n");
	// 그래프 g를 화면에 출력
	g.display();

	return 0;
}