#pragma once

#include <cstdio>

// ���� ���� ����Ʈ ��带 ��Ÿ���� ���� Ŭ����
class Node2
{
	Node2* prev; // ���� ��带 ����Ű�� ������ ����
	Node2* next; // �ļ� ��带 ����Ű�� ������ ����
	int data; // ������ �ʵ�

public:
	Node2(int val = 0)
		:data(val), prev(NULL), next(NULL) {}

	Node2* getPrev() { return prev; }
	Node2* getNext() { return next; }
	void setPrev(Node2* p) { prev = p; }
	void setNext(Node2* n) { next = n; }
	void display() { printf(" <%2d>", data); }

	bool hasData(int val) { return data == val; }

	// �ڽ��� ������ ���ο� ��� n�� �����ϴ� �Լ�
	// � ���(���� ���) ������ ���ο� ��� N�� �߰��Ϸ��� �Ѵ� �̸� ���� �� �ܰ� ó���� �ʿ��ϴ�(���ͳ�, å 242p �׸� ����)
	void insertNext(Node2* n)
	{
		if (n != NULL)
		{
			// N�� ���� ��带 ���� ���� ����
			n->prev = this;

			// N�� �ļ� ��带 ���� ����� �ļ� ��� ����
			n->next = next;

			// ���� ����� �ļ� ����� ���� ��带 N���� ���� (���� ����� �ļ� ���� ������ִ� �ּҰ� ���� ���)
			if (next != NULL) 
				next->prev = n;

			// ���� ����� �ļ� ��带 N���� ����
			next = n;
		}
	}
	
	// ���� ��带 ���� ����Ʈ���� �����ϴ� �Լ�
	// ���� ���� ����Ʈ�� ��� ���� �ڽ��� ���� ��带 �� �� �ִ�
	// ���� ���� �Լ��� removeNext()�� ���� �� �ʿ䰡 ����
	// �ڽ�(���� ���) ��ü�� ����Ʈ���� ������ �� �ֱ� �����̴�
	// ���� �Լ��� �̸��� remove()�� �����Ѵ�
	// (���ͳ�, å243p �׸� ����)
	Node2* remove()
	{
		// ������ ����� �����带 ������ ����� �ļӳ�忡 �������ش�
		if (prev != NULL) prev->next = next;
		// ������ ����� �ļӳ�带 ������ ����� �����忡 �������ش�
		if (next != NULL) next->prev = prev;
		// �����ϴ� �ڱ� �ּ� ��ȯ
		return this;
	}
};