#include <cstdio>

// 보간 탐색(interpolation search) 은 사전이나 전화번호부를 탐색하는 방법과 같이 탐색키가 존재할 위치를 예측하여 탐색하는 방법이다
// 이는 우리가 사전을 찾을 때 'ㅎ' 으로 시작하는 단어는 사전의 뒷부분에서 찾는 것과 같은 원리다
// 보간 탐색은 이진 탐색과 유사하나 리스트를 반으로 분할하지 않고 불균등하게 분할하여 탐색한다

// 이진 탐색에서 탐색 위치는 항상(low+high)/2 이나 
// 보간 탐색에서는 찾고자하는 키 값과 현재의 low, high 위치의 값을 고려하여 다음과 같이 다음 탐색 위치를 결정한다
/*
	탐색 위치 = (int)((float)(key - list[low]) / (list[high] - list[low])*(high - low) + low);
*/
// 여기에서 key 는 찾고자 하는 키값을, low와 high는 각각 탐색할 범위의 최소, 최대 인덱스 값을 나타낸다
// 이 식은 탐색 값과 위치는 비례한다는 가정에서 탐색 위치를 결정할 때 찾고자 하는 키값이 있는 곳에 근접하도록 가중치를 주는 방법이다

// 계산 결과는 일반적으로 실수이며 따라서 이 실수를 정수로 변환하여 주어야 한다, 보통은 소수점 이하를 버리는 방법을 사용한다

// 보간 탐색은 이진 탐새곽 같은 O(log2 n) 의 시간 복잡도를 가지지만
// 많은 데이터가 비교적으로 균등하게 분포되어 있는 자료의 경우 훨씬 효율적인 방법이 된다
// 만약 나눗셈을 계산할 때 float로 형 변환을 하지 않으면 정수로 계산되어 항상 0이 된다는 점을 주의해야 한다

int interpolationSeatch(int list[], int nList, int key)
{
	printf("탐색 시작\n");
	int low = 0;
	int high = nList - 1;

	int count = 0;

	while ((list[low] <= key) && (key <= list[high]))
	{
		printf("탐색 중...\n");
		count++;

		int j = (int)((float)(key - list[low]) / (list[high] - list[low])*(high - low) + low);

		if (key > list[j])
			low = j + 1;
		else if (key < list[j])
			high = j - 1;
		else
		{
			printf("탐색 횟수 = %d\n", count);
			return j;
		}
	}

	printf("탐색 횟수 = %d\n", count);
	return -1;
}

int main()
{
	int arr[10] = { 3,9,15,16,17,40,41,42,50,77 };
	int key = 0;

	printf("탐색 키를 입력해주세요 : ");
	scanf("%d", &key);

	int i = interpolationSeatch(arr, 10, key);

	if (i >= 0)
		printf("탐색 성공\n");
	else
		printf("탐색 실패\n");

	return 0;
}