#pragma once

// 덱은 전단과 후단으로 요소의 삽입, 삭제가 가능한데
// Db1LinkedLinst 클래스의 멤버 함수를 간단히 호출해주기만 하면 된다
// 상속을 사용하여 이중 연결 리스트를 이용한 덱 클래스를 매우 간단하게 만들 수 있다

#include "Db1LinkedList.h"

class LinkedDeque :public Db1LinkedList
{
public:
	void addFront(Node2* n) { insert(0, n); }
	Node2* deleteFront() { return remove(0); }
	Node2* getFront() { return getEntry(0); }

	void addRear(Node2* n) { insert(size(), n); }
	Node2* deleteRear() { return remove(size() - 1); }
	Node2* gerRear() { return getEntry(size() - 1); }
};