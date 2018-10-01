#include <cstdio>
#include <cstdlib>
#include <memory.h>

// ���� ������ ���� ���� ���ڵ���� �̵��� �����Ѵ�
// ��������� ���� ������ ���ڵ���� ���� Ư�� ���ڵ� ũ�Ⱑ Ŭ ��쿡 �������� ������ �� �� �ִ�
// �ݸ鿡 �˰����� �����ϹǷ� ���ڵ��� ���� ���� ��� ȿ������ �� �ִ�
// Ư�� ���� ������ ��κ��� ���ڵ尡 �̹� ���ĵǾ� �ִ� ��쿡�� ȿ������ �˰����� �� �� �ִ�

// �������� �˰����� �̿��� int �迭�� ������������ �����ϴ� �Լ�
void insertionSort(int A[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = A[i];
		int j;

		for (j = i - 1; j >= 0 && A[j] > key; j--)
		{
			// ���ڵ��� ������ �̵�
			A[j + 1] = A[j];
		}

		A[j + 1] = key;
	}
}

inline int ascend(int x, int y) { return y - x; }  // �������� ���Լ�
inline int descend(int x, int y) { return x - y; } // �������� ���Լ�

// �Լ� �����͸� �Ű������� �޴� �������� �Լ�
void insertionSortFn(int A[], int n, int(*f)(int, int))
{
	for (int i = 0; i < n; i++)
	{
		int key = A[i];
		int j;

		// ���� �迭 ��ҿ� ���� ����� ������ �迭 ��� �̹Ƿ� -1 �� �Ѵ�
		// ���� �迭�� ù ��° ��Ҵ� ���� �ʿ䰡 �����Ƿ� j >= 0 �� �Ͽ� �׳� �Ѿ��
		// �׸��� �������� �� �������� �� ���ϱ� ���� �Լ� �����͸� ȣ���Ѵ� 
		// �� �Լ� �����ͷ� 0���� ���� ���� ������ �� ���� �������� ������ �ٸ� ������ ���������� ������
		for (j = i - 1; j >= 0 && f(A[j], key) < 0; j--)
		{
			A[j + 1] = A[j];
		}

		A[j + 1] = key;
	}
}

// ���� �Լ��� �̿��Ͽ� int �迭�� 0 ~ max-1 �� ������ �������� ä��� �Լ�
// static ���� �����Ͽ� ĸ��ȭ �Ͽ��� (static ���� ����� �Լ��� ������ ���Ͼȿ����� ����� �� �ִ�)
static void initRandom(int list[], int n, int max = 100)
{
	for (int i = 0; i < n; i++)
	{
		list[i] = rand() % max;
	}
}

// �迭�� ȭ�鿡 ���� ���� ����ϴ� �Լ�, ����Ʈ �Ű����� ���
// static ���� �����Ͽ� ĸ��ȭ �Ͽ��� (static ���� ����� �Լ��� ������ ���Ͼȿ����� ����� �� �ִ�)
static void PrintArray(int arr[], int n, const char* str = "Array")
{
	printf("%s = ", str);

	for (int i = 0; i < n; i++)
		printf("%3d", arr[i]);

	printf("\n");
}

int main()
{
	int list[5] = { 8,2,1,7,5 };
	int n = 5;

	//initRandom(list, n);
	// ���� �� �迭 ������ ���
	PrintArray(list, n, "Original ");

	// �������� �������� �˰���
	insertionSortFn(list, n, ascend);
	// ���� �� �迭 ������ ���
	PrintArray(list, n, "Insert-As");

	// �������� �������� �˰���
	insertionSortFn(list, n, descend);
	// ���� �� �迭 ������ ���
	PrintArray(list, n, "Insert-De");

	return 0;
}