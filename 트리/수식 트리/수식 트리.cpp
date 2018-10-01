#include "BinaryTree.h"

int main()
{
	BinaryTree tree;

	// 현재 트리 구조
	//         +
	//     *       -
	//   3   2   5   6

	BinaryNode* n1 = new BinaryNode(3, NULL, NULL);
	BinaryNode* n2 = new BinaryNode(2, NULL, NULL);
	BinaryNode* n3 = new BinaryNode('*', n1, n2);

	BinaryNode* n4 = new BinaryNode(5, NULL, NULL);
	BinaryNode* n5 = new BinaryNode(6, NULL, NULL);
	BinaryNode* n6 = new BinaryNode('-', n4, n5);

	BinaryNode* n7 = new BinaryNode('+', n3, n6);

	tree.setroot(n7);

	printf("계산 결과 : %d\n", tree.evaluate());

	return 0;
}