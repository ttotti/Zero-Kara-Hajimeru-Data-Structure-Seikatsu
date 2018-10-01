#pragma once

// 너비 우선 탐색은 큐를 사용하여야 하므로 깊이 우선 탐색보다 코드가 약간 복잡하다
// 여기서는 원형 큐를 사용했으나 연결된 큐를 사용해도 좋다
// 인접 행렬을 이용한 방법과 경과가 다른 것은 역시 인접 리스트의 노드 순서가 정점 인덱스의 역순이기 때문이다

// 너비 우선 탐색은 그래프가 
// 인접 리스트로 표현되어 있으면 전체 수행 시간이 O(n + e) 이며,
// 인접 행렬로 표현되어 있는 경우는 O(n^2) 시간이 걸린다
// 너비 우선 탐색도 깊이 우선 탐색과 같이 희소 그래프를 사용할 경우 인접 리스트를 사용하는 것이 효율적이다

#include "AdjListGraph.h"
#include "CircularQueue.h"

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

	// 인접 리스트로 표현된 그래프에 대한 너비우선탐색 연산
	void BFS(int v)
	{
		// 현재 정점을 방문함
		visited[v] = true;
		// 정점의 이름 출력
		printf("%c ", getVertex(v));

		// 큐 객체 생성
		CircularQueue que;

		// 시작 정점을 큐에 저장
		que.enqueue(v);

		// 큐 안에 데이터가 없을 때까지
		while (!que.isEmpty())
		{
			// 큐에 정점 추출
			int v = que.dequeue();

			// 현재 정점의 모든 인접 정점들에 대해서
			for (Node* w = adj[v]; w != NULL; w = w->getLink())
			{
				// 인접 노드의 정점 ID
				int id = w->getId();
				// 미방문 정점 탐색
				if (!visited[id])
				{
					// 방문 표시
					visited[id] = true;

					printf("%c ", getVertex(id));
					// 방문한 정점을 큐에 저장
					que.enqueue(id);
				}
			}
		}
	}
};