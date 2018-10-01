#include <queue>
#include <iostream>
#include "Location2D.h"

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

// 큐를 이용한 미로탐색
// 큐를 사용하는 것은 너비 우선 탐색(BFS : Bread First Search)전략으로 탐색 순서에서 깊이보다는 폭을 우선으로 취한다
// 이것은 스택을 이용한 탐색보다 오래걸렸지만 미로의 구성이 어떻게 되어있는가에 따라 속도가 변할 수 있고
// 탐색순서에 따라 달라질수 있다 예제에는 상-하-좌-우 순서로 탐색을 했지만 상-우-하-좌와 같이 탐색하면 스택이나 큐에 들어가는 순서가 달라지고 그에 따라 속도가 변한다
int main()
{
	queue<Location2D> locQueue;
	Location2D entry(1, 0);
	locQueue.push(entry);

	while (locQueue.empty() == false) // 큐가 비어있지 않는 동안
	{
		Location2D here = locQueue.front(); // 큐의 front 상단 객체 복사
		locQueue.pop(); // 큐의 상단 객체 삭제

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
			if (isValidLoc(r - 1, c)) locQueue.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c)) locQueue.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1)) locQueue.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1)) locQueue.push(Location2D(r, c + 1));
		}
	}

	printf("미로 탐색 실패\n");

	return 0;
}