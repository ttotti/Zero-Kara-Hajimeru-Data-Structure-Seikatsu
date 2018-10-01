#pragma once

#include "BinSrchTree.h"

// 맵은 이진 탐색 트리로도 구현할 수 있다
// 이진 탐색과 이진 탐색 트리는 근본적으로 같은 원리에 의한 탐색 구조로 탐색에 걸리는 시간도 O(log2 n) 로 동일하다
// 이 둘의 차이는 자료의 삽입과 삭제의 용의성에 있다

// 이진 탐색에서 자료는 배열에 저장되어 있으므로 삽입과 삭제가 상당히 힘들다
// 즉, 맵에 자료를 삽입하거나 삭제할 때 불필요한 항목들의 많은 이동이 필요하다

// 반면에 맵을 이진 탐색 트리로 구현하면 O(log2 n) 시간에 삽입과 삭제가 가능하다
// 따라서 삽입과 삭제가 빈번히 이루어진다면 반드시 이진 탐색 트리를 사용하여야 한다

// 이진 탐색 트리는 만약 균형 트리이면 O(log2 n)의 탐색 연산 시간 복잡도를 갖는다
// 그러나 균형 트리가 아닌 경사 트리일 경우에는 탐색의 시간 복잡도가 O(n) 으로 높아지게 된다

// 따라서 이진 탐색 트리에서는 균형을 유지하는 것이 무엇보다 중요하다
// 여기서는 이진 탐색 트리가 스스로 균형을 유지하도록 하는 방법에 대해 살펴본다
// 이들은 상당히 복잡하기 때문에 모든 주제를 다루지는 않고 AVL 트리에 대해서만 알아본다

// AVL 트리란
// AVL 트리는 Adelson-Velskii 와 Landis 에 의해 제안된 트리로
// 각 노드에서 왼쪽 서브트리의 높이와 오른쪽 서브트리의 높이 차이가 1 이하인 이진 탐색 트리를 말한다
// 이 트리는 트리가 비균형 상태로 되면 스스로 노드들을 재배치하여 균형 상태로 만든다
// AVL 트리는 항상 균형 트리를 보장하기 때문에 O(log2 n) 의 탐색 시간을 보장한다, 삽입과 삭제연산도 O(log2 n) 시간안에 할 수 있다

// AVL 트리에서 균형이 깨지는 경우는 다음 4가지의 타입이 있다
// 새로 삽입된 노드 N로 부터 가장 가까우면서 균형 인수가 +-2가 된 조상 노드를 A라고 하자
/*
	1. LL 타입 - N이 A의 왼쪽 서브트리의 왼쪽 서브트리에 삽입된다
	2. LR 타입 - N이 A의 왼쪽 서브트리의 오른쪽 서브트리에 삽입된다
	3. RR 타입 - N이 A의 오른쪽 서브트리의 오른쪽 서브트리에 삽입된다
	3. RL 타입 - N이 A의 오른쪽 서브트리의 왼쪽 서브트리에 삽입된다
*/

// LL과 RR은 대칭이고 역시 LR과 RL도 대칭이다
// 이제 트리를 다시 균형시킨다, 다음은 각각의 경우에 대하여 균형 트리로 다시 만드는 방법이다
/*
	1. LL 회전 - A부터 N까지의 경로상의 노드들은 오른쪽으로 회전시킨다
	2. LR 회전 - A부터 N까지의 경로상의 노드들을 왼쪽 - 오른쪽으로 회전시킨다
	3. RR 회전 - A부터 N까지의 경로상의 노드들을 왼쪽으로 회전시킨다
	4. RL 회전 - A부터 N까지의 경로상의 노드들을 오른쪽 - 왼쪽으로 회전시킨다
*/

// 한번만 회전시키는 것을 단순 회전(single rotation) 이라고 하는데 LL 회전, RR 회전이 여기에 속한다
// 이 경우, 탐색 순서를 유지하면서 부모와 자식의 위치를 교환하면 된다

// 두 번의 회전이 필요한 것을 이중 회전(double rotation) 이라고 하며 LR 회전, RL 회전이 여기에 속한다
// 마찬가지로 LL 회전과 RR 회전은 방향만 반대이고 대칭이며 LR 회전과 RL 회전도 마찬가지이다

class AVLTree :public BinSrchTree
{
public:
	int getHeightDiff(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		int hLeft = getHeight(node->GetLeft());
		int hRight = getHeight(node->GetRight());

		return hLeft - hRight;
	}

	// LL 회전
	BinaryNode* rotateLL(BinaryNode* parent)
	{
		BinaryNode* child = parent->GetLeft();

		parent->SetLeft(child->GetRight());
		child->SetRight(parent);

		return child;
	}

	// RR 회전
	BinaryNode* rotateRR(BinaryNode* parent)
	{
		BinaryNode* child = parent->GetRight();

		parent->SetRight(child->GetLeft());
		child->SetLeft(parent);

		return child;
	}

	// RL 회전
	BinaryNode* rotateRL(BinaryNode* parent)
	{
		BinaryNode* child = parent->GetRight();

		parent->SetRight(rotateLL(child));

		return rotateRR(parent);
	}

	// LR 회전
	BinaryNode* rotateLR(BinaryNode* parent)
	{
		BinaryNode* child = parent->GetLeft();

		parent->SetLeft(rotateRR(child));

		return rotateLL(parent);
	}

	BinaryNode* reBalance(BinaryNode* parent)
	{
		int hDiff = getHeightDiff(parent);

		if (hDiff > 1)
		{
			if (getHeightDiff(parent->GetLeft()) > 0)
				parent = rotateLL(parent);
			else
				parent = rotateLR(parent);
		}
		else if (hDiff < -1)
		{
			if (getHeightDiff(parent->GetRight()) < 0)
				parent = rotateRR(parent);
			else
				parent = rotateRL(parent);
		}

		return parent;
	}

	// 
	BinaryNode* insertAVL(BinaryNode* parent, int data)
	{
		if (data < parent->Getdata())
		{
			if (parent->GetLeft() != NULL)
				parent->SetLeft(insertAVL(parent->GetLeft(), data));
			else
				parent->SetLeft(new BinaryNode(data));

			return reBalance(parent);
		}
		else if (data > parent->Getdata())
		{
			if (parent->GetRight() != NULL)
				parent->SetRight(insertAVL(parent->GetRight(), data));
			else
				parent->SetRight(new BinaryNode(data));

			return reBalance(parent);
		}
		else
		{
			printf("중복된 키 에러\n");
			return NULL;
		}
	}

	void insert(int data)
	{
		if (isEmpty())
			root = new BinaryNode(data);
		else
			root = insertAVL(root, data);
	}
};