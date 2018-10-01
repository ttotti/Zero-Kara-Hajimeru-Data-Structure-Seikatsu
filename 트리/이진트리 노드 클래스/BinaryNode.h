#pragma once
#include <cstdio>

// 이진노드 클래스 선언
class BinaryNode
{
	// 상속을 고려해 데이터 멤버들을 protected로 선언
protected:
	// 노드에 저장할 데이터, 단순화를 위해 int를 저장하도록 한다 (템플릿을 사용하면 코드를 수정할 필요없이 다양한 타입의 데이터를 저장할 수 있다)
	int data;
	// 왼쪽 자식과 오른쪽 자식에 대한 포인터 변수
	BinaryNode* left;
	BinaryNode* right;

	// 큐에서 사용할 노드를 이어줄 링크
	BinaryNode* link;

public:
	// 생성자 // 디폴트 매개변수를 사용하였으며 멤버 초기화 리스트를 이용해서 데이터 멤버를 초기화하였음
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		:data(val), left(l), right(r)
	{
		link = NULL;
	}

	~BinaryNode()
	{

	}
	
	// 데이터 멤버를 설정하는 함수
	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	// 데이터 멤버를 반환하는 함수
	int getData() { return data; }
	BinaryNode* getLeft() { return left;}
	BinaryNode* getRight() { return right; }

	// 현재 노드가 단말 노드인지를 검사하는 함수
	// 단말 노드가 되기 위해서는 왼쪽 자식과 오른쪽 자식이 모두 없어야 함
	bool isLeat() { return left == NULL && right == NULL; }

	// 현재 노드를 루트로 갖는 서브트리에서의 중위 순환
	// 객체지향언어인 C++ 에서는 객체에서 멤버 함수를 호출하는 방식을 사용하므로 순회 함수들도 노드 클래스의 멤버 함수로 구현할 수 있다
	// (단순 연결 리스트의 삽입과 삭제 연산을 추가하는 것과 동일한 연산)(책 p318)
	// 다음은 중위 순회를 트리 클래스가 아닌 노드 클래스에서 담당하도록 구현한 코드이다
	// 노드 클래스에 순회 함수를 구현한 경우 트리 클래스에 구현한 순회는 필요없게 된다

	// 이와 같이 노드 클래스에서 처리할 수 있는 연산들이 많은데 이것은 모든 노드를 그 노드를 루트로 하는 하나의 트리로 생각할 수 있기 때문이다
	void inorder()
	{
		if (left != NULL)
			left->inorder();

		printf("  [%c]  ", data);

		if (right != NULL)
			right->inorder();
	}

	// 큐에서 사용할 링크 접근자
	void setlink(BinaryNode* d) { link = d; }
	BinaryNode* getlink() { return link; }
};