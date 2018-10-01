#include <cstdio>
#include <cstdlib>
#include <memory.h>

static void initRandom(int list[], int n, int max);
static void PrintArray(int arr[], int n, const char* str);

// 셸 정렬 은 Donald L. Shell 이 제안한 방법으로 삽입 정렬이 어느 정도 정렬된 배열에 대해서는 대단히 빠른 것에 착안했다
// 물론 삽입 정렬보다 빠르다, 삽입 정렬의 최대 문제점은 요소들이 삽입될 대, 이웃한 위치로만 이동한다는 것이다
// 만약 삽입되어야 할 위치가 현재 위치에서 상당히 멀리 떨어진 곳이라면 많은 이동을 해야 만이 제자리로 갈 수 있다
// 셸 정렬에서는 요소들이 멀리 떨어진 위치로도 이동할 수 있다

// 삽입 정렬과는 달리 셸 정렬은 전체 리스트를 한꺼번에 정렬하지 않는다
// 리스트를 일정한 기준에 따라 분류해 연속적이지 않은 여러 개의 부분 리스트를 만들고,
// 각 부분 리스트를 삽입 정렬을 이용하여 정렬한다
// 모든 부분 리스트가 정렬되면 셸 정렬은 다시 전체 리스트를 더 적은 개수의 부분 리스트로 만들어 앞의 과정을 되풀이한다
// 이 과정은 부분 리스트의 개수가 1이 될 때까지 반복된다

// 각 부분 리스트는 전체 리스트에서 거리가 k만큼 떨어진 요소들로 이루어진다
// 이 k를 간격(gap) 이라고 한다,
// 셸 정렬에서는 큰 간격으로 시작해서 각 단계마다 간격 k를 줄이는데, 이에 따라 하나의 부분 리스트에 속하는 요소의 개수는 증가된다
// 마지막 단계는 간격이 1이 된다

// 간격은 처음에는 n/2 정도로 하고 각 패스마다 간격을 절반으로 줄이는 방식을 많이 사용한다
// 셸 정렬의 자세한 설명은 책 519p, 인터넷을 참고한다

// 삽입 정렬에 비하여 셸 정렬은 2가지의 장점이 있다
/*
	1. 연속적이지 않은 부분 파일에서 자료의 교환이 일어나면 더 큰 거리를 이동한다
	   반면 삽입 정렬에서는 한 번에 한 칸씩만 이동된다
	   따라서 교환되는 아이템들이 삽입 정렬보다는 최종 위치에 더 가까이 있을 가능성이 높아진다

	2. 부분 리스트가 하나가 되면 셸 정렬은 전체 리스트를 정렬해야 한다
	   그러나 삽입 정렬이 거의 정렬된 리스트에 대해 매우 효율적이므로 이 과정도 빠르게 수행된다
*/

// 실험적인 연구를 통하여 셸 정렬의 시간 복잡도는 최악의 경우에는 O(n^2) 이지만 평균적인 경우에는 O(n^1.5) 인 것으로 알려져 있다

// gap 만큼 떨어진 요소들을 삽입 정렬, 정렬의 범위는 first에서 last
static void sortGapInsertion(int A[], int first, int last, int gap)
{
	int i, j, key;

	for (int i = first + gap; i <= last; i = i + gap)
	{
		key = A[i];

		for (j = i - gap; j >= first && key < A[j]; j = j - gap)
		{
			A[j + gap] = A[j];
		}

		A[j + gap] = key;
	}
}

// 셸 정렬 알고리즘을 이용해 int 배열을 오름차순으로 정렬하는 함수
void shellSort(int A[], int n)
{
	// 변수 gap이 간격 k를 나타낸다
	// gap이 1이 될 때까지 1/2로 줄이면서 반복한다

	// 부분 리스트의 개수는 gap이 된다
	// 각 부분 리스트에 대하여 일정한 간격으로 떨어져 있는 요소들을 삽입 정렬하는 함수는 sortGapInsertion() 이다
	// 이 함수는 삽입 정렬 함수와 비교하여 보면 쉽게 이해할 수 있다

	// 만약 간격이 짝수이면 1을 더하는 것이 좋은 것으로 분석되었는데
	// 코드에서도 짝수인 경우 간격에 1을 더해주었다
	for (int gap = n / 2; gap > 0; gap = gap / 2)
	{
		// 처리과정을 보기 위한 코드
		PrintArray(A, n, "Shell....");

		// 간격이 짝수일 경우 간격에 1을 더해준다
		if ((gap % 2) == 0) 
			gap++;

		// 부분 리스트의 개수는 gap
		for (int i = 0; i < gap; i++)
		{
			sortGapInsertion(A, i, n - 1, gap);
		}
	}
}

// 랜덤 함수를 이용하여 int 배열을 0 ~ max-1 의 값으로 무작위로 채우는 함수
// static 으로 선언하여 캡슐화 하였다 (static 으로 선언된 함수는 선언한 파일안에서만 사용할 수 있다)
static void initRandom(int list[], int n, int max = 100)
{
	for (int i = 0; i < n; i++)
	{
		list[i] = rand() % max;
	}
}

// 배열을 화면에 보기 좋게 출력하는 함수, 디폴트 매개변수 사용
// static 으로 선언하여 캡슐화 하였다 (static 으로 선언된 함수는 선언한 파일안에서만 사용할 수 있다)
static void PrintArray(int arr[], int n, const char* str = "Array")
{
	printf("%s = ", str);

	for (int i = 0; i < n; i++)
		printf("%3d", arr[i]);

	printf("\n");
}

int main()
{
	int list[5] = { 8,2,1,7,5 };
	int n = 5;

	//initRandom(list, n);
	// 정렬 전 배열 내용을 출력
	PrintArray(list, n, "Original ");

	// 오름차순 선택정렬 알고리즘
	shellSort(list, n);
	// 정렬 후 배열 내용을 출력
	PrintArray(list, n, "Insert-As");

	return 0;
}