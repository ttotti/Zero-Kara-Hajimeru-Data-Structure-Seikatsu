#pragma once

#include "HeapNode.h"

#define MAX_ELEMENT 200

// 최소 힙 클래스
// 다른 프로젝트에서 만든 MaxHeap.h 에서 키 값을 비교하는 부분에서 부등호만 바꾸면 되고 나머지는 동일하다
class MinHeap
{
	// 요소의 배열
	HeapNode node[MAX_ELEMENT];
	// 힙의 현재 요소의 개수
	int size;

public:
	MinHeap()
		:size(0){}

	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i * 2]; }
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	// 삽입 함수
	void insert(int key)
	{
		if (isFull())
			return;

		int i = ++size;

		// i 가 루트가 아니고 key가 i의 부모 노드보다 작으면
		while (i != 1 && key < getParent(i).getKey())
		{
			node[i] = getParent(i);
			i /= 2;
		}

		node[i].setKey(key);
	}

	// 삭제 함수
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
			// 현재 노드의 자식 노드 중 더 작은 자식 노드를 찾음, 최종적으로 child는 더 작은 자식 노드의 인덱스가 됨
			if (child < size && getLeft(parent).getKey() > getRight(parent).getKey())
			{
				child++;
			}

			// 마지막 노드가 더 큰 자식보다 작으면 이동이 완료됨, 루프를 빠져나감
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