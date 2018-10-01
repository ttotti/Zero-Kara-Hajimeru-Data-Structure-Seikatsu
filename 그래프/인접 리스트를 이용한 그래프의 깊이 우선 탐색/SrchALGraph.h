#pragma once

// 깊이 우선 탐색은 현재 정점에서 더 이상 방문하지 않은 인접 정점이 없으면 가장 마지막에 만났던 정점으로 되돌아간다
// 이 방법은 가장 최근에 만났던 갈림길로 되돌아가야 하므로 스택을 사용하여 구현할 수 있지만
// 스택없이 순환 알고리즘의 형태로 간단하게 나타낼 수 있다

// 깊이 우선 탐색은 그래프의 모든 간선을 조사하므로
// 정점의 수가 n이고 간선의 수가 e인 그래프를 깊이 우선 탐색을 하는 시간은
// 그래프가 인접 리스트로 표현되어 있다면 O(n + e) 이고
// 인접 행렬로 표시되어 있다면 O(n^2) 이다
// 이는 희소 그래프인 경우 깊이 우선 탐색은 인접 리스트의 사용이 인접 행렬의 사용보다 시간적으로 유리함을 뜻한다

// 이 방법은 인접 행렬을 사용할 때와 결과가 다르다
// 왜냐하면 노드 순서가 정점 인덱스의 역순으로 들어 있기 때문이다

// 탐색 기능이 추가된 인접 리스트 기반 그래프 클래스
#include "AdjListGraph.h"

class SrchALGraph :public AdjListGraph
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

	// u번째 정점의 인접 리스트의 헤더 포인터에서부터 NULL이 아닐 때까지 모든 인접 노드들에 대해 검사함
	bool isLinked(int u, int v)
	{
		for (Node* p = adj[u]; p != NULL; p = p->getLink())
		{
			// 그 노드의 정점 번호가 v이면 u번째 정점과 v번째 정점이 인접함, 따라서 true 반환
			if (p->getId() == v)
				return true;
		}

		// 인접 리스트에 정점번호 v가 없으면 u와 v는 인접하지 않음, 따라서 false 반환
		return false;
	}

	// 깊이 우선 탐색
	void DFS(int v)
	{
		// 현재 정점을 방문함
		visited[v] = true;

		// 정점의 이름 출력
		printf("%c ", getVertex(v));

		// v번째 정점의 인접 리스트의 헤더 포인터에서부터 NULL이 아닐 때까지 모든 인접 노드들에 대해 검사함
		for (Node* p = adj[v]; p != NULL; p = p->getLink())
		{
			// 만약 노드 p의 정점이 방문되지 않았으면
			if (visited[p->getId()] == false)
			{
				// 순환 호출로 이 노드를 다시 탐색함
				// 정점 w에서 DFS 새로 시작
				DFS(p->getId());
			}
		}
	}
};