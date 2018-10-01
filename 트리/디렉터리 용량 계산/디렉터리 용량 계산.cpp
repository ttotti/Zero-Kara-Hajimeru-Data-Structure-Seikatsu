#include "BinaryTree.h"

int main()
{
	BinaryTree Tree;

	BinaryNode* m4 = new BinaryNode(200, NULL, NULL);
	BinaryNode* m5 = new BinaryNode(500, NULL, NULL);
	BinaryNode* m3 = new BinaryNode(100, m4, m5);
	BinaryNode* m2 = new BinaryNode(50, NULL, NULL);
	BinaryNode* m1 = new BinaryNode(0, m2, m3);

	Tree.SetTree(m1);

	printf("ÃÑ ¿ë·® : %d KB\n", Tree.calcSize());

	return 0;
}