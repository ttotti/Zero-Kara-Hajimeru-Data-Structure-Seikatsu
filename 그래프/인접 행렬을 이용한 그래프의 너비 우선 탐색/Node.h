#pragma once

// ���� ����Ʈ�� �̿��� �׷����� ���� ��� Ŭ����
#include <cstdio>

class Node
{
	// Ŭ������ ����� ����� ������ �ʵ带 protected�� ����
protected:
	// ������ id, ���� ������ �ε���
	int id;
	// ���� ����� ������, ���� ��带 ���� ������ ����
	Node* link;

public:
	// ������, ��� �ʱ�ȭ ����Ʈ ���, ��ũ�� ����Ʈ �Ű����� ���
	Node(int i, Node* l = NULL)
		:id(i), link(l) {}
	// �Ҹ���, �ϳ��� ��尡 �Ҹ�� �� ����� ��� ��带 �����ϵ��� ������
	~Node()
	{
		if (link != NULL)
			delete link;
	}

	// ������ �ʵ� ���� �Լ���
	int getId() { return id; }
	Node* getLink() { return link; }
	void setLink(Node* l) { link = l; }
};