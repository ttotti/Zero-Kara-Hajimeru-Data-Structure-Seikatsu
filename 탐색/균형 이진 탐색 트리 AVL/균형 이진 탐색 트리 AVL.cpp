#include <cstdio>
#include "AVLTree.h"

int main()
{
	AVLTree tree;

	tree.insert(7);
	tree.levelorder();

	tree.insert(8);
	tree.levelorder();

	tree.insert(9);
	tree.levelorder();

	tree.insert(2);
	tree.levelorder();

	tree.insert(1);
	tree.levelorder();

	tree.insert(5);
	tree.levelorder();

	tree.insert(3);
	tree.levelorder();

	tree.insert(6);
	tree.levelorder();

	tree.insert(4);
	tree.levelorder();


	return 0;
}