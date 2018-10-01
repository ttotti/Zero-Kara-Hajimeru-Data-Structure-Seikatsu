#include "Dictionary.h"
#include <conio.h>
#include <stdio.h>

void help()
{
	printf("[사용법] i-추가 d-삭제 w-단어검색 m-의미검색 p-출력 q-종료 =>");
}

// 사용법을 화면에 출력하고 키보드 입력을 기다린다
// 일반적으로 키보드로 하나의 문자를 입력받을 때 키보드를 치는 순간 동작이 되지 않고 엔터키를 쳐야 동작이 되는데
// getche() 함수는 키보드를 치는 것을 감지하여 엔터키 없이 바로 한 키보드 문자를 입력받는다
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
			printf("  > 삽입 단어: ");
			gets_s(word);
			printf("  > 단어 설명: ");
			gets_s(meaning);
			tree.insert(new BinaryNode(word, meaning));
			break;

		case 'd':
			printf("  > 삭제 단어: ");
			gets_s(word);
			tree.remove(word);
			break;

		case 'p':
			tree.printAllwords();
			printf("\n");
			break;

		case 'w':
			printf("  > 검색 단어: ");
			gets_s(word);
			tree.searchword(word);
			break;

		case 'm':
			printf("  > 검색 의미: ");
			gets_s(word);
			tree.searchMeaning(word);
			break;
		}
	} while (command != 'q');
}