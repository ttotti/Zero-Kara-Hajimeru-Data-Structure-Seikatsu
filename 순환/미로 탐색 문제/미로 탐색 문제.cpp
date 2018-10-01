#include "Location2D.h"
#include <cstdio>

// 미로 찾기 문제도 순환을 이용하여 구현할 수 있다

// 미로 맵 크기 고정
const int MAZE_SIZE = 6;

// 미로 맵 데이터
char map[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},
};

bool isValidLoc(int r, int c)
{
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)
		return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}

// 입구와 출구 위치
Location2D locEntry, locExit;
// 탐색 성공 여부
// 탐색이 성공하면 더 이상 순환 호출을 하지 않도록 done변수를 true로 설정한다
bool done = false;

// 순환으로 구현한 미로 탐색 함수
void searchRecur(Location2D pt)
{
	// 현재 위치 화면 출력
	printf("(%d,%d) ", pt.row, pt.col);

	// 이미 탐색이 성공했으면 나간다
	if (done) return;

	// 현재 위치가 출구이면 ==> 성공
	if (pt == locExit)
	{
		done = true;
		return;
	}

	int r = pt.row;
	int c = pt.col;
	map[r][c] = '5';

	// 네 방향 이웃에 대해 순환 호출
	if (isValidLoc(r - 1, c))searchRecur(Location2D(r - 1, c));
	if (isValidLoc(r + 1, c))searchRecur(Location2D(r + 1, c));
	if (isValidLoc(r, c - 1))searchRecur(Location2D(r, c - 1));
	if (isValidLoc(r, c + 1))searchRecur(Location2D(r, c + 1));
}

// 미로 탐색 프로그램 주 함수
int main()
{
	locEntry.set(1, 0);
	locExit.set(4, 5);

	searchRecur(locEntry);

	if (done)
		printf("\n ==> 출구가 탐지되었습니다\n");
	else
		printf("\n ==> 출구를 찾지 못했습니다\n");

}