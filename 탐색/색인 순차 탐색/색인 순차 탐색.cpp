#include <cstdio>

#define LIST_SIZE 9
#define INDEX_SIZE 3

// 인덱스 테이블 항목의 구조체 선언
struct Index
{
	int key;   // 키 값
	int index; // 키 값의 인덱스
};

int sequentialSearch(int list[], int key, int low, int high)
{
	int i = 0;
	int count = 0;
	printf("탐색 키 = %d\n", key);

	// 배열의 요소를 처음부터 하나씩 검사해서 원하는 레코드를 찾는다
	for (i = low; i <= high; i++)
	{
		printf("탐색 중...\n");
		count++;

		// 배열의 값과 키값이 일치하면 탐색 성공
		if (list[i] == key)
		{
			printf("탐색 횟수 = %d\n", count);
			printf("탐색 결과 = %d\n", list[i]);
			return i + 1;
		}
	}

	printf("탐색 횟수 = %d\n", count);

	// 배열의 값에 원하는 키값이 없으면 탐색 실패
	return -1;
}

// 색인 순차 탐색(indexed sequential search) 방법은 인덱스(index) 라 불리는 테이블을 사용하여 탐색의 효율을 높이는 방법이다
// 인덱스 테이블은 주 자료 리스트에서 일정 간격으로 발췌한 자료를 가지고 있다
// 인덱스 테이블에 m개의 항목이 있고, 주 자료 리스트의 데이터 수가 n이면 
// 각 인덱스 항목은 주 자료 리스트의 각 n/m번째 데이터를 가지고 있다
// 이 때 주 자료 리스트와 인덱스 테이블은 모두 정렬되어 있어야 한다

// 이 방법은 주 자료 리스트에서의 탐색시간을 상당히 줄일 수 있으므로
// 파일 처리, 데이터베이스 등의 응용 분야에서 많이 사용하는 방법이다

// 색인 순차 탐색 알고리즘의 탐색 성능은 인덱스 테이블의 크기에 좌우된다
// 인덱스 테이블의 크기를 줄이면 주 자료 리스트에서의 탐색 시간을 증가시키고,
// 인덱스 테이블의 크기를 크게 하면 인덱스 테이블의 탐색 시간을 증가시킨다
// 인덱스 테이블의 크기를 m이라 하고, 주 자료 리스트의 크기를 n이라 하면
// 색인 순차 탐색의 복잡도는 O(m + n / m) 와 같다
// 물론 주 자료 리스트의 탐색에서 이진 탐색을 사용할 수도 있다

// 색인 순차 탐색 함수
// list - 검색할 데이터 리스트, nList - 항목의 수, tbl - 인덱스 테이블, nTbl - 인덱스 테이블 크기, key - 탐색하고자 하는 키 값을 나타냄
int indexedSearch(int list[], int nList, Index* tbl, int nTbl, int key)
{
	// 키 값이 리스트 범위 밖
	// 키 값이 리스트 범위 내가 아니면 탐색 종료
	if (key<list[0] || key>list[nList - 1])
		return -1;

	// 인덱스 테이블 조사
	// 인덱스 테이블을 조사하여 해당 키의 예상 구간을 찾으면, 그 구간 안에서만 탐색 수행
	for (int i = 0; i < nTbl - 1; i++)
	{
		// 다음 조건을 만족하는 항목을 찾으면
		// 주 자료 테이블에서 해당 범위의 항목들에 대해서만 검색하면 된다
		if (tbl[i].key <= key && tbl[i + 1].key > key)
			return sequentialSearch(list, key, tbl[i].index, tbl[i + 1].index);
	}

	// 인덱스 테이블의 끝이면, 탐색 구간은 최종 인덱스에서 배열의 끝(nList) 까지가 됨, 이 구간에 대해서만 탐색
	return sequentialSearch(list, key, tbl[nTbl - 1].index, nList);
}

int main()
{
	int list[LIST_SIZE] = { 3,9,15,22,31,55,67,88,91 };
	// 인덱스 배열에서 {15,3} 부분은 리스트에 있는 15의 위치와 인덱스 순서가 맞지 않아서 탐색이 안된다, 탐색을 하려면 {15,2} 로 바꿔야 한다
	// 리스트에서 일정 간격으로 인덱스 번호를 부여한다
	Index index[INDEX_SIZE] = { {3,0},{15,3},{67,6} };

	int number, ret;
	printf("탐색할 숫자를 입력하시오 : ", &number);
	scanf("%d", &number);

	ret = indexedSearch(list, LIST_SIZE, index, INDEX_SIZE, number);
	if (ret >= 0)
		printf("탐색 성공 : 숫자(%d) 위치 = %d\n", number, ret);
	else
		printf("숫자(%d) 탐색 실패\n", number);

	return 0;
}