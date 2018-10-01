#pragma once

#include <cstdio>
#include <cstdlib>
#include "Location2D.h"
#include "LinkedStack.h"

class Maze
{
private:
	int width; // 미로의 너비
	int height; // 미로의 높이
	int** map; // 미로 맵

public:
	int i = 0;
	Maze() { init(0, 0); }
	~Maze() { reset(); }
	
	// map 이차원 배열을 동적으로 할당
	void init(int h, int w)
	{
		if (w <= 0 || h <= 0)
			map = NULL;

		map = new int*[h];

		for (int i = 0; i < h; i++)
		{
			map[i] = new int[w];
		}
	}

	// 미로 맵 maze를 동적으로 해제
	void reset()
	{
		for (int i = 0; i < height; i++)
		{
			delete[] map[i];
		}

		delete[] map;
	}

	// 파일에서 미로 파일을 읽어옴
	void load(char* fname)
	{
		// 주어진 파일을 읽어옴
		FILE *fp = fopen(fname, "r");

		int ch;

		if (fp == NULL)
		{
			printf("파일이 존재하지 않습니다\n");
			exit(0);
		}

		int w = -1, h = 0;

		// 스트림에서 파일 끝(end-of-file)을 테스트 함니다
		while (!feof(fp))
		{
			fscanf(fp, "%d", &ch);
			if (ch == 20 || ch == 10)
			{
				if (ch == 20)
					width = ch;
				else
				{
					height = ch;
					// 파일을 읽어서 크기를 구한 후
					// 그 크기로 2차원 배열 map을 동적할당한다
					init(height,width);
				}

				continue;
			}
			
			++w;
			if (w == width)
			{
				w = 0;
				h++;
			}
			map[h][w] = ch;
		}

		fclose(fp);
	}

	// 현재 Maze를 화면에 출력
	void print()
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (map[i][j] == 0)
				{
					printf("■");
				}
				else if (map[i][j] == 2)
				{
					printf("□");
				}
				else if (map[i][j] == 9)
				{
					printf("◎");
				}
				else
				{
					printf("  ");
				}
			}
			printf("\n");
		}
	}

	// 실제 미로를 탐색하는 함수
	void searchExit()
	{
		LinkedStack stack;
		//Location2D entry(2, 0);
		//stack.push(new Node(entry));
		stack.push(new Node(2, 0));

		while (!stack.isEmpty())
		{
			i += 1;
			Node* here = stack.pop();
			stack.display();
			if (map[here->row][here->col] == 9)
			{
				printf("\n탈출성공!");
				break;
			}
			map[here->row][here->col] = 2;

			if (map[here->row - 1][here->col] != 0 && here->row - 1 >= 0 && map[here->row - 1][here->col] != 2)
			{
				stack.push(new Node(here->row - 1, here->col));
				system("cls");
				print();
				stack.display();
			}
			if (map[here->row + 1][here->col] != 0 && here->row + 1 < height && map[here->row + 1][here->col] != 2)
			{
				stack.push(new Node(here->row + 1, here->col));
				system("cls");
				print();
				stack.display();
			}
			if (map[here->row][here->col - 1] != 0 && here->col - 1 >= 0 && map[here->row][here->col - 1] != 2)
			{
				stack.push(new Node(here->row, here->col - 1));
				system("cls");
				print();
				stack.display();
			}
			if (map[here->row][here->col + 1] != 0 && here->col + 1 < width && map[here->row][here->col + 1] != 2)
			{
				stack.push(new Node(here->row, here->col + 1));
				system("cls");
				print();
				stack.display();
			}
		}

		if (stack.isEmpty())
		{
			printf("길이 없습니다ㅠ\n");
		}
	}
};