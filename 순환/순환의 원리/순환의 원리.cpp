#include <cstdio>

// 순환(재귀함수)를 이용한 최대값 구하기

#define MAX 5

int a[MAX] = { 2,5,3,1,6 };

int findMax(int low, int high)
{
	if (low == high)
	{
		return a[low];
	}
	else
	{
		int left_max = findMax(low, (high + low) / 2);
		int right_max = findMax((high + low) / 2 + 1, high);

		return left_max > right_max ? left_max : right_max;
	}
}

int main()
{
	int nMax = findMax(0, MAX);
	printf("Max : %d\n", nMax);

	return 0;
}