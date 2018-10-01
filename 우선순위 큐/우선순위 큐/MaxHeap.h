#pragma once

#include "HeapNode.h"

#define MAX_ELEMENT 200

// 완전 이진 트리를 배열을 사용하여 힙의 형태로 만드는 클래스
class MaxHeap
{
	// 요소의 배열
	HeapNode node[MAX_ELEMENT];
	// 힙의 현재 요소의 개수
	int size;

public:
	MaxHeap()
		:size(0){}

	bool isEmpty() { return size == 0; }
	// MAX_ELEMENT - 1 에 유의할것! - 배열의 0번 요소를 사용하지 않음
	bool isFull() { return size == MAX_ELEMENT - 1; }

	// 완전 이진 트리에서 노드의 인덱스 번호를 이용해 부모와 자식 노드를 계산하는 함수
	// 부모 노드
	HeapNode& getParent(int i) { return node[i / 2]; }
	// 왼쪽 자식 노드
	HeapNode& getLeft(int i) { return node[i * 2]; }
	// 오른쪽 자식 노드
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	// 삽입 함수: 힙에 키값 key를 갖는 새로운 요소를 삽입한다
	void insert(int key)
	{
		// 힙이 가득 찬 경우
		if (isFull())
			return;
		// 증가된 힙 크기 위치에서 시작
		int i = ++size;

		// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
		// 루트가 아니고 부모 노드보다 키값이 크면
		while (i != 1 && key > getParent(i).getKey())
		{
			// 부모를 자신노드로 끌어내림
			node[i] = getParent(i);
			// 한 레벨 위로 상승
			i /= 2;
		}

		// 최종 위치에 데이터 복사
		node[i].setKey(key);
	}
	// 삭제 함수: 힙의 루트 노드를 반환하고 힙을 재구성한다
	HeapNode remove()
	{
		if (isEmpty())
			return NULL;

		// 루트노드(꺼낼 요소)
		// 삭제 연산에서는 루트 노드를 반환하므로 루트를 item에 저장한다
		// 현재 힙 상태는 오름차순으로 정렬된 상태이므로 1번을 꺼낸다
		HeapNode item = node[1];
		// 힙의 마지막노드
		// 힙의 마지막 요소를 last에 복사
		// 이미 증가된 힙 크기에서 1을 뺀 곳이 마지막 요소이다
		HeapNode last = node[size--];

		// parent를 루트 위치로 child를 parent의 왼쪽 자식으로 초기화함
		// 마지막 노드의 위치를 루트로 생각함
		int parent = 1;
		// 루트의 왼쪽 자식 위치
		int child = 2;

		// 힙 트리를 벗어나지 않는 동안
		while (child <= size)
		{
			// 현재 노드의 자식 노드 중 더 큰 자식노드를 찾음
			// 최종적으로 child는 제일 큰 자식 노드의 인덱스가 됨
			if (child < size && getLeft(parent).getKey() < getRight(parent).getKey())
			{
				// child: 이전 노드보다 큰 자식 노드의 인덱스
				child++;
			}

			// 마지막 노드가 더 큰 자식보다 크면 ==> 이동 완료
			if (last.getKey() >= node[child].getKey())
				break;

			// 아니면 ==> 한 단계 아래로 이동
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}

		// 마지막 노드를 최종 위치에 저장
		node[parent] = last;
		// 루트 노드 반환
		return item;
	}

	// 루트 노드를 반환함
	HeapNode find() { return node[1]; }

	// 힙 내용 출력 함수
	// 완전 이진트리의 형태이므로 같은 레벨의 노드들을 한 줄에 출력함
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