#pragma once

#include <cstdio>

class BinaryNode
{
protected:
	int data;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode* link;

public:
	BinaryNode()
		:data(0), left(NULL), right(NULL), link(NULL)
	{

	}

	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		:data(val), left(l), right(r)
	{
		link = NULL;
	}

	void Setdata(int val) { data = val; }
	void SetLeft(BinaryNode* l) { left = l; }
	void SetRight(BinaryNode* r) { right = r; }

	int Getdata() { return data; }
	BinaryNode* GetLeft() { return left; }
	BinaryNode* GetRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }

	void SetLink(BinaryNode* l) { link = l; }
	BinaryNode* GetLink() { return link; }

	// 키 값으로 노드를 탐색하는 함수(순환적인 방법)
	// 노드 클래스의 멤버로 구현 (일반 함수가 아님)

	// 트리의 각 노드들은 모두 자신을 루트로 갖는 서브트리를 대표한다고 생각할 수 있다
	// 따라서 노드 클래스의 엠버 함수로 작성하는 것이 가능하다
	// 이 경우 매개변수가 하나 줄어드는 것에 유의한다
	BinaryNode* search(int key)
	{
		// 탐색 성공
		if (key == data)
			return this;
		// key < 현재노드의 data
		// key가 자신의 키 값보다 작으면 왼쪽 서브트리 탐색 // 이때 왼족 자식 노드가 있어야 호출할 수 있으므로 이를 검사한다
		else if (key < data&&left != NULL)
			return left->search(key);
		// key > 현재노드의 data
		// key가 자신의 키 값보다 크면 오른쪽 서브트리 탐색 // 이때 오른쪽 자식 노드가 있어야 호출 할 수 있으므로 이를 검사한다
		else if (key > data&&right != NULL)
			return right->search(key);
		// 찾는 노드 없음
		else
			return NULL;
	}
};