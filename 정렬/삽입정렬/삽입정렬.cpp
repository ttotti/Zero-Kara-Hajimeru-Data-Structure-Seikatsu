#include <cstdio>
#include <cstdlib>
#include <memory.h>

// 삽입 정렬은 비교적 많은 레코드들의 이동을 포함한다
// 결과적으로 삽입 정렬은 레코드양이 많고 특히 레코드 크기가 클 경우에 적합하지 않음을 알 수 있다
// 반면에 알고리즘이 간단하므로 레코드의 수가 적을 경우 효과적일 수 있다
// 특히 삽입 정렬은 대부분의 레코드가 이미 정렬되어 있는 경우에는 효율적인 알고리즘이 될 수 있다

// 삽입정렬 알고리즘을 이용해 int 배열을 오름차순으로 정렬하는 함수
void insertionSort(int A[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = A[i];
		int j;

		for (j = i - 1; j >= 0 && A[j] > key; j--)
		{
			// 레코드의 오름쪽 이동
			A[j + 1] = A[j];
		}

		A[j + 1] = key;
	}
}

inline int ascend(int x, int y) { return y - x; }  // 오름차순 비교함수
inline int descend(int x, int y) { return x - y; } // 내림차순 비교함수

// 함수 포인터를 매개변수로 받는 삽입정렬 함수
void insertionSortFn(int A[], int n, int(*f)(int, int))
{
	for (int i = 0; i < n; i++)
	{
		int key = A[i];
		int j;

		// 현재 배열 요소와 비교할 대상은 이전의 배열 요소 이므로 -1 씩 한다
		// 또한 배열의 첫 번째 요소는 비교할 필요가 없으므로 j >= 0 을 하여 그냥 넘어간다
		// 그리고 오름차순 및 내림차순 을 비교하기 위해 함수 포인터를 호출한다 
		// 이 함수 포인터로 0보다 작은 수가 나오면 그 수를 왼쪽으로 보내고 다른 수들은 오른쪽으로 보낸다
		for (j = i - 1; j >= 0 && f(A[j], key) < 0; j--)
		{
			A[j + 1] = A[j];
		}

		A[j + 1] = key;
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
	insertionSortFn(list, n, ascend);
	// 정렬 후 배열 내용을 출력
	PrintArray(list, n, "Insert-As");

	// 내림차순 선택정렬 알고리즘
	insertionSortFn(list, n, descend);
	// 정렬 후 배열 내용을 출력
	PrintArray(list, n, "Insert-De");

	return 0;
}