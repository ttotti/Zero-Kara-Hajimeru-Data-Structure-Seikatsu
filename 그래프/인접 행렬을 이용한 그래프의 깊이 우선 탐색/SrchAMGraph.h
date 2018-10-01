#pragma once

// 깊이 우선 탐색은 현재 정점에서 더 이상 방문하지 않은 인접 정점이 없으면 가장 마지막에 만났던 정점으로 되돌아간다
// 이 방법은 가장 최근에 만났던 갈림길로 되돌아가야 하므로 스택을 사용하여 구현할 수 있지만
// 스택없이 순환 알고리즘의 형태로 간단하게 나타낼 수 있다

#include "AdjMatGraph.h"

class SrchAMGraph :public AdjMatGraph
{
private:
	// 정점의 방문 정보
	bool visited[MAX_VTXS];

public:
	// 모든 정점을 방문하지 않았다고 설정
	void resetVisited()
	{
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}
	}

	// u 번째 정점과 v 번째 정점이 연결되어 있는지를 검사함
	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	// 깊이 우선 탐색 함수
	void DFS(int v)
	{
		// 현재 정점을 방문함
		// 먼저 현재 정점 v를 방문했다고 표시함
		visited[v] = true;
		// 정점의 이름 출력
		printf("%c ", getVertex(v));

		// 모든 정점들에 대해
		for (int w = 0; w < size; w++)
		{
			// 현재 정점과 연결되어 있고 아직 가지 않은 정점이면
			if (isLinked(v, w) && visited[w] == false)
				// 연결 + 방문X => 순환호출로 방문
				// 순환 호출로 다시 탐색함
				DFS(w);
		}
	}
};