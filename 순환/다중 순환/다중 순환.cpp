#include <cstdio>

// 순환 함수들은 호출이 발생할 때마다 몇개의 순환 호출이 이루어지는가에 따라 선형 순환, 이진 순환, 다중 순환으로 나눌 수 있다
// 선형 순환(linear recursion)은 함수의 호출이 발생하면 최대로 하나의 순환 호출이 이루어지는 경우(예 - 팩토리얼 계산, 거듭 제곱 계산 등)
// 이진 순환(binart recursion)은 함수에서 두 개의 순환 호출이 발생하는 경우(예 - 피보나치수열, 하노이 탑 등)
// 다중 순환(multiple recursion)은 이진 순환을 일반화하여 하나의 함수에서 두 개 이상의 순환 호출이 이루어지는 경우

// 영역 채식 문제
// 영상 처리 분야에서 영역 채색(blob coloring)또는 연결 화소 분석법(connected component labelling)이라 불리는 알고리즘은
// 흑과 백의 화소 값만을 갖는 이진 영상(binart image)에서 연결된 객체를 찾는 방법이다
// 각각을 고유한 화소 값으로 채색할 수만 있으면 객체의 수나 각 객체들의 위치와 크기, 형태 등을 분석할 수 있다
// 따라서 영역 채색은 영상처리에서 매우 중요한 연산의 하나이다

// 영역 채색 문제는 단순화를 위해 2차원 배열을 이용하여 정적으로 할당하였는데 동적 할당을 사용하여 임의의 크기의 영상에 대해서도 처리할 수 있도록 구현하는 것이 바람직하다

// 실행 결과를 보면 입력 영상의 자료! 란 글자의 각 연결된 부분들 (ㅈ, ㅏ, ㄹ, ㅛ, 느낌표(!)의 두 영역)이 각각의 객체가 되어 채색되었으며
// 전체 6개의 객체가 검출된 것을 알 수 있다

// 이 프로그램은 실제로 객체의 영역의 크기가 크지 않은 경우는 매우 안정적으로 실행된다
// 그러나 영상의 크기가 크고, 객체 영역의 면적이 매우 넓은 경우 실행속도가 느려지며 심한 경우 스택 오버플로우가 발생할 수 있다
// 따라서 일반적으로는 주사선 알고리즘(scanline algorithm)을 사용한다
// 반복문을 사용하는 '주사선 알고리즘'은 '순환 알고리즘'에 비하면 코드가 매우 복잡하지만 처리시간이 빠르고, 영상의 크기와 상관없이 일정한 시간 안에 결과를 얻을 수 있다

#define WIDTH 20
#define HEIGHT 9

// 순환 호출 함수 (다중 순환의 예)
void labelComponent(unsigned char img[HEIGHT][WIDTH], int x, int y, int label)
{
	// 영상의 밖이면 나간다
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return;

	// 처리가 안 된 전경 화소이면
	if (img[y][x] == 9)
	{
		// label로 화소 값을 바꾸고
		img[y][x] = label;
		// 상하좌우의 4방향으로 인접한 화소에 대해 동일한 처리를 하도록 순환 호출을 한다
		labelComponent(img, x - 1, y, label); // 순환 호출: 좌측 이웃화소
		labelComponent(img, x, y - 1, label); // 순환 호출: 상측 이웃화소
		labelComponent(img, x + 1, y, label); // 순환 호출: 우측 이웃화소
		labelComponent(img, x, y + 1, label); // 순환 호출: 하측 이웃화소
	}
}

// 이진 영상의 영역 채색(blob coloring) 함수
void blobColoring(unsigned char img[HEIGHT][WIDTH])
{
	// label은 1부터 시작함
	int label = 1;

	// 영상의 모든 화소에 대해
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			// 처리가 안 된 전경 화소이면
			if (img[y][x] == 9)
				// 연결화소 채색 시작
				labelComponent(img, x, y, label++);
		}
	}
}

// 영상의 화소 값을 화면에 출력하는 함수
void printImage(unsigned char img[HEIGHT][WIDTH], const char* msg)
{
	printf("%s\n", msg);

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (img[y][x] == 0)
				printf(".");
			else
				printf("%-1d", img[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

// 주 함수
int main()
{
	unsigned char image[HEIGHT][WIDTH] = {
		0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
		9,9,9,9,9,0,9,0,0,0,0,0,0,0,0,9,0,0,9,9,
		0,0,9,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
		0,9,9,9,0,0,9,9,9,0,0,9,0,0,0,0,0,0,9,9,
		0,9,0,9,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
		9,9,0,9,9,0,9,0,0,0,0,0,0,0,0,0,0,0,9,9,
		9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,0,0,
		9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,9,9,
		0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9
	};

	printImage(image, "<Original image>");
	blobColoring(image);
	printImage(image, "<Labelled image>");

	return 0;
}