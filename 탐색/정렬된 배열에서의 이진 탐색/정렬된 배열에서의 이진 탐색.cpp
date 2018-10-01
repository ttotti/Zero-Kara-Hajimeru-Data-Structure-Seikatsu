#include <cstdio>

// ���ĵ� �迭�� Ž������ ���� Ž�� �� ����� �� �ִ�
// �� ����� �迭�� �߾ӿ� �ִ� ���� �����Ͽ� ã���� �ϴ� �׸��� ���� �κ� �迭�� �ִ��� ������ �κ� �迭�� �ִ��� �Ǵ��ϰ�
// ���� �ܰ��� Ž�� ������ ������ ���δ�, ���� �� �ܰ迡�� �˻��ؾ� �� ����Ʈ�� ũ�Ⱑ ������ �پ���
// �̿� ���� ���� Ž���� �����Ϸ��� Ž���ϱ� ���� �ݵ�� �迭�� ���ĵǾ� �־�� �ϴ�
// ���� ���� Ž���� �������� �����̳� ������ ����� ��쿡�� �������� �ʴ�

// ���� Ž���� Ž���� �ݺ��� ������ Ž�� ������ ������ ���δ�
// �̷��� Ž�� ������ �� �̻� ���� �� ���� 1�� �� ���� Ž��Ƚ���� k�� �ϸ�, n/2^k = 1 �̹Ƿ� k = log2 n ���� �� �� �ִ�
// �ᱹ ���� Ž���� �ð� ���⵵�� O(log2 n) �� �ȴ�

// ��ȯ ȣ��(��� ȣ��)�� �̿��� ���� Ž��
int j = 0;
int binarySearch(int list[], int key, int low, int high)
{
	if (j == 0)
		printf("���� Ž��(��ȯ ȣ��) Ž�� ����\n");

	int middle;

	// �ϳ� �̻��� �׸��� �־�� Ž��
	if (low <= high)
	{
		printf("Ž�� ��...\n");

		// �������� ������ ������ ������
		// �߰� ��ġ ����
		middle = (low + high) / 2;

		// Ű ���� ����Ʈ�� ���� ���Ͽ� ������ Ž�� ����
		if (key == list[middle])
		{
			printf("Ž�� Ƚ�� = %d\n", j);
			return middle;
		}
		// ���� �κи���Ʈ Ž��
		// �߰� ��ġ�� Ű ������ key�� ������ ���� �κ� ����Ʈ Ž��
		else if (key < list[middle])
		{
			j++;
			return binarySearch(list, key, low, middle - 1);
		}
		// ������ �κи���Ʈ Ž��
		// �ƴϸ� ���� �κ� ����Ʈ Ž��
		else
		{
			j++;
			return binarySearch(list, key, middle + 1, high);
		}

	}

	printf("Ž�� Ƚ�� = %d\n", j);
	// Ž�� ����
	return -1;
}

// ���� Ž���� �ݺ����� ����Ͽ� ������ ���� �ִ�
// ȿ������ ���ؼ��� �ݺ� ������ ����ϴ� ���� �� ����
int binarySearchIter(int list[], int key, int low, int high)
{
	printf("���� Ž��(�ݺ���) Ž�� ����\n");

	int middle;
	int i = 0;

	// �׸���� ���� ������(���� ����)
	while (low <= high)
	{
		printf("Ž�� ��...\n");

		// �������� ������ ������ ������
		// �߰� ��ġ ����
		middle = (low + high) / 2;

		// Ű ���� ����Ʈ�� ���� ���Ͽ� ������ Ž�� ����
		if (key == list[middle])
		{
			printf("Ž�� Ƚ�� = %d\n", i);
			return middle;
		}
		// key �� middle ������ ������ low ~ middle-1 ���� �˻�
		// low �� ���� middle + 1 �� �ٲ۴�
		else if (key > list[middle])
		{
			i++;
			low = middle + 1;
		}
		// key �� middle ������ ũ�� middle+1 ~ high ���� �˻�
		// high �� ���� middle - 1 �� �ٲ۴�
		else
		{
			i++;
			high = middle - 1;
		}
	}

	printf("Ž�� Ƚ�� = %d\n", i);

	return -1;
}

#define MAX 100

int main()
{
	int arr[MAX];
	int key = 0;

	for (int i = 0; i < MAX; i++)
	{
		arr[i] = i + 1;
	}

	printf("Ű ���� �Է����ּ��� ");
	scanf("%d", &key);

	// �ݺ����� �̿��� ���� Ž��
	if (binarySearchIter(arr, key, 0, MAX) == key - 1)
	{
		printf("Ž�� ����!\n\n");
	}
	else
	{
		printf("Ž�� ����\n");
	}

	// ��ȯ ȣ���� �̿��� ���� Ž��
	if (binarySearch(arr, key, 0, MAX) == key - 1)
	{
		printf("Ž�� ����!\n\n");
	}
	else
	{
		printf("Ž�� ����\n");
	}

	return 0;
}