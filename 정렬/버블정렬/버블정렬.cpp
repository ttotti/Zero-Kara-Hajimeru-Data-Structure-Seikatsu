#include <cstdio>
#include <cstdlib>

// 버블 정렬의 비교횟수와 이동횟수를 계산하여 보면, 버블 정렬의 비교횟수는 최상, 평균, 최악의 어떠한 경우에도 항상 일정하다
// 따라서 전체적인 시간 복잡도는 O(n^2) 이다
// 버블 정렬은 매우 단순하지만 효율적이지는 않다 그러나 조금 개선할 수는 있다
// 어떤 스캔에서 자료의 변화가 한 번도 없으면 더 이상 스캔하지 않아도 된다
// 예를 들어 완전히 정렬된 입력에 대해서는 한 번만의 스캔으로 정렬이 종료되도록 할 수 있다
// 이렇게 하면 버블 정렬은 입력 데이터가 어느 정도 정렬되어 있는 경우에 효과적으로 사용될 수 있다

// 두 정수를 교환하는 함수 : inline 함수, 매개변수로 레퍼런스형 사용
// 요소의 교환을 위해 다음과 같이 swap() 함수를 사용하였다
// 이 함수는 inline 함수로 선언하여 실행 효율은 높으면서 매개변수의 자료형을 정확히 검사하도록 하였다 또한 레퍼런스 형을 사용하였다
inline void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

void bubbleSort(int A[], int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
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

// 정렬 알고리즘 테스트를 위한 주 함수
int main()
{
	int list[16];
	int n = 16;

	initRandom(list, n);
	// 정렬 전 배열 내용을 출력
	PrintArray(list, n, "Original ");
	// 선택 정렬 알고리즘 실행
	bubbleSort(list, n);
	// 정렬 후 배열 내용을 출력
	PrintArray(list, n, "Selection");

	return 0;
}