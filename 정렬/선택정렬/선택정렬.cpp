#include <cstdio>
#include <cstdlib>
#include <ctime>

// 정렬이 안 된 리스트에서 최솟값이 선택되면 이 값을 배열의 첫 번째 요소와 교환한다
// 이렇게 입력 배열 이외에 다른 추가 메모리를 요구하지 않는 정렬 방법을 제자리 정렬(in - place sorting) 라고 한다
// 이 절차를 (숫자 개수 - 1)만큼 되풀이 하면 추가적인 배열을 사용하지 않고서도 전체 숫자들이 정렬된다

// 선택 정렬은 전체 시간 복잡도가 O(n^2) 이므로 효율적인 알고리즘은 아니다
// 또 안정성을 만족하지는 않는다, 즉 값이 같은 레코드가 있는 경우에 상대적인 위치가 변경될 수 있다
// 그러나 알고리즘이 매우 간단하다는 장점이 있다

// 두 정수를 교환하는 함수 : inline 함수, 매개변수로 레퍼런스형 사용
// 요소의 교환을 위해 다음과 같이 swap() 함수를 사용하였다
// 이 함수는 inline 함수로 선언하여 실행 효율은 높으면서 매개변수의 자료형을 정확히 검사하도록 하였다 또한 레퍼런스 형을 사용하였다
inline void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

// 선택정렬 알고리즘을 이용해 int 배열을 오름차순으로 정렬하는 함수
void selectionSort(int A[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int least = i;

		// n - 1 번만 반복
		for (int j = i + 1; j < n; j++)
		{
			// 최솟값 탐색 // 여기서 배열 안에서 가장 작은 수를 찾는다
			if (A[j] < A[least])
				least = j;
		}

		// 교환
		swap(A[i], A[least]);
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
	selectionSort(list, n);
	// 정렬 후 배열 내용을 출력
	PrintArray(list, n, "Selection");

	return 0;
}