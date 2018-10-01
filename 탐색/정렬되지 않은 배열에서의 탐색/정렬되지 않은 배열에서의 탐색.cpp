#include <stdio.h>

// 만약 배열을 이용해 맵을 구현하고 배열을 정렬하지 않으면 순차 탐색 방법을 사용할 수 있다
// 순차 탐색(sequential Search)은 가장 간단하고 직접적인 탐색 방법이다
// 순차 탐색은 정렬되지 않은 배열에서 탐색 키를 찾을 수 있는데, 배열의 요소들을 처음부터 마지막까지 하나씩 검사하여 원하는 레코드를 찾는 방법이다

// 일단 레코드에는 정수가 저장된다고 가정한다, 이것은 쉽게 다른 자료형으로 확장할 수 있다
// 탐색 대상인 배열 list[] 와 배열에서의 탐색 범위 low, high 가 함수의 매개변수로 주어진다
// 탐색 함수는 탐색에 성공하면 그 항목이 발견된 위치를 반환하고 그렇지 않으면 -1 을 반환한다

// 순차 탐색에서 비교횟수는 찾는 레코드의 위치에 따라 다르다
// 맨 앞에 있으면 1번, 두 번째이면 2번, k번째 있으면 k번 비교가 필요하다, 모든 키가 탐색될 확률이 동일하다가 가정하면
// 순차 탐색의 시간 복잡도는 O(n) 이 된다

int sequentialSearch(int list[], int key, int low, int high)
{
	int i;
	printf("탐색 키 = %d\n", key);

	// 배열의 요소를 처음부터 하나씩 검사해서 원하는 레코드를 찾는다
	for (i = low; i <= high; i++)
	{
		printf("탐색 중...\n");

		// 배열의 값과 키값이 일치하면 탐색 성공
		if (list[i] == key)
		{
			printf("탐색 횟수 = %d\n", i + 1);
			printf("탐색 결과 = %d\n", list[i]);
			return 1;
		}
	}

	printf("탐색 횟수 = %d\n", i + 1);

	// 배열의 값에 원하는 키값이 없으면 탐색 실패
	return -1;
}

int main()
{
	int arr[5] = { 9,5,8,3,7 };
	int key = 0;

	printf("탐색할 키를 입력하세요 : ");
	scanf("%d", &key);

	int search = sequentialSearch(arr, key, 0, 4);

	if (search == 1)
		printf("탐색 성공!\n");
	else
		printf("탐색 실패\n");

	return 0;
}