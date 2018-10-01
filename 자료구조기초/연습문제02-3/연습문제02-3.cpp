/*83P-3��
ũ�Ⱑ 10�� �迭two[]�� �����ϰ� 2�� ���� ������ ������ �� for���� �̿��Ͽ� ����ϱ�*/

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