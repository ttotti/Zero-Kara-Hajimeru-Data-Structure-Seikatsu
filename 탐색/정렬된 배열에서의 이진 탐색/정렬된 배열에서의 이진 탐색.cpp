#include <cstdio>

// 정렬된 배열의 탐색에는 이진 탐색 이 적용될 수 있다
// 이 방법은 배열의 중앙에 있는 값을 조사하여 찾고자 하는 항목이 왼쪽 부분 배열에 있는지 오른쪽 부분 배열에 있는지 판단하고
// 다음 단계의 탐색 범위를 반으로 줄인다, 따라서 매 단계에서 검색해야 할 리스트의 크기가 반으로 줄어든다
// 이와 같은 이진 탐색을 적용하려면 탐색하기 전에 반드시 배열이 정렬되어 있어야 하다
// 따라서 이진 탐색은 데이터의 삽입이나 삭제가 빈번한 경우에는 적합하지 않다

// 이진 탐색은 탐색을 반복할 때마다 탐색 범위를 반으로 줄인다
// 이러한 탐색 범위가 더 이상 줄일 수 없는 1이 될 때의 탐색횟수를 k라 하면, n/2^k = 1 이므로 k = log2 n 임을 알 수 있다
// 결국 이진 탐색의 시간 복잡도는 O(log2 n) 이 된다

// 순환 호출(재귀 호출)을 이용한 이진 탐색
int j = 0;
int binarySearch(int list[], int key, int low, int high)
{
	if (j == 0)
		printf("이진 탐색(순환 호출) 탐색 시작\n");

	int middle;

	// 하나 이상의 항목이 있어야 탐색
	if (low <= high)
	{
		printf("탐색 중...\n");

		// 데이터의 범위를 반으로 나눈다
		// 중간 위치 결정
		middle = (low + high) / 2;

		// 키 값과 리스트의 값을 비교하여 같으면 탐색 성공
		if (key == list[middle])
		{
			printf("탐색 횟수 = %d\n", j);
			return middle;
		}
		// 왼쪽 부분리스트 탐색
		// 중간 위치의 키 값보다 key가 작으면 앞쪽 부분 리스트 탐색
		else if (key < list[middle])
		{
			j++;
			return binarySearch(list, key, low, middle - 1);
		}
		// 오른쪽 부분리스트 탐색
		// 아니면 뒤쪽 부분 리스트 탐색
		else
		{
			j++;
			return binarySearch(list, key, middle + 1, high);
		}

	}

	printf("탐색 횟수 = %d\n", j);
	// 탐색 실패
	return -1;
}

// 이진 탐색은 반복문을 사용하여 구현할 수도 있다
// 효율성을 위해서는 반복 구조를 사용하는 것이 더 좋다
int binarySearchIter(int list[], int key, int low, int high)
{
	printf("이진 탐색(반복문) 탐색 시작\n");

	int middle;
	int i = 0;

	// 항목들이 남아 있으면(종료 조건)
	while (low <= high)
	{
		printf("탐색 중...\n");

		// 데이터의 범위를 반으로 나눈다
		// 중간 위치 결정
		middle = (low + high) / 2;

		// 키 값과 리스트의 값을 비교하여 같으면 탐색 성공
		if (key == list[middle])
		{
			printf("탐색 횟수 = %d\n", i);
			return middle;
		}
		// key 가 middle 값보다 작으면 low ~ middle-1 사이 검색
		// low 의 값을 middle + 1 로 바꾼다
		else if (key > list[middle])
		{
			i++;
			low = middle + 1;
		}
		// key 가 middle 값보다 크면 middle+1 ~ high 사이 검색
		// high 의 값을 middle - 1 로 바꾼다
		else
		{
			i++;
			high = middle - 1;
		}
	}

	printf("탐색 횟수 = %d\n", i);

	return -1;
}

#define MAX 100

int main()
{
	int arr[MAX];
	int key = 0;

	for (int i = 0; i < MAX; i++)
	{
		arr[i] = i + 1;
	}

	printf("키 값을 입력해주세요 ");
	scanf("%d", &key);

	// 반복문을 이용한 이진 탐색
	if (binarySearchIter(arr, key, 0, MAX) == key - 1)
	{
		printf("탐색 성공!\n\n");
	}
	else
	{
		printf("탐색 실패\n");
	}

	// 순환 호출을 이용한 이진 탐색
	if (binarySearch(arr, key, 0, MAX) == key - 1)
	{
		printf("탐색 성공!\n\n");
	}
	else
	{
		printf("탐색 실패\n");
	}

	return 0;
}