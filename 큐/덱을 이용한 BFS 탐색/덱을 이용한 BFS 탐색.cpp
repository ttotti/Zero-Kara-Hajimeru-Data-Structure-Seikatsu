#include "Location2D.h"
#include <deque>
#include <iostream>

using namespace std;

const int MAZE_SIZE = 6; // 미로 맵 크기 고정

char map[MAZE_SIZE][MAZE_SIZE] = { // 미로 맵 데이터
	{ '1','1','1','1','1','1' },
	{ 'e','0','1','0','0','1' },
	{ '1','0','0','0','1','1' },
	{ '1','0','1','0','1','1' },
	{ '1','0','1','0','0','x' },
	{ '1','1','1','1','1','1' },
};

// (r,c)가 갈 수 있는 위치인지를 검사하는 함수
// (r,c)가 배열 안에 있고, 값이 갈 수 있는 위치 '0' 이거나 'x' 이어야 함
bool isValidLoc(int r, int c)
{
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) // 위치 값(r,c)이 0보다 작거나 맵의 최대 크기 보다 크면 갈 수 없다
		return false;
	else
		return map[r][c] == '0' || map[r][c] == 'x';
}

// 덱을 이용한 BFS 탐색
int main()
{
	deque<Location2D> locDeque;
	Location2D entry(1, 0);
	locDeque.push_front(entry);

	while (locDeque.empty() == false) // 덱이 비어있지 않을동안
	{
		Location2D here = locDeque.front(); // 상단 복사
		locDeque.pop_front(); // 상단 삭제

		int r = here.row;
		int c = here.col;

		printf("(%d,%d) ", r, c);

		if (map[r][c] == 'x')
		{
			printf("미로 탐색 성공\n");
			return 0;
		}
		else
		{
			map[r][c] = '.';

			if (isValidLoc(r - 1, c)) 
				locDeque.push_back(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c))
				locDeque.push_back(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1))
				locDeque.push_back(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1))
				locDeque.push_back(Location2D(r, c + 1));
		}
	}

	printf("미로 탐색 실패\n");

	return 0;
}