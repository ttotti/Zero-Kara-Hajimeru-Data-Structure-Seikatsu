#include "BinaryTree.h"
#include <cstdio>

// Ʈ���� ����� ���� �ڽ� ������ ������ ������ �ְ� �ִ� �Ϳ� ����
// ������� Ʈ���� ���� ���¸� �˾ƺ��� ���� ��� �Լ��� ȣ������ �ʾҴ� 
// ���� �ڷ������� �޸� Ʈ���� ������ ���� ���� ȭ�鿡 ����ϴ� ���� ���������� �ʴ�
// �� ���α׷������� �������� ������ �޸𸮸� �����ϴ� �κе� �����Ǿ���
int main()
{
	BinaryTree tree;
	BinaryNode* e = new BinaryNode('E', NULL, NULL);
	BinaryNode* d = new BinaryNode('D', e, NULL);
	BinaryNode* b = new BinaryNode('B', d, NULL);

	BinaryNode* g = new BinaryNode('G', NULL, NULL);
	BinaryNode* h = new BinaryNode('H', NULL, NULL);
	BinaryNode* f = new BinaryNode('F', g, h);
	BinaryNode* c = new BinaryNode('C', f, NULL);


	// ��Ʈ
	BinaryNode* a = new BinaryNode('A', b, c);

	tree.setRoot(a);

	tree.inorder();
	tree.preorder();
	tree.postorder();

	tree.levelorder();

	printf("\n  ����� ���� : %d", tree.getCount());
	printf("\n  �ܸ� ����� ���� : %d", tree.getLeafCount());
	printf("\n  Ʈ���� ���� : %d", tree.getHeight());

	printf("\n");

	return 0;
}