#pragma once

// 인접 리스트를 이용한 그래프 클래스

// 연결 리스트를 위한 노드 그래프 클래스 포함
#include "Node.h"

#define MAX_VTXS 256

class AdjListGraph
{
protected:
	// 정점의 개수
	int size;
	// 정점 정보 (응용에 따라 확장 필요)
	char vertices[MAX_VTXS];
	// 각 정점의 인접 리스트
	// 각 노드에 대한 인접 리스트 헤더 포인터 배열
	Node* adj[MAX_VTXS];

public:
	// 생성자, 정점의 개수만 0으로 초기화
	AdjListGraph()
		:size(0) {}
	// 소멸자. reset() 함수 호출
	~AdjListGraph() { reset(); }

	void reset()
	{
		// 각 노드에 대한 인접 리스트가 NULL이 아니면 인접 리스트를 동적으로 해제함
		// 노드 클래스의 소멸자에 의해 연결된 모든 노드들이 동적으로 해제됨
		for (int i = 0; i < size; i++)
		{
			if (adj[i] != NULL)
				delete adj[i];

		}

		// 최종적으로 size를 0으로 초기화
		size = 0;
	}

	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }
	char getVertex(int i) { return vertices[i]; }

	// 정점 삽입 연산
	void insertVertex(char val)
	{
		if (!isFull())
		{
			// 정점 삽입 함수에서 정점의 이름을 설정하고
			vertices[size] = val;
			// 인접 리스트의 헤드 포인터를 NULL로 초기화 함
			// 그 다음에 size를 증가시켜야 함 (후위 연산)
			adj[size++] = NULL;
		}
		else
			printf("Error : 그래프 정점 개수 초과\n");
	}

	// 간선 삽입 연산
	void insertEdge(int u, int v)
	{
		// 인접 리스트에 추가
		// 새로운 노드를 생성함,
		// 노드의 인덱스는 v가 되고, link는 u번째 정점의 인접 리스트 헤더 포인터임
		// 최종적으로 만들어진 새로운 노드가 u번째 정점의 새로운 헤더 포인터가 됨, 즉 삽입은 리스트의 전단에서 처리됨
		// Node() 의 두 번째 인수에 삽입되는 데이터의 주소는 링크에 저장된다
		// (즉 새롭게 삽입된 노드는 항상 앞에 있고(헤더 포인터가 됨) 먼저 삽입된 노드는 계속 뒤로 밀려난다(자료구조 스택 과 비슷한 구조))
		adj[u] = new Node(v, adj[u]);

		// 방향 그래프가 아닌 무방향그래프 일경우 이미 연결된 정점을 또 연결할 필요가 없으므로
		// 이 부분을 if로 하여 반대로 연결하려는 정점이 NULL 일경우 아무것도 연결되있지 않은 상태를 의미하므로 연결해준다
		// 이해가 안된다면 if 부분을 지우고 실행해보자
		if (adjacent(v) == NULL)
		{
			// u와 v를 바꾸어 위와 동일한 과정을 처리
			// 만약 그래프가 방향 그래프이면 이 행을 주석처리 해야 함을 명심할 것
			adj[v] = new Node(u, adj[v]); // 방향 그래프는 이 부분을 주석 처리함
		}
	}

	// v번째 정점의 인접 정점 리스트를 반환하는 함수
	// 인접 리스트의 헤더 포인터 adj[v]를 반환하면 됨
	Node* adjacent(int v) { return adj[v]; }

	// 화면 출력 함수
	void display()
	{
		// 정점의 개수 출력
		// 정점의 개수를 먼저 출력
		printf("%d\n", size);

		// 각 행의 정보 출력
		for (int i = 0; i < size; i++)
		{
			// 정점의 이름 출력
			// 각 행의 출력에서 먼저 정점의 이름을 출력함
			printf("%c  ", getVertex(i));

			// 인접 리스트의 각 노드를 찾아가는 반복문
			for (Node* v = adj[i]; v != NULL; v = v->getLink())
			{
				// 인접한 정점의 이름을 출력함
				printf("  %c", getVertex(v->getId()));
				// 위의 노드대신 이 코드를 사용하면 인접한 정점의 인덱스를 출력함
				//printf("%3d", v->getId());
			}

			printf("\n");
		}
	}

	// 파일 입력 함수
	// 파일 filename 을 읽어 그래프 객체를 초기화하는 함수
	// 인접 행렬 예에서와 동일한 파일 형식을 읽어 들임에 유의할 것
	// 또한 이 함수를 사용하려면 71행을 주석으로 처리하여 방향 그래프로 처리해야 함, 저장하는 함수는 제공하지 않았음
	void load(const char* filename)
	{
		// 파일을 열어 포인터를 만듫 (읽기 모드)
		FILE* fp = fopen(filename, "r");

		// 파일이 있으면
		if (fp != NULL)
		{
			int n, val;
			// 정점의 개수를 먼저 읽어들임, 위의 graph.txt 형식을 참고할 것
			fscanf(fp, "%d", &n);

			// 정점의 이름을 읽어 정점을 삽입함
			// 파일에서 먼저 하나의 문자열을 읽고 문자열의 첫 번째 문자를 정점의 이름으로 설정한 것에 유의할 것
			// 문자열이 아니라 문자로 읽을 경우 '\n'에 의한 문제 상황이 발생할 수 있음
			for (int i = 0; i < n; i++)
			{
				char str[80];
				// 정점의 이름
				fscanf(fp, "%s", str);
				// 정점 삽입
				insertVertex(str[0]);

				// 하나의 정점에 대해 다른 정점과의 연결 관계를 읽어 들여 연결이 있으면 간선을 삽입함
				for (int j = 0; j < n; j++)
				{
					int val;
					// 간선 정보
					fscanf(fp, "%d", &val);
					// 간선이 있으면
					if (val != 0)
						// 간선 삽입
						insertEdge(i, j);
				}
			}

			// 처리가 끝났으면 파일을 닫음
			fclose(fp);
		}
	}
};