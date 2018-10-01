
// 인접 행렬을 이용한 그래프 클래스
#pragma once
#include <cstdio>

// 표현 가능한 최대 정점의 개수
#define MAX_VTXS 256

class AdjMatGraph
{
	// 그래프 클래스의 상속을 대비해 데이터 필드를 protected로 선언
	// 데이터 멤버들, 정점은 이름 정보를 가짐
protected:
	// 정점의 개수
	int size;
	// 정점의 이름
	char vertices[MAX_VTXS];
	// 인접 행렬
	int adj[MAX_VTXS][MAX_VTXS];

public:
	// 생성자, reset() 함수를 호출해 데이터 필드를 초기화 함
	AdjMatGraph() { reset(); }

	// 정점과 간선의 정보 접근(설정 또는 반환) 함수
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }

	// 정점의 개수가 0이면 공백, MAX_VTXS 이상이면 포화 상태
	bool isEmpty() { return size = 0; }
	bool isFull() { return size >= MAX_VTXS; }

	// 그래프 초기화 -> 공백 상태의 그래프
	// 클래스 초기화 함수, 정점의 개수와 인접 리스트를 초기화 함
	void reset()
	{
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++)
		{
			for (int j = 0; j < MAX_VTXS; j++)
			{
				setEdge(i, j, 0);
			}
		}
	}

	// 정점 삽입 연산
	void inserVertex(char name)
	{
		// 포화 상태가 아니면 새로운 정점을 그래프에 추가함, 정점의 이름을 매개변수로 전달받아 설정함
		if (!isFull())
			vertices[size++] = name;
		else
			printf("Error : 그래프 정점 개수 초과\n");
	}

	// 간선 삽입 연산 : 무방향 그래프의 경우임, (방향, 가중치 그래프에서는 수정)
	// 무방향 그래프의 간선 삽입 함수, 간선(u, v)와 함께 (v, u)도 삽입함, 인접 행렬의 해당 요소의 값이 1이 됨
	void insertEdge(int u, int v)
	{
		setEdge(u, v, 1);
		setEdge(v, u, 1); // 방향 그래프에서는 이 부분이 삭제됨(<u, v>만 존재)
	}

	// 그래프 정보를 출력함 (화면이나 파일에 출력)
	// 그래프 출력 함수, 그래프를 화면뿐 아니라 파일로도 출력할 수 있도록 매개변수로 FILE* 를 가짐
	// 디폴트 매개변수로 stdout을 제공하여 매개변수가 없이 호출된 경우 화면에 출력하도록 함
	void display(FILE* fp = stdout)
	{
		// 출력 순서는 먼저 정점의 개수를 출력하고
		fprintf(fp, "%d\n", size);

		// 각 정점의 이름과 다른 정점과의 연결 여부를 출력함, 간선이 있는 경우는 1을 없으면 0을 출력함
		for (int i = 0; i < size; i++)
		{
			fprintf(fp, "%c  ", getVertex(i));

			for (int j = 0; j < size; j++)
				fprintf(fp, " %3d", getEdge(i, j));

			fprintf(fp, "\n");
		}
	}

	// 파일 입력 함수
	// 파일 filename 을 읽어 그래프 객체를 초기화하는 함수
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
				inserVertex(str[0]);

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

	// 파일 저장 함수, 현재 그래프를 filename 파일에 저장함
	void store(const char* filename)
	{
		// 파일을 열어 포인터를 만듦 (저장 모드)
		FILE* fp = fopen(filename, "w");

		// 파일이 있으면
		if (fp != NULL)
		{
			// display() 함수 호출, 매개변수로 파일 포인터 fp를 전달함
			display(fp);
			// 처리가 끝났으면 파일을 닫음
			fclose(fp);
		}
	}
};