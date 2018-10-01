#include <cstdio>

#define MAX_SIZE 10

void sub(int x, int arr[])
{
	x = 10;
	arr[0] = 10;
}

//////////////////////////////////////

// 1차원 배열에서 최댓값을 구해 반환하는 함수
int findMaxValue(int a[], int len)
{
	int maxVal = a[0];
	for (int i = 1; i < len; i++)
	{
		if (maxVal < a[i])
		{
			maxVal = a[i];
		}
	}

	return maxVal;
}

//////////////////////////////////////

// 2차원 이상의 다차원 배열의 매개변수 전달
// 다차원 배열에서는 a[][5]와 같이 가로 값을 지정해 주어야 한다 일단 이것은 불편하다
// 그리고 이 함수가 배열의 세로길이는 상관없지만 가로길이가 반드시 5인 2차원 배열에 대해서만 동작하는 함수이다
// 임의의 크기를 가지는 프로그램에는 동적할당과 이중 포인터를 사용해야한다
int findMaxPixel(int a[][5], int h, int w)
{
	int maxVal = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (maxVal < a[i][j])
				maxVal = a[i][j];
		}
	}

	return maxVal;
}

int main()
{
	int var;
	int list[MAX_SIZE];

	var = 0;
	list[0] = 0;

	// 변수 var의 값은 변경되지 않았지만 list 배열의 값은 변경되었다(값에 의한 호출 과 레퍼런스에 의한 호출) 
	sub(var, list);
	printf("var = %d, list[0] = %d\n", var, list[0]);

	//////////////////////////////////////////

	int arr[10] = { 3,10,54,78,91,54,12,45,2,46 };

	// 배열의 이름은 포인터역활을 한다 하지만 배열의 주소를 통해 길이를 알수없다(벡터 클래스를 배열 대신 사용하면 가능하다) 
	printf("%d\n", findMaxValue(arr, 10));

	//////////////////////////////////////////

	int img[4][5] = { {3,54,12,87,64},{54,6,8,7,2},{87,65,12,6,7},{78,54,21,64,8}};

	printf("%d\n", findMaxPixel(img, 4, 5));

	return 0;
}