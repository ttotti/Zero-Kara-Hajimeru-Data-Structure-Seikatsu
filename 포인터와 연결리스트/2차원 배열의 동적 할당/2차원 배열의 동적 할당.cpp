#include <cstdio>
#include <cstdlib>

int** alloc2DInt(int rows, int cols);
void free2DInt(int** mat, int rows, int cols = 0);
void set2DRandom(int** mat, int rows, int cols);
void print2DInt(int** mat, int rows, int cols);

// int�� 2���� �迭 ���� �Ҵ� �Լ�
int** alloc2DInt(int rows, int cols)
{
	if (rows <= 0 || cols <= 0)
		return NULL;

	// ������ ������ ������ �迭
	int** mat = new int*[rows];

	// ���� �� ���� �����͸� ������ �迭
	for (int i = 0; i < rows; i++)
		mat[i] = new int[cols];

	return mat;
}

// int�� 2���� �迭 ���� ���� �Լ�
void free2DInt(int** mat, int rows, int cols)
{
	// �Ҵ� �������� new �����ڰ� ���� �� ���Ǿ����Ƿ� ���� ���������� new �����ڰ� ���� Ƚ����ŭ delete �����ڰ� ȣ��Ǿ�� �Ѵ�
	if (mat != NULL)
	{
		// ���� �� rows�� ���� �� cols�� �޾� 2���� �迭�� �������� ����
		// cols�� ������ �����Ƿ� ����Ʈ �Ű����� ó���� ��
		// ���� �������� �Ҵ�� ������ ������ mat[i](int �迭)�� ����
		for (int i = 0; i < rows; i++)
			delete[]mat[i];

		// ���������� ������ �迭(mat)�� ������
		delete[] mat;
	}
}

void set2DRandom(int** mat, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			mat[i][j] = rand() % 100;
	}
}

void print2DInt(int ** mat, int rows, int cols)
{
	printf("���� �� = %d, ���� �� = %d\n", rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%4d",mat[i][j]);
		}

		printf("\n");
	}
}

// ����̳� ���� ó���� 2���� �迭 ������ �����͸� �ʿ�� �ϴ� �оߴ� ����
// �̿� ���� 2���� �迭�� 2�� �����ͷ� ó���ϸ� set2DRandom �̳� print2DInt ������ ���� ������ ũ���� �����̳� ��Ŀ� ���� ó���� ������ �Լ��� ó���� �����ϴ�
// ���� 2���� �迭�� �����Ҵ��� �ٸ� ������ε� �����ϴ�
// ���������� new �����ڸ� ���� ������ �ѹ� �� ����ߴµ�
// new �����ڸ� �� ���� ����ϰ� �� �� �����Ϳ� ���� �ּҰ��� ����Ͽ� �����ϴ� �����
// new �����ڴ� �ѹ��� ����Ͽ� �ʿ��� ��� �����͸� �Ѳ����� �������� �Ҵ��ϰ� ������ ����� ������ �� �ִ�
// ���� �Ҵ����� �ٲ�� ���� ������ ����Ǿ�� �Ѵ�
int main()
{
	int** mat;
	int rows, cols;

	printf("��� ���� ũ�⸦ �Է��Ͻÿ�: ");
	scanf("%d%d", &rows, &cols);

	mat = alloc2DInt(rows, cols);
	set2DRandom(mat, rows, cols);
	print2DInt(mat, rows, cols);
	free2DInt(mat, rows, cols);

	return 0;
}