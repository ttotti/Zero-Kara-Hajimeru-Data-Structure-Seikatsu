#include <cstdio>
#include <cstdlib>

int** alloc2DInt(int rows, int cols);
void free2DInt(int** mat, int rows, int cols = 0);
void set2DRandom(int** mat, int rows, int cols);
void print2DInt(int** mat, int rows, int cols);

// int형 2차원 배열 동적 할당 함수
int** alloc2DInt(int rows, int cols)
{
	if (rows <= 0 || cols <= 0)
		return NULL;

	// 포인터 변수를 저장할 배열
	int** mat = new int*[rows];

	// 실제 각 행의 데이터를 저장할 배열
	for (int i = 0; i < rows; i++)
		mat[i] = new int[cols];

	return mat;
}

// int형 2차원 배열 동적 해재 함수
void free2DInt(int** mat, int rows, int cols)
{
	// 할당 과정에서 new 연산자가 여러 번 사용되었으므로 해제 과정에서도 new 연산자가 사용된 횟수만큼 delete 연산자가 호출되어야 한다
	if (mat != NULL)
	{
		// 행의 수 rows와 열의 수 cols를 받아 2차원 배열을 동적으로 해제
		// cols는 사용되지 않으므로 디폴트 매개변수 처리를 함
		// 먼저 동적으로 할당된 각각의 데이터 mat[i](int 배열)를 없앰
		for (int i = 0; i < rows; i++)
			delete[]mat[i];

		// 최종적으로 포인터 배열(mat)을 해제함
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
	printf("행의 수 = %d, 열의 수 = %d\n", rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%4d",mat[i][j]);
		}

		printf("\n");
	}
}

// 행렬이나 영상 처리등 2차원 배열 형태의 데이터를 필요로 하는 분야는 많다
// 이와 같이 2차원 배열을 2중 포인터로 처리하면 set2DRandom 이나 print2DInt 에서와 같이 임의의 크기의 영상이나 행렬에 대한 처리가 가능한 함수의 처리가 가능하다
// 또한 2차원 배열의 동적할당은 다른 방법으로도 가능하다
// 예제에서는 new 연산자를 행의 수보다 한번 더 사용했는데
// new 연산자를 두 번만 사용하고 각 행 데이터에 대한 주소값을 계산하여 대입하는 방법과
// new 연산자는 한번만 사용하여 필요한 모든 데이터를 한꺼번에 동적으로 할당하고도 동일한 기능을 구현할 수 있다
// 물론 할당방법이 바뀌면 해제 과정도 변경되어야 한다
int main()
{
	int** mat;
	int rows, cols;

	printf("행과 열의 크기를 입력하시오: ");
	scanf("%d%d", &rows, &cols);

	mat = alloc2DInt(rows, cols);
	set2DRandom(mat, rows, cols);
	print2DInt(mat, rows, cols);
	free2DInt(mat, rows, cols);

	return 0;
}