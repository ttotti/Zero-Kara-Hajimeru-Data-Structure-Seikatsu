#pragma once

// �������� ���� ������ Ŭ���� LineEditor�� LinkedList�� ����Ͽ� �����
#include "LinkedList.h"

class LineEditor :public LinkedList
{
public:
	// ȭ�鿡 ���� ���� ���
	void Display(FILE* fp = stdout)
	{
		int i = 0;

		for (Node* p = getHead(); p != NULL; p = p->getLink(), i++)
		{
			// stderr ǥ�ؿ���
			// Windows������ stdout�� stdree�� �����ϴ� (�ڼ��Ѱ� ���ͳ��� �����Ѵ�)
			fprintf(stderr, "%3d: ", i);
			p->display(fp);
		}

		//while (getchar() != '\n');
	}

	// �� ���� �Է� ó��
	void InsertLine()
	{
		int position;
		char line[MAX_CHAR_PER_LINE];

		printf(" �Է��� ��ȣ: ");
		scanf("%d", &position);

		printf(" �Է��� ����: ");
		// ����Ű ó��
		//fflush(stdin); // �� �Լ��� �ᵵ \n(���๮��)�� �Ȼ������
		// �׷��� ǥ�� �Է� ���ۿ� �����Ͱ� ä������ ������ Ű������ '\n'(Enter) �� �ԷµǴ� ������ �����Ѵٸ�
		// ������ ���� ������� ���ۿ� �����ִ� �����͸� ���� �� �ִ�
		while (getchar() != '\n');
		scanf("%s", line);
		//fgets(line, MAX_CHAR_PER_LINE, stdin);

		insert(position, new Node(line));
	}

	// �� ���� ���� ó��
	void DeleteLine()
	{
		printf(" ������ ��ȣ: ");
		int position;
		scanf("%d", &position);

		delete remove(position);

		//while (getchar() != '\n');
	}

	// �� ���� ���� ó��
	void ReplaceLine()
	{
		int position;
		char line[MAX_CHAR_PER_LINE];

		printf(" ������ ��ȣ: ");
		scanf("%d", &position);

		printf(" ������ ����: ");
		// ����Ű ó��
		while (getchar() != '\n');
		//fflush(stdin);
		fgets(line, MAX_CHAR_PER_LINE, stdin);

		replace(position, new Node(line));
	}

	// ���� �ε�
	void LoadFile(const char* fname)
	{
		FILE* fp = fopen(fname, "r");

		if (fp != NULL)
		{
			char line[MAX_CHAR_PER_LINE];

			while (fgets(line, MAX_CHAR_PER_LINE, fp))
			{
				insert(size(), new Node(line));
			}
			printf("������ ���������� �о�Խ��ϴ�!\n");
			fclose(fp);
		}
	}

	// ���� ����
	void StoreFile(const char* fname)
	{
		FILE* fp = fopen(fname, "w");

		if (fp != NULL)
		{
			Display(fp);
			fclose(fp);
		}
	}
};