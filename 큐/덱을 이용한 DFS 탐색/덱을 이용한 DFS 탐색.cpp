#include <deque>
#include <iostream>
#include "Location2D.h"

using namespace std;

const int MAZE_SIZE = 6; // �̷� �� ũ�� ����

char map[MAZE_SIZE][MAZE_SIZE] = { // �̷� �� ������
	{ '1','1','1','1','1','1' },
	{ 'e','0','1','0','0','1' },
	{ '1','0','0','0','1','1' },
	{ '1','0','1','0','1','1' },
	{ '1','0','1','0','0','x' },
	{ '1','1','1','1','1','1' },
};

// (r,c)�� �� �� �ִ� ��ġ������ �˻��ϴ� �Լ�
// (r,c)�� �迭 �ȿ� �ְ�, ���� �� �� �ִ� ��ġ '0' �̰ų� 'x' �̾�� ��
bool isValidLoc(int r, int c)
{
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) // ��ġ ��(r,c)�� 0���� �۰ų� ���� �ִ� ũ�� ���� ũ�� �� �� ����
		return false;
	else
		return map[r][c] == '0' || map[r][c] == 'x';
}

// ���� �̿��� DFS Ž��
// ���� ��� ������ ���� push_front(), push_rear() �Լ��� �ְ� ������ ���� pop_front(), pop_rear() �� �ִ�
// ���ܰ� �Ĵ� ��ü�� �о���� ���� front() �� rear() �Լ��� �̿��Ѵ�
int main()
{
	deque<Location2D> locDeque;
	Location2D entry(1, 0);
	locDeque.push_front(entry);

	while (locDeque.empty() == false)
	{
		Location2D here = locDeque.front();
		locDeque.pop_front();

		int r = here.row;
		int c = here.col;
		
		printf("(%d,%d) ", r, c);

		if (map[r][c] == 'x')
		{
			printf("�̷� Ž�� ����\n");
			return 0;
		}
		else
		{
			map[r][c] = '.'; // ���� ��ġ�� ������ ǥ��

			if (isValidLoc(r - 1, c))
				locDeque.push_front(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c))
				locDeque.push_front(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1))
				locDeque.push_front(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1))
				locDeque.push_front(Location2D(r, c + 1));
		}
	}

	printf("�̷� Ž�� ����\n");

	return 0;
}