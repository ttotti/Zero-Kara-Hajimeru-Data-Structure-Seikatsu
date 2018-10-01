#include "Dictionary.h"
#include <conio.h>
#include <stdio.h>

void help()
{
	printf("[����] i-�߰� d-���� w-�ܾ�˻� m-�ǹ̰˻� p-��� q-���� =>");
}

// ������ ȭ�鿡 ����ϰ� Ű���� �Է��� ��ٸ���
// �Ϲ������� Ű����� �ϳ��� ���ڸ� �Է¹��� �� Ű���带 ġ�� ���� ������ ���� �ʰ� ����Ű�� �ľ� ������ �Ǵµ�
// getche() �Լ��� Ű���带 ġ�� ���� �����Ͽ� ����Ű ���� �ٷ� �� Ű���� ���ڸ� �Է¹޴´�
int main()
{
	char command;
	char word[80];
	char meaning[200];
	Dictionary tree;

	do 
	{
		help();
		command = _getche();
		printf("\n");
		switch (command)
		{
		case 'i':
			printf("  > ���� �ܾ�: ");
			gets_s(word);
			printf("  > �ܾ� ����: ");
			gets_s(meaning);
			tree.insert(new BinaryNode(word, meaning));
			break;

		case 'd':
			printf("  > ���� �ܾ�: ");
			gets_s(word);
			tree.remove(word);
			break;

		case 'p':
			tree.printAllwords();
			printf("\n");
			break;

		case 'w':
			printf("  > �˻� �ܾ�: ");
			gets_s(word);
			tree.searchword(word);
			break;

		case 'm':
			printf("  > �˻� �ǹ�: ");
			gets_s(word);
			tree.searchMeaning(word);
			break;
		}
	} while (command != 'q');
}