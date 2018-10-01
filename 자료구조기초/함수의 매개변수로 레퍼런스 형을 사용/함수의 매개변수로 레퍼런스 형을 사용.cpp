#include <cstdio>

// 레퍼런스 사용
// 참조에 의한 호출(Call by reference)
void swap(int& x, int& y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int a = 1, b = 2;

	printf("a = %d, b = %d\n", a, b);

	swap(a, b);

	printf("a = %d, b = %d\n", a, b);

	return 0;
}