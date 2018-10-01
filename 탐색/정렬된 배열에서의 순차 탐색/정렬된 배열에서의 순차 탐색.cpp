#include <stdio.h>

// 배열이 정렬되어 있지 않다면 순차 탐색 이외에는 별다른 대안이 없다
// 그러나 맵에서 배열을 키값에 따라 정렬하여 관리하고 있다면 보다 개선된 탐색 방법을 사용할 수 있다

// 배열이 정렬되어 있으면 순차 탐색 실행 중에 탐색키보다 큰 레코드르 만나면 탐색을 종료 할 수 있으므로
// 배열 전체를 검색하지 않고도 탐색 항목의 존재 유무를 알 수 있다

// 정렬된 리스트를 순차 탐색할 경우 비교 횟수는 배열에 해당 항목이 존재하여 탐색이 성공했을 경우
// 일반 순차 탐색과 동일하지만, 해당 항목이 리스트에 존재하지 않아서 탐색이 실패할 경우에는 비교 횟수가 반으로 줄어든다
// 그러나 시간 복잡도의 차수는 원래의 순차 탐색과 동일하게 O(n) 으로 변함이 없다

int sortedSequentialSearch(int list[], int key, int low, int high)
{
	printf("탐색 키 = %d\n", key);
	int i;

	// 탐색 할 키 값이 범위안에 들지 않을 경우 바로 함수를 종료한다
	if (key<list[low] || key>list[high])
	{
		printf("탐색 할 키 값이 범위 미달이거나 초과했습니다\n");
		return -1;
	}

	// 키 값이 범위안에 들었을 경우 탐색을 시작한다
	for (i = low; i <= high; i++)
	{
		printf("탐색 중...\n");

		// 탐색 중 키 값이 리스트안의 데이터보다 작으면 바로 종료한다
		if (list[i] > key)
		{
			printf("탐색 횟수 = %d\n", i + 1);
			printf("탐색 할 키 값이 범위 미달입니다\n");
			return -1;
		}

		// 키 값이 리스트의 데이터와 일치하면 탐색 성공
		// 이때 시간 복잡도는 O(n) 으로 일반 순차 탐색과 동일하다
		if (list[i] == key)
		{
			printf("탐색 횟수 = %d\n", i + 1);
			printf("탐색 결과 = %d\n", key);
			return 1;
		}
	}
}

int main()
{
	int arr[5] = { 3,5,7,8,9 };
	int key = 0;

	printf("탐색할 키를 입력하세요 : ");
	scanf("%d", &key);

	int search = sortedSequentialSearch(arr, key, 0, 4);

	if (search == 1)
		printf("탐색 성공!\n");
	else
		printf("탐색 실패\n");

	return 0;
}