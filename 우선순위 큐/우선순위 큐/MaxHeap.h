#pragma once

#include "HeapNode.h"

#define MAX_ELEMENT 200

// ���� ���� Ʈ���� �迭�� ����Ͽ� ���� ���·� ����� Ŭ����
class MaxHeap
{
	// ����� �迭
	HeapNode node[MAX_ELEMENT];
	// ���� ���� ����� ����
	int size;

public:
	MaxHeap()
		:size(0){}

	bool isEmpty() { return size == 0; }
	// MAX_ELEMENT - 1 �� �����Ұ�! - �迭�� 0�� ��Ҹ� ������� ����
	bool isFull() { return size == MAX_ELEMENT - 1; }

	// ���� ���� Ʈ������ ����� �ε��� ��ȣ�� �̿��� �θ�� �ڽ� ��带 ����ϴ� �Լ�
	// �θ� ���
	HeapNode& getParent(int i) { return node[i / 2]; }
	// ���� �ڽ� ���
	HeapNode& getLeft(int i) { return node[i * 2]; }
	// ������ �ڽ� ���
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	// ���� �Լ�: ���� Ű�� key�� ���� ���ο� ��Ҹ� �����Ѵ�
	void insert(int key)
	{
		// ���� ���� �� ���
		if (isFull())
			return;
		// ������ �� ũ�� ��ġ���� ����
		int i = ++size;

		// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
		// ��Ʈ�� �ƴϰ� �θ� ��庸�� Ű���� ũ��
		while (i != 1 && key > getParent(i).getKey())
		{
			// �θ� �ڽų��� �����
			node[i] = getParent(i);
			// �� ���� ���� ���
			i /= 2;
		}

		// ���� ��ġ�� ������ ����
		node[i].setKey(key);
	}
	// ���� �Լ�: ���� ��Ʈ ��带 ��ȯ�ϰ� ���� �籸���Ѵ�
	HeapNode remove()
	{
		if (isEmpty())
			return NULL;

		// ��Ʈ���(���� ���)
		// ���� ���꿡���� ��Ʈ ��带 ��ȯ�ϹǷ� ��Ʈ�� item�� �����Ѵ�
		// ���� �� ���´� ������������ ���ĵ� �����̹Ƿ� 1���� ������
		HeapNode item = node[1];
		// ���� ���������
		// ���� ������ ��Ҹ� last�� ����
		// �̹� ������ �� ũ�⿡�� 1�� �� ���� ������ ����̴�
		HeapNode last = node[size--];

		// parent�� ��Ʈ ��ġ�� child�� parent�� ���� �ڽ����� �ʱ�ȭ��
		// ������ ����� ��ġ�� ��Ʈ�� ������
		int parent = 1;
		// ��Ʈ�� ���� �ڽ� ��ġ
		int child = 2;

		// �� Ʈ���� ����� �ʴ� ����
		while (child <= size)
		{
			// ���� ����� �ڽ� ��� �� �� ū �ڽĳ�带 ã��
			// ���������� child�� ���� ū �ڽ� ����� �ε����� ��
			if (child < size && getLeft(parent).getKey() < getRight(parent).getKey())
			{
				// child: ���� ��庸�� ū �ڽ� ����� �ε���
				child++;
			}

			// ������ ��尡 �� ū �ڽĺ��� ũ�� ==> �̵� �Ϸ�
			if (last.getKey() >= node[child].getKey())
				break;

			// �ƴϸ� ==> �� �ܰ� �Ʒ��� �̵�
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}

		// ������ ��带 ���� ��ġ�� ����
		node[parent] = last;
		// ��Ʈ ��� ��ȯ
		return item;
	}

	// ��Ʈ ��带 ��ȯ��
	HeapNode find() { return node[1]; }

	// �� ���� ��� �Լ�
	// ���� ����Ʈ���� �����̹Ƿ� ���� ������ ������ �� �ٿ� �����
	void display()
	{
		for (int i = 1, level = 1; i <= size; i++)
		{
			if (i == level)
			{
				printf("\n");
				level *= 2;
			}

			node[i].display();
		}

		printf("\n----------------------------------------");
	}
};