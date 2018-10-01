#include <cstdio>

#define MAX_W 3
#define MAX_H 3

class Transpose
{
private:
	int matrix[MAX_H][MAX_W];

public:
	Transpose()
	{
		for (int i = 0; i < MAX_H; i++)
		{
			for (int j = 0; j < MAX_W; j++)
			{
				if (j == 0)
					matrix[i][j] = 0;
				else
					matrix[i][j] = 1 + matrix[i][j-1];
			}
		}
	}

	void output()
	{
		for (int i = 0; i < MAX_H; i++)
		{
			printf("{");
			for (int j = 0; j < MAX_W; j++)
			{
				printf(" %d", matrix[i][j]);
			}
			printf("}");
			printf("\n");
		}
	}

	void transpose()
	{
		int temp;

		for (int i = 0; i < MAX_H; i++)
		{
			if (i == 2)
				break;

			for (int j = 0; j < MAX_W; j++)
			{
				if (i == 1 && j == 0)
					continue;

				temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;

			}
		}
	}
};

int main()
{
	Transpose a;

	a.output();
	printf("\n");
	a.transpose();
	printf("\n");
	a.output();

	return 0;
}