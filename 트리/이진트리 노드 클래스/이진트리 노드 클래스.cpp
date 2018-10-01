#include "BinaryTree.h"
#include <cstdio>

// 트리를 만들기 위해 자식 노드들을 일일이 지정해 주고 있는 것에 유의
// 만들어진 트리의 현재 상태를 알아보기 위한 출력 함수도 호출하지 않았다 
// 선형 자료형과는 달리 트리의 내용을 보기 좋게 화면에 출력하는 것은 간단하지가 않다
// 이 프로그램에서는 동적으로 생성된 메모리를 해제하는 부분도 누락되었다
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


	// 루트
	BinaryNode* a = new BinaryNode('A', b, c);

	tree.setRoot(a);

	tree.inorder();
	tree.preorder();
	tree.postorder();

	tree.levelorder();

	printf("\n  노드의 개수 : %d", tree.getCount());
	printf("\n  단말 노드의 개수 : %d", tree.getLeafCount());
	printf("\n  트리의 높이 : %d", tree.getHeight());

	printf("\n");

	return 0;
}