#pragma once

// �������� ���� Ŭ������ Dictionary�� BinSrchTree�� ����Ͽ� �����Ͽ���
#include "BinSrchTree.h"

class Dictionary :public BinSrehTree
{
public:
	// ������ ��ü ������ ����ϴ� printfAllWords() ������ inorder�� ��ȸ�Ͽ� �� ����� �ܾ�� �ǹ̸� ����Ѵ�
	// ��������� ��� �ܾ���� ������ ������ ���ĵǾ� ��µȴ�
	void printAllwords()
	{
		printf("    >> ���� �ܾ���:\n");
		if (!isEmpty())
			inorder(root);
	}
	// �˻� ����
	// searchword()�� Ű ���� �̿��� Ž���� BinSrchTree::search()�� ���� ������� �˻��Ѵ�
	// �׷��� �ǹ̿� ���� �˻� ������ searchMeaning()�� �ٸ� ������� �˻��ؾ� �Ѵ�
	// ������ �ܾ Ű ������ ���ĵ� ���� Ž�� Ʈ���̰� "�ǹ�"�� ���ؼ��� ���ĵǾ� ���� �ʴ�
	// ���� � "�ǹ�"�� ���� ��带 �˻��ϱ� ���ؼ��� �Ϲ����� Ʈ���� ��ȸ �˰����� ����ؾ� �Ѵ�
	void searchword(char* word)
	{
		BinaryNode* node = search(word);
		if (node != NULL)
		{
			printf("    >> ");
			node->display();
		}
		else
			printf("    >> ��ϵ��� ���� �ܾ�: %s\n", word);
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
			printf("    >> ��ϵ��� ���� �ǹ�: %s\n", m);
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