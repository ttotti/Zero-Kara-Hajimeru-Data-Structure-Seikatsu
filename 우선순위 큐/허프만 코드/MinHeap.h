#pragma once

#include "HeapNode.h"

#define MAX_ELEMENT 200

// �ּ� �� Ŭ����
// �ٸ� ������Ʈ���� ���� MaxHeap.h ���� Ű ���� ���ϴ� �κп��� �ε�ȣ�� �ٲٸ� �ǰ� �������� �����ϴ�
class MinHeap
{
	// ����� �迭
	HeapNode node[MAX_ELEMENT];
	// ���� ���� ����� ����
	int size;

public:
	MinHeap()
		:size(0){}

	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i * 2]; }
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	// ���� �Լ�
	void insert(int key)
	{
		if (isFull())
			return;

		int i = ++size;

		// i �� ��Ʈ�� �ƴϰ� key�� i�� �θ� ��庸�� ������
		while (i != 1 && key < getParent(i).getKey())
		{
			node[i] = getParent(i);
			i /= 2;
		}

		node[i].setKey(key);
	}

	// ���� �Լ�
	HeapNode remove()
	{
		if (isEmpty())
			return NULL;

		HeapNode root = node[1];
		HeapNode last = node[size--];

		int parent = 1;
		int child = 2;

		while (child <= size)
		{
			// ���� ����� �ڽ� ��� �� �� ���� �ڽ� ��带 ã��, ���������� child�� �� ���� �ڽ� ����� �ε����� ��
			if (child < size && getLeft(parent).getKey() > getRight(parent).getKey())
			{
				child++;
			}

			// ������ ��尡 �� ū �ڽĺ��� ������ �̵��� �Ϸ��, ������ ��������
			if (last.getKey() <= node[child].getKey())
				break;

			node[parent] = node[child];
			parent = child;
			child *= 2;
		}

		node[parent] = last;
		return root;
	}
};