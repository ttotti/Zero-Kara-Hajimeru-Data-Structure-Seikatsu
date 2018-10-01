#include <cstdio>
#include <cstdlib>

static void initRandom(int list[], int n, int max);
static void PrintArray(int arr[], int n, const char* str);
static int partition(int list[], int left, int right);
void quickSort(int list[], int left, int right);
inline void swap(int& x, int& y);

// 퀵 정렬(Quick sort) 은 평균적으로 매우 빠른 수행 속도를 자랑하는 정렬 방법이다
// 퀵 정렬도 합병 정렬과 같이 분할-정복법 을 사용한다
// 그러나 합병 정렬과는 달리 리스트를 균등하지 않게 분할한다

// 먼저 리스트 안에 있는 한 요소를 피벗(pivot) 으로 선택한다
// 여기서는 리스트의 첫 번째 요소를 피벗으로 하자
// 피벗보다 작은 요소들은 모두 피벗의 왼쪽으로 옮기고, 피벗보다 큰 요소들은 모두 피벗의 오른쪽으로 옮긴다
// 결과적으로 피벗을 중심으로 왼쪽은 피벗보다 작은 요소들로 구성되고, 오른쪽은 피벗보다 큰 요소들로 구성된다
// 이 상태에서 피벗을 제외한 왼쪽 리스트와 오른쪽 리스트를 다시 정렬하게 되면 전체 리스트가 정렬된다

// 이제 피벗을 기준으로 나누어진 왼쪽 부분 리스트와 오른쪽 부분 리스트를 정렬하는데 여기에서도 순환 호출이 사용된다
// 부분 리스트에서도 다시 피벗을 정하고 피벗을 기준으로 2개의 부분 리스트로 나누는 과정이 되풀이된다
// 이 과정은 부분 리스트를 더 이상이 분할할 수 없을 때까지 반복된다

// 퀵 정렬에서 가장 준요한 함수가 partition() 이다
// 이 함수는 데이터가 들어 있는 배열 list 의 left 부터 right 까지를, 피벗을 기준으로 2개의 부분 리스트로 나눈다
// 피벗보다 작은 데이터는 모두 왼쪽 부분 리스트로, 큰 데이터는 모두 오른쪽 부분 리스트로 옮겨진다

// 다음 설명은 책 530p ~ 532p 를 보면 이해가 잘된다
/*
	만약 5, 3, 8, 4, 9, 1, 6, 2, 7 리스트가 있다고 하면 이를 두 개의 부분 리스트로 나눈다
	먼저 간단하게 피벗을 입력 데이터의 첫 번째 데이터로 한다, 따라서 피벗은 5 가 된다
	인덱스 변수 low 는 왼쪽 부분 리스트를 만드는데 사용하고, high 는 오른쪽 부분 리스트를 만드는데 사용한다
	low는 왼쪽에서 오른쪽으로 탐색하다가 피벗보다 큰 데이터(8) 찾으면 멈춘다
	high는 오른쪽 끝에서부터 왼쪽으로 탐색해가다가 피벗보다 작은 데이터(2) 를 찾으면 멈춘다
	탐색이 멈추어진 위치는 각 부분 리스트에 적합하지 않은 데이터이다
	따라서 low와 high가 가리키는 데이터를 서로 교환한다
	이러한 탐색-교환 과정은 low와 high가 엇갈려서 지나가게 되면서 멈추게 된다
	이 때 high가 가리키는 데이터(1)와 피벗(5)을 교환하게 되면,
	피벗을 중심으로 왼쪽 리스트에는 피벗보다 작은 데이터만 존재하게 되고 오른쪽 리스트에는 피벗보다 큰 데이터만 남는다
	결국 피벗을 중심으로 2개의 리스트로 나누어지게 된다

	마지막 상태에서는 피벗(5)는 high와 교환되어 제 위치에 있는다
	따라서 피벗을 제외한 왼쪽과 오른쪽 리스트 (1, 3, 2, 4) 와 (9, 6, 8, 7) 를 독립적으로 다시 퀵 정렬하면 전체 리스트가 정렬된다
*/

// 퀵 정렬의 복잡도 분석
// n이 2의 거듭제곱이라고 가정하고 만약에 퀵 정렬에서의 리스트 분할이 항상 리스트의 가운데에서 이루어진다고 가정하면
// 합병 정렬의 복잡도 분석과 마찬가지롤 n개의 레코드를 가지는 리스트는 n/2, n/4, n/8 ... n/2^k 의 크기로 나누어질 것이다
// 크기가 1이 될 때까지 나누어지므로 n/2^k = 1 일 때까지 나누어질 것이고 따라서 k=log2 n 개의 패스가 필요하게 된다
// 각각의 패스에서는 전체 리스트의 대부분의 레코드를 비교해야 하므로 평균 n번 정도의 비교가 이루어지므로 퀵 정렬은 비교 연산을 총 n log2 n 번 실행하여
// O(n log2 n) 알고리즘이 된다, 레코드의 이동횟수는 비교횟수보다 적으므로 무시할 수 있다

