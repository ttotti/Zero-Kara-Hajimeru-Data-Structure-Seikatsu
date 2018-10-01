#pragma once

#include <cstdio>
#include <cstdlib>
#include "Location2D.h"
#include "LinkedStack.h"

class Maze
{
private:
	int width; // �̷��� �ʺ�
	int height; // �̷��� ����
	int** map; // �̷� ��

public:
	int i = 0;
	Maze() { init(0, 0); }
	~Maze() { reset(); }
	
	// map ������ �迭�� �������� �Ҵ�
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

	// �̷� �� maze�� �������� ����
	void reset()
	{
		for (int i = 0; i < height; i++)
		{
			delete[] map[i];
		}

		delete[] map;
	}

	// ���Ͽ��� �̷� ������ �о��
	void load(char* fname)
	{
		// �־��� ������ �о��
		FILE *fp = fopen(fname, "r");

		int ch;

		if (fp == NULL)
		{
			printf("������ �������� �ʽ��ϴ�\n");
			exit(0);
		}

		int w = -1, h = 0;

		// ��Ʈ������ ���� ��(end-of-file)�� �׽�Ʈ �Դϴ�
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
					// ������ �о ũ�⸦ ���� ��
					// �� ũ��� 2���� �迭 map�� �����Ҵ��Ѵ�
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

	// ���� Maze�� ȭ�鿡 ���
	void print()
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (map[i][j] == 0)
				{
					printf("��");
				}
				else if (map[i][j] == 2)
				{
					printf("��");
				}
				else if (map[i][j] == 9)
				{
					printf("��");
				}
				else
				{
					printf("  ");
				}
			}
			printf("\n");
		}
	}

	// ���� �̷θ� Ž���ϴ� �Լ�
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
				printf("\nŻ�⼺��!");
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
			printf("���� �����ϴ٤�\n");
		}
	}
};