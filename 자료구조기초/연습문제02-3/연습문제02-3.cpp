/*83P-3번
크기가 10인 배열two[]을 선언하고 2의 제곱 값들을 저장한 후 for문을 이용하여 출력하기*/

#include <cstdio>

#define MAX 10

class Two
{
private:
	int two[MAX];
public:
	Two()
	{
		for (int i = 0; i < MAX; i++)
		{
			if (i == 0)
				two[i] = 1;
			else
				two[i] = 2 * two[i-1];
		}
	}

	void output()
	{
		for (int i = 0; i < MAX; i++)
		{
			printf("%d ", two[i]);
		}
	}
};

int main()
{
	Two a;

	a.output();

	return 0;
}