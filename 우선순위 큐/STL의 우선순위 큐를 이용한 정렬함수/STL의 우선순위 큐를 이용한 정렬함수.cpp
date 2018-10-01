#include <queue>
#include <functional>
#include <time.h>

using namespace std;

// ǥ�� ���ø� ���̺귯�������� �켱���� ť�� �����Ѵ�
// ���� STL�� �켱���� ť�� ����Ϸ��� <queue> ��������� �����Ѵ�

// STL�� �켱���� ť�� �̿��� �������� ����, �ִ� �� ��� (�θ� ����� Ű ���� �ڽ� ����� Ű ������ ũ�ų� ���� ���� ����Ʈ��)
void heapSortDec(int a[], int n)
{
	// �ִ� ��: "less than operator"�� ����ϴ� priority_queue

	// �� ���忡���� �⺻������ "less than operator"�� ����ϴµ�
	// ���� ���� ū �׸� ���� ��µǴ� �ִ� ������ �����Ѵ�
	priority_queue<int> maxHeap;

	// ���ʷ� ť�� �����͸� �ִ´�
	for (int i = 0; i < n; i++)
	{
		// ������ �����Լ� insert()�� STL�� �켱���� ť���� push()�� ����ؾ� �Ѵ�
		maxHeap.push(a[i]);
	}

	for (int i = 0; i < n; i++)
	{
		// �����Լ��� STL�� ť������ ���������� top()�� pop()���� �и��Ǿ� �ִ�
		// top()�� ���� �켱������ ����(�Ǵ� ����) �׸��� ��ȯ�ϰ�(���������� ����)
		a[i] = maxHeap.top();
		// pop()�� ��ȯ���� �ʰ� �� �׸��� �켱���� ť���� �����Ѵ�
		maxHeap.pop();
	}
}

// STL�� �켱���� ť�� �̿��� �ø����� ����, �ּ� �� ��� (�θ� ����� Ű ���� �ڽ� ����� Ű ������ �۰ų� ���� ���� ����Ʈ��)
void heapSortInc(int a[], int n)
{
	// �ּ� ��: "greater than operator"�� ����ϴ� priority_queue

	// �ּ� ���� ����Ϸ��� "greater than operator"�� ����ؾ� �ϰ�
	// �켱���� ť ��ü�� ������ ������ ���� ���� �� ����������
	// ���� �ּ� ���� ����Ϸ��� ������� <functional>�� �߰��� �����ؾ� �Ѵ�
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i = 0; i < n; i++)
	{
		minHeap.push(a[i]);
	}

	for (int i = 0; i < n; i++)
	{
		a[i] = minHeap.top();
		minHeap.pop();
	}
}

int main()
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 5; i++)
	{
		int data[6];

		for (int i = 0; i < 6; i++)
		{
			data[i] = rand() % 45 + 1;
		}

		printf("������: ");

		for (int i = 0; i < 6; i++)
			printf("%3d", data[i]);

		printf("\n\n�������� ����, �ִ��� ���");

		heapSortDec(data, 6);

		printf("\n������: ");

		for (int i = 0; i < 6; i++)
		{
			printf("%3d", data[i]);
		}

		printf("\n\n");

		printf("�ø����� ����, �ּ��� ���");

		heapSortInc(data, 6);

		printf("\n������: ");

		for (int i = 0; i < 6; i++)
		{
			printf("%3d", data[i]);
		}

		printf("\n---------------------------------");
		printf("\n\n");
	}


	return 0;
}