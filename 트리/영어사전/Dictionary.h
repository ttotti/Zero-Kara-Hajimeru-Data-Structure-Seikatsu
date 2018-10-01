#pragma once

// 최종적인 사전 클래스인 Dictionary는 BinSrchTree를 상속하여 구현하였다
#include "BinSrchTree.h"

class Dictionary :public BinSrehTree
{
public:
	// 사전의 전체 내용을 출력하는 printfAllWords() 연산은 inorder로 순회하여 각 노드의 단어와 의미를 출력한다
	// 결과적으로 모든 단어들은 사전적 순서로 정렬되어 출력된다
	void printAllwords()
	{
		printf("    >> 나의 단어장:\n");
		if (!isEmpty())
			inorder(root);
	}
	// 검색 연산
	// searchword()는 키 값을 이용한 탐색인 BinSrchTree::search()와 같은 방법으로 검색한다
	// 그러나 의미에 의한 검색 연산인 searchMeaning()은 다른 방법으로 검색해야 한다
	// 사전은 단어를 키 값으로 정렬된 이진 탐색 트리이고 "의미"에 의해서는 정렬되어 있지 않다
	// 따라서 어떤 "의미"를 갖는 노드를 검색하기 위해서는 일반적인 트리의 순회 알고리즘을 사용해야 한다
	void searchword(char* word)
	{
		BinaryNode* node = search(word);
		if (node != NULL)
		{
			printf("    >> ");
			node->display();
		}
		else
			printf("    >> 등록되지 않은 단어: %s\n", word);
	}

	void searchMeaning(char* m)
	{
		BinaryNode* node = (isEmpty()) ? NULL : searchByMeaning(root, m);
		if (node != NULL)
		{
			printf("    >> ");
			node->display();
		}
		else
			printf("    >> 등록되지 않은 의미: %s\n", m);
	}
	BinaryNode* searchByMeaning(BinaryNode* node, char* m)
	{
		if (node == NULL || node->compareMeaning(m) == 0)
			return node;
		BinaryNode* theNode = searchByMeaning(node->getLeft(), m);
		if (theNode != NULL)
			return theNode;

		return searchByMeaning(node->getRight(), m);
	}
};