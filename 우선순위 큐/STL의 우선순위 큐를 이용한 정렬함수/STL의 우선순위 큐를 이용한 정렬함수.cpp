#include <queue>
#include <functional>
#include <time.h>

using namespace std;

// 표준 템플릿 라이브러리에서도 우선순위 큐를 제공한다
// 먼저 STL의 우선순위 큐를 사용하려면 <queue> 헤더파일을 포함한다

// STL의 우선순위 큐를 이용한 내림차순 정렬, 최대 힙 사용 (부모 노드의 키 값이 자식 노드의 키 값보다 크거나 같은 완전 이진트리)
void heapSortDec(int a[], int n)
{
	// 최대 힙: "less than operator"를 사용하는 priority_queue

	// 이 문장에서는 기본적으로 "less than operator"를 사용하는데
	// 가장 값이 큰 항목 부터 출력되는 최대 힙으로 동작한다
	priority_queue<int> maxHeap;

	// 차례로 큐에 데이터를 넣는다
	for (int i = 0; i < n; i++)
	{
		// 기존의 삽입함수 insert()는 STL의 우선순위 큐에서 push()를 사용해야 한다
		maxHeap.push(a[i]);
	}

	for (int i = 0; i < n; i++)
	{
		// 삭제함수도 STL의 큐에서와 마찬가지로 top()과 pop()으로 분리되어 있다
		// top()은 가장 우선순위가 높은(또는 낮은) 항목을 반환하고(삭제하지는 않음)
		a[i] = maxHeap.top();
		// pop()은 반환하지 않고 그 항목을 우선순위 큐에서 삭제한다
		maxHeap.pop();
	}
}

// STL의 우선순위 큐를 이용한 올림차순 정렬, 최소 힙 사용 (부모 노드의 키 값이 자식 노드의 키 값보다 작거나 같은 완전 이진트리)
void heapSortInc(int a[], int n)
{
	// 최소 힙: "greater than operator"를 사용하는 priority_queue

	// 최소 힙을 사용하려면 "greater than operator"를 사용해야 하고
	// 우선순위 큐 객체의 선언이 다음과 같이 조금 더 복잡해진다
	// 또한 최소 힙을 사용하려면 헤더파일 <functional>을 추가로 포함해야 한다
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i = 0; i < n; i++)
	{
		minHeap.push(a[i]);
	}

	for (int i = 0; i < n; i++)
	{
		a[i] = minHeap.top();
		minHeap.pop();
	}
}

int main()
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 5; i++)
	{
		int data[6];

		for (int i = 0; i < 6; i++)
		{
			data[i] = rand() % 45 + 1;
		}

		printf("정렬전: ");

		for (int i = 0; i < 6; i++)
			printf("%3d", data[i]);

		printf("\n\n내림차순 정렬, 최대힙 사용");

		heapSortDec(data, 6);

		printf("\n정렬후: ");

		for (int i = 0; i < 6; i++)
		{
			printf("%3d", data[i]);
		}

		printf("\n\n");

		printf("올림차순 정렬, 최소힙 사용");

		heapSortInc(data, 6);

		printf("\n정렬후: ");

		for (int i = 0; i < 6; i++)
		{
			printf("%3d", data[i]);
		}

		printf("\n---------------------------------");
		printf("\n\n");
	}


	return 0;
}