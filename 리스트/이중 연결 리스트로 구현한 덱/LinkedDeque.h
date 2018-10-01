#pragma once

// ���� ���ܰ� �Ĵ����� ����� ����, ������ �����ѵ�
// Db1LinkedLinst Ŭ������ ��� �Լ��� ������ ȣ�����ֱ⸸ �ϸ� �ȴ�
// ����� ����Ͽ� ���� ���� ����Ʈ�� �̿��� �� Ŭ������ �ſ� �����ϰ� ���� �� �ִ�

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