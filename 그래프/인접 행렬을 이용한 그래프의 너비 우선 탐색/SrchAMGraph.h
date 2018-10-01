#pragma once

// 너비 우선 탐색(BFS)은 시작 정점으로 부터 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 순회 방법이다
// 너비 우선 탐색을 위해서는 가까운 거리에 있는 정점들을 차례로 저장하고, 들어간 순서대로 꺼낼 수 있는 자료구조가 필요하다
// 이를 위해 큐(queue)가 사용된다

// 즉 정점들이 방문될 때마다 큐에 인접 정점을 삽입하고, 
// 더 이상 방문할 인접 정점이 없는 경우 큐의 맨 앞에서 정점을 꺼내 그 정점과 인접한 정점들을 차례대로 방문한다
// 초기 상태의 큐에는 시작 정점만이 저장되고, 너비 우선 탐색 과정은 큐가 공백 상태가 될 때까지 계속한다
// (책 447p 그림 참고)

// 처음에는 큐에 A만 들어있다
// 큐에서 A를 꺼내 인접 정점을 순서대로 방문한다
// 이제 큐에는 B, C 가 순서대로 들어있다
// 다시 큐에서 B를 꺼내고 B에서 갈 수 있는 인접 정점을 방문하고 큐에 삽입한다
// 이제 큐에는 C, D 가 들어있다
// 이 과정을 큐가 공백 상태가 될 때까지 진행한다


#include "AdjMatGraph.h"
#include "CircularQueue.h"

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

	// 인접 행렬로 표현된 그래프에 대한 너비우선탐색 연산
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

		// 큐가 공백 상태가 아닐 때 까지 진행
		while (!que.isEmpty())
		{
			// 큐에 정점 추출
			int v = que.dequeue();

			// 인접 정점 탐색
			for (int w = 0; w < size; w++)
			{
				// 그 정점이 현재 정점과 연결되어 있고, 방문되지 않았으면
				if (isLinked(v, w) && visited[w] == false)
				{
					// 방문 표시
					visited[w] = true;

					// 정점의 이름 출력
					printf("%c ", getVertex(w));

					// 방문한 정점을 큐에 저장
					que.enqueue(w);
				}
			}
		}
	}
};