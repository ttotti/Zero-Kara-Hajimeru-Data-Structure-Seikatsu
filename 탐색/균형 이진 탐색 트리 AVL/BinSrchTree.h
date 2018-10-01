#pragma once

// 이진 탐색 트리 클래스
#include "BinaryTree.h"

// 이진 탐색 트리는 이진트리의 일종이므로 이진트리를 상속하여 설계한다
class BinSrchTree :public BinaryTree
{
public:
	BinSrchTree(void){}
	~BinSrchTree(void){}

	// 이진 탐색 트리의 탐색 연산
	BinaryNode* search(int key)
	{
		BinaryNode* node = searchRecur(root, key);
		if (node != NULL)
			printf("탐색 성공: 키값이 %d인 노드 = 0x%x\n", node->Getdata(), node);
		else
			printf("탐색 실패: 키값이 %d인 노드 없음\n", key);

		return node;
	}

	// BinaryNode* search(BinaryNode* n,int key){}
	// 키 값으로 노드를 탐색하는 함수(순환적인 방법)
	// 일반 함수로 구현 가능, BinSrchTree의 멤버 함수로 넣어도 됨
	BinaryNode* searchRecur(BinaryNode* n, int key)
	{
		// n이 NULL
		if (n == NULL)
			return NULL;

		// key == 현재노드의 data
		if (key == n->Getdata())
			return n;
		// key < 현재노드의 data
		else if (key < n->Getdata())
			return searchRecur(n->GetLeft(), key);
		// key > 현재노드의 data
		else
			return searchRecur(n->GetRight(), key);
	}

	// 키 값으로 노드를 탐색하는 함수(반복적인 방법)
	// 일반 함수로 구현 가능, BinSrchTree의 멤버 함수로 넣어도 됨
	// n을 루트로 하는 서브트리에서 키 값이 key을 찾아 반환하는 함수
	BinaryNode* searchIter(BinaryNode* n, int key)
	{
		while (n != NULL)
		{
			if (key == n->Getdata())
				return n;
			else if (key < n->Getdata())
				return n = n->GetLeft();
			else
				return n = n->GetRight();
		}

		// 탐색에 실패한 경우 NULL 반환
		return NULL;
	}

	// 이진 탐색 트리의 삽입 연산
	void insert(BinaryNode* n)
	{
		if (n == NULL)
			return;
		// 공백 트리일 경우 첫번째로 삽입된 데이터가 루트가 된다
		if (isEmpty())
			root = n;
		else insertRecur(root, n);
	}

	// void insert(BinaryNode* r,BinaryNode* n){}
	// 이진 탐색 트리의 삽입 함수(순환적인 방법) // 삽입 연산도 탐색 연산과 마찬가지로 순환이 아닌 반복을 이용하여 구현이 가능하다
	// 일반 함수로 구현 가능 , BinSrchTree의 멤버 함수로 넣어도 됨

	// 이진 탐색 트리에 원소를 삽입하기 위해서는 먼저 탐색을 하여 같은 키 값을 갖는 노드가 없는지 확인하여야 하고
	// 탐색에 실패한 위치가 바로 새로운 노드를 삽입하는 위치가 되기 때문이다 

	// 노드 r을 루트로 하는 서브트리에 노드 n을 삽입하는 함수
	void insertRecur(BinaryNode* r, BinaryNode* n)
	{
		// 노드 n 키가 루트 노드의 r의 키 값과 같으면 중복된 노드가 이미 트리에 존재함 // 이 경우 삽입하지 않음
		if (n->Getdata() == r->Getdata())
			return;
		// 노드 n키가 루트 노드의 r의 키 값보다 작은 경우
		else if (n->Getdata() < r->Getdata())
		{
			// 왼쪽 자식 노드가 없으면 n이 r의 왼쪽 자식 노드가 됨
			if (r->GetLeft() == NULL)
				r->SetLeft(n);
			// 왼쪽 자식이 있으면 insert함수를 순환적으로 호출
			else
				insertRecur(r->GetLeft(), n);
		}
		// 노드 n키가 루트 노드의 r의 키 값보다 클 경우
		else
		{
			// 오른쪽 자식 노드가 없으면 n이 r의 오른쪽 자식 노드가 됨
			if (r->GetRight() == NULL)
				r->SetRight(n);
			// 오른쪽 자식이 있으면 insert함수를 순환적으로 호출
			else
				insertRecur(r->GetRight(), n);
		}
	}

	// 이진 탐색 트리의 삭제 연산
	void remove(int key)
	{
		if (isEmpty())
			return;

		BinaryNode* parent = NULL;
		BinaryNode* node = root;

		while (node != NULL && node->Getdata() != key)
		{
			parent = node;
			node = (key < node->Getdata()) ? node->GetLeft() : node->GetRight();
		}

		if (node == NULL)
		{
			printf(" Error: key is not in the tree\n");
			return;
		}
		else
			remove(parent, node);
	}
	void remove(BinaryNode* parent,BinaryNode* node)
	{
		// case 1: 삭제하려는 노드가 단말 노드일 경우
		if (node->isLeaf())
		{
			// node == root인경우 => 공백상태가 됨
			if (parent == NULL)
				root = NULL;
			// 아닌 경우 => parent의 해당 자식을 NULL
			else
			{
				if (parent->GetLeft() == node)
					parent->SetLeft(NULL);
				else
					parent->SetRight(NULL);
			}
		}
		// case 2: 삭제하려는 노드가 왼쪽이나 오른쪽 자식만 갖는 경우
		else if (node->GetLeft() == NULL || node->GetRight() == NULL)
		{
			// 삭제할 노드의 유일한 자식 노드 => child
			BinaryNode* child = (node->GetLeft() != NULL) ? node->GetLeft() : node->GetRight();

			// 삭제할 노드가 루트이면 => child가 새로운 root가 됨
			if (node == root)
				root = child;
			// 아니면 => 부모 노드의 자식으로 자식 노드 child를 직접 연결
			else
			{
				if (parent->GetLeft() == node)
					parent->SetLeft(child);
				else
					parent->SetRight(child);
			}
		}
		// case 3: 삭제하려는 노드가 두개의 자식이 모두 있는 경우
		else
		{
			// 삭제하려는 노드의 오른쪽 서브트리에서 가장 큰 노드를 탐색
			// succp => 후계 노드의 부모 노드
			// succ => 후계 노드: 오른쪽 서브트리에서 가장 key가 작은 노드
			BinaryNode* succp = node;
			BinaryNode* succ = node->GetRight();

			// 후계 노드 탐색
			while (succ->GetLeft() != NULL)
			{
				// 후계 노드의 부모 노드
				succp = succ;
				// 후계 노드
				succ = succ->GetLeft();
			}
			
			// 후계 노드의 부모와 후계 노드의 오른쪽 자식을 직접 연결
			if (succp->GetLeft() == succ)
				succp->SetLeft(succ->GetRight());
			// 후계 노드가 삭제할 노드의 바로 오른쪽 자식인 경우
			else
				succp->SetRight(succ->GetRight());

			// 후계 노드 정보를 삭제할 노드에 복사
			node->Setdata(succ->Getdata());

			// 삭제할 노드를 후계 노드로 변경 : 실제로는 후계 노드가 제거됨
			node = succ;
		}

		// 메모리 동적 해제
		delete node;
	}
};