// 그렇다면 퀵 정렬에서의 최악의 경우는 리스트가 계속 불균형하게 나누어지는 것이다
// 이미 정렬된 리스트에 대하여 퀵 정렬을 실행하는 경우
// 리스트의 첫 번째 레코드를 피벗으로 설정하면 왼편 리스트가 텅 비게 되는 불균형 분할이 연속해서 이루어진다
// 이 경우 레코드의 수만큼 총 n변의 패스가 실행되고, 각 패스에서 n번의 비교가 이루어지게 되므로
// 비교 연산을 n^2 번 실행하게 된다, 따라서 최악의 경우 퀵 정렬은 O(n^2) 의 시간 복잡도를 가지게 된다

// 퀵 정렬의 평균적인 경우의 시간 복잡도가 O(n log2 n)으로 나타난다
// 특히 다른 O(n log2 n)의 정렬 알고리즘과 비교하였을 때도 가장 빠른 것으로 나타났다
// 이는 퀵 정렬이 불필요한 데이터의 이동을 줄이고 먼 거리의 데이터를 교환할 뿐 아니라,
// 한번 결정된 피벗들이 추후 연산에서 제외되는 특성 등에서 기인한다고 보인다

// 퀵 정렬은 속도가 빠르고 추가 메모리 공간을 필요로 하지 않는 등의 장점이 있는 반면에
// 정렬된 리스트에 대해서는 오히려 수행 시간이 더 많이 걸리는 등의 단점도 가진다
// 이러한 불균형 분할을 방지하기 위하여 피벗을 선택할 때
// 단순히 리스트의 왼쪽 데이터를 사용하는 대신에 보다 리스트의 중앙 부분을 분할할 수 있는 데이터를 선택한다
// 많이 사용되는 방법은 리스트 내의 몇 개의 데이터 중에서 중간값(median)을 피벗으로 선택하는 것이다
// 일반적으로 리스트의 왼쪽, 오른쪽, 중간의 3개의 데이터 중에서 중간 값을 선택하는 방법이 많이 사용된다

static int partition(int list[], int left, int right)
{
	int low = left;			// low 는 left 에서 출발, do-while 루프에서 먼저 증가를 시킴을 주의
	int high = right + 1;   // high는 right + 1 에서 출발, do-while 루프에서 먼저 감소를 시킴을 주의
	int pivot = list[left]; // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택한다

	// 피벗 설정
	// low 와 high 가 교차할 때까지 계속 반복한다
	do
	{
		// 왼쪽 리스트에서 피벗보다 큰 레코드 선택
		// list[low] 가 pivot 보다 작으면 계속 low를 증가시킨다
		do
		{
			low++;
		} while (low <= right && list[low] < pivot);

		// 오른쪽 리스트에서 피벗보다 작은 레코드 선택
		// list[high] 가 pivot 보다 크면 계속 high를 감소시킨다
		do
		{
			high--;
		} while (high >= left && list[high] > pivot);

		// 선택된 두 레코드 교환
		// low와 high가 아직 교차하지 않았으면 list[low]와 list[high]를 교환한다
		if (low < high)
			swap(list[low], list[high]);

		// 인텍스 i, j 가 엇갈리지 않은 한 반복
		// 만약 low와 high가 교차하였으면 반복을 종료한다
	} while (low < high);

	// 인덱스 j가 가리키는 레코드와 피벗 교환
	// 피벗을 중앙에 위치시킨다
	swap(list[left], list[high]);

	// 피벗의 위치를 반환한다
	return high;
}

// 퀵 정렬 알고리즘을 이용해 배열의 left ~ right 항목들을 오름차순으로 정렬하는 함수
// 정렬 대상 배열 list 와 함께 정렬 범위를 나타내는 left와 right를 매개변수로 전달하는 것에 주목해야한다
void quickSort(int list[], int left, int right)
{
	// 정렬 범위가 2개 이상인 경우
	if (left < right)
	{
		// 좌우로 분할
		int q = partition(list, left, right);
		// 왼쪽 부분리스트를 퀵 정렬
		quickSort(list, left, q - 1);
		// 오른쪽 부분리스트를 퀵 정렬
		quickSort(list, q + 1, right);
	}
}

inline void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
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
	int list[9] = { 5,3,8,4,9,1,6,2,7 };
	int n = 9;

	//initRandom(list, n);
	PrintArray(list, n, "Original  ");
	quickSort(list, 0, n - 1);
	PrintArray(list, n, "QuickSort ");
}