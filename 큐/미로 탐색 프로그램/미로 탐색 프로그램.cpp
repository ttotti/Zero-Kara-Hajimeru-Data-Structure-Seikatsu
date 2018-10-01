#include <queue>
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

// ť�� �̿��� �̷�Ž��
// ť�� ����ϴ� ���� �ʺ� �켱 Ž��(BFS : Bread First Search)�������� Ž�� �������� ���̺��ٴ� ���� �켱���� ���Ѵ�
// �̰��� ������ �̿��� Ž������ �����ɷ����� �̷��� ������ ��� �Ǿ��ִ°��� ���� �ӵ��� ���� �� �ְ�
// Ž�������� ���� �޶����� �ִ� �������� ��-��-��-�� ������ Ž���� ������ ��-��-��-�¿� ���� Ž���ϸ� �����̳� ť�� ���� ������ �޶����� �׿� ���� �ӵ��� ���Ѵ�
int main()
{
	queue<Location2D> locQueue;
	Location2D entry(1, 0);
	locQueue.push(entry);

	while (locQueue.empty() == false) // ť�� ������� �ʴ� ����
	{
		Location2D here = locQueue.front(); // ť�� front ��� ��ü ����
		locQueue.pop(); // ť�� ��� ��ü ����

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
			map[r][c] = '.';
			if (isValidLoc(r - 1, c)) locQueue.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c)) locQueue.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1)) locQueue.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1)) locQueue.push(Location2D(r, c + 1));
		}
	}

	printf("�̷� Ž�� ����\n");

	return 0;
}