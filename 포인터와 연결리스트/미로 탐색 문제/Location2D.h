#pragma once

class Location2D
{
public:
	int row;
	int col;

	Location2D(int r = 0, int c = 0)
	{
		row = r;
		col = c;
	}
	void display()
	{
		printf("<%d,%d> ", row, col);
	}

	// 위치 p가 자신의 이웃인지를 검사하는 함수 (상하좌우)
	bool isNeighbor(Location2D &p)
	{
		return ((row == p.row && (col == p.col - 1 || col == p.col + 1)) || (col == p.col && (row == p.row - 1 || row == p.row + 1)));
	}
};