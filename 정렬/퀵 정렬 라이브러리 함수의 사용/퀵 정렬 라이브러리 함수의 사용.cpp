#include <cstdlib>
#include <cstring>
#include <cstdio>

// 이와 같이 퀵 정렬의 장점에 따라 C언어나 C++의 실행 시간 라이브러리에서 퀵 정렬 함수가 제공된다
// 보통 qsort() 란 이름으로 제공되는데, 이 함수를 어떻게 사용하는지 이해하고 활용할 수 있다면 매우 유용할 것이다

// 함수의 원형
/*
	void qsort
	{
		void* base,   // 배열의 시작 주소
		size_t num,   // 배열 요소의 개수
		size_t width, // 배열 요소 하나의 크기(바이트 단위)
		int (*compare)(const void *, const void *) // 비교 함수, 포인터를 통하여 두 개의 요소를 비교하여 비교 결과를 정수로 반환한다, 사용자가 제공하여야 됨
	}
*/

// 함수의 설명
// 이 함수는 각 요소가 width 바이트인 num 개의 요소를 가지는 배열에 대하여 퀵 정렬을 수행한다
// 입력 배열은 정렬된 값으로 덮어 씌워진다,
// compare()는 배열 요소 2개를 서로 비교하는 사용자 제공 함수로 qsort 함수가 요소들을 비교할 때마다 다음과 같이 호출하여 사용한다
/*
	compare((void *)elem1,(void *)elem2);

	반환값
	< 0  - elem1이 elem2 보다 작으면
	0    - elem1이 elem2 과 같으면
	> 0  - elem1이 elem2 보다 크면
*/

// 다음은 퀵 정렬 라이브러리 함수를 사용하는 예를 보인다
// 배열의 요소가 double 형이므로 이에 따른 compare() 함수를 보였다
// 만약 클래스 객체의 배열을 정렬하려면 compare() 에서 정렬하고자 하는 필드를 비교하여 적절한 값을 반환하면 된다
int compare(const void* arg1, const void* arg2)
{
	if (*(double*)arg1 > *(double*)arg2)
		return 1;
	else if (*(double*)arg1 < *(double*)arg2)
		return -1;
	else
		return 0;
}

void main()
{
	double list[5] = { 2.1, 0.9, 1.6, 3.8, 1.2 };

	qsort((void*)list, 5, sizeof(double), compare);

	for (int i = 0; i < 5; i++)
		printf("%f ", list[i]);
}