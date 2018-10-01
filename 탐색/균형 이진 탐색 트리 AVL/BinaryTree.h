#pragma once

#include "BinaryNode.h"
#include "Queue.h"

// 이진트리 클래스 선언
class BinaryTree
{
protected:
	// 데이터 멤버로는 루트 노드에 대한 포인터만 있으면 됨
	BinaryNode* root;

public:
	// 생성자 // 새로운 트리 생성 시 루트는 NULL이 되어야 함
	BinaryTree()
		:root(NULL) {}

	~BinaryTree()
	{
		deleteNode(root);
	}

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* GetRoot() { return root; }

	// root가 NULL이면 공백 트리임
	bool isEmpty() { return root == NULL; }

	// 이진트리의 순회 연산과 각종 추가 연산

	// 중위 순회
	void inorder() { printf("\n     inorder: "); inorder(root); }
	void inorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			// 왼쪽 서브트리 처리
			if (node->GetLeft() != NULL)
				inorder(node->GetLeft());

			// 현재 노드 처리
			printf("  [%d]  ", node->Getdata());

			// 오른쪽 서브트리 순회
			if (node->GetRight() != NULL)
				inorder(node->GetRight());
		}
	}

	// 노드 클래스에 순회 함수를 구현한 경우 트리 클래스에는 순회 함수가 필요없으므로
	// 다음과 같이 노드에서 순회 함수를 호출하도록 한다
	//void inorder()
	//{
	//	printf("\n     inorder: ");
	//	if (!isEmpty()) root->inorder();
	//}

	// 전위 순회
	void preorder() { printf("\n    preorder: "); preorder(root); }
	void preorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			printf("  [%d]  ", node->Getdata());

			if (node->GetLeft() != NULL)
				preorder(node->GetLeft());

			if (node->GetRight() != NULL)
				preorder(node->GetRight());
		}
	}

	// 후위 순회
	void postorder() { printf("\n   postorder: "), postorder(root); }
	void postorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			if (node->GetLeft() != NULL)
				postorder(node->GetLeft());

			if (node->GetRight() != NULL)
				postorder(node->GetRight());

			printf("  [%d]  ", node->Getdata());
		}
	}

	// 후위 순회를 사용하여 맨 아래노드부터 차례로 해제한다
	void deleteNode(BinaryNode* node)
	{
		if (node != NULL)
		{
			if (node->GetLeft() != NULL)
				deleteNode(node->GetLeft());

			if (node->GetRight() != NULL)
				deleteNode(node->GetRight());

			printf("[해제] \n");
			delete node;
		}
	}

	void levelorder()
	{
		printf("\n  levelorder: ");

		if (!isEmpty())
		{
			Queue q;

			q.enqueue(root);

			while (!q.isEmpty())
			{
				BinaryNode* n = q.dequeue();
				n->SetLink(NULL);

				if (n != NULL)
				{
					printf("  [%d]  ", n->Getdata());

					if (n->GetLeft() != NULL)
						q.enqueue(n->GetLeft());

					if (n->GetRight() != NULL)
						q.enqueue(n->GetRight());
				}
			}
		}

		printf("\n");
	}

	// 트리의 노드 개수 구하기
	int getCount() { return isEmpty() ? 0 : getCount(root); }
	// 순환 호출에 의해 node를 루트로 하는 서브트리의 노드 수 계산 함수
	int getCount(BinaryNode* node)
	{
		// 공백 트리이면 0을 반환하고
		if (node == NULL)
			return 0;

		// 기본적으로 노드의 개수를 세기 위해서는 트리 안의 노드들을 전체적으로 순회하여야 한다
		// 트리의 노드의 개수는 왼쪽 서브트리의 노드 개수와 오른쪽 서브트리의 노드 개수에 루트 노드를 더하면 된다
		// 서브트리의 노드 개수는 순환 호출로 계산한다
		return 1 + getCount(node->GetLeft()) + getCount(node->GetRight());
	}

	// 단말 노드 개수 구하기
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	// 순환 호출에 의해 node를 루트로 하는 서브트리의 단말 노드 수 계산 함수
	int getLeafCount(BinaryNode* node)
	{
		// 공백 트리이면 0을 반환하고
		if (node == NULL)
			return 0;
		// 단말 트리이면 1을 반환함
		// isLeft() : 현재 노드가 단말 노드인지를 검사하는 함수 (BinaryNode.h 38줄)
		if (node->isLeaf())
			return 1;
		else
			return getLeafCount(node->GetLeft()) + getLeafCount(node->GetRight());
	}

	// 트리의 높이 구하기
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	// 트리의 높이는 왼쪽 서브트리와 오른쪽 서브트리 중에서 더 높은 트리를 먼저 찾는다
	int getHeight(BinaryNode* node)
	{
		// 공백 트리이면 0을 반환하고
		if (node == NULL)
			return 0;

		int hLeft = getHeight(node->GetLeft());
		int hRight = getHeight(node->GetRight());

		// hLeft와 hRight 중에서 큰 값을 선택하고 1을 더한 값을 반환한다
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
};