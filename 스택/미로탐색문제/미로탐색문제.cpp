#include "Location2D.h" // 위치 클래스 포함
#include <stack> // STL의 stack 템플릿 파일 포함

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

// 스택을 이용한 미로탐색
// 스택을 사용하는 것은 DFS(Depth First Search)전략으로 이것은 일단 최대한 갈수있는데 까지 가보고 막히며 다시 다른 길을 찾는 방식이다
int main()
{
	stack<Location2D> locStack; // 위치 스택 객체 생성
	Location2D entry(1, 0); // 입구 객체
	locStack.push(entry); // 스택에 입구 위치 삽입

	while (locStack.empty() == false) // 스택이 비어있지 않는 동안
	{
		Location2D here = locStack.top(); // 스택에 상단 객체 복사
		locStack.pop(); // 스택에 상단 객체 삭제

		int r = here.row;
		int c = here.col;

		printf("(%d,%d) ", r, c); // 현재 위치를 화면에 출력
		if (map[r][c] == 'x') // 출구이면 탐색 성공
		{
			printf("  미로 탐색 성공\n");
			return 0;
		}
		else // 출구가 아니면
		{
			map[r][c] = '.'; // 현재 위치를 '지나옴' 처리
			if (isValidLoc(r - 1, c)) // 4 방향의 이웃 위치에 대해 갈 수 있는 위치이면 그 위치를 스택에 삽입함
				locStack.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c))
				locStack.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1))
				locStack.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1))
				locStack.push(Location2D(r, c + 1));
		}
	}

	printf("미로 탐색 실패\n"); // 스택이 공백 상태면 탐색이 실패함

	return 0;
}