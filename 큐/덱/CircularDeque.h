#pragma once

#include "CircularQueue.h"

// 큐 클래스를 상속
// 덱은 스택과 큐의 연산을 모두 가지고 있다
// 예를 들어 덱의 전단(front)과 관련된 연산들만 사용하면 스택이 되고
// 삽입은 후단(rear) 삭제는 전단(front)을 사용하면 큐가 된다
// 덱 또한 연결리스트로 구현할수있는데 이중연결리스트 라는 구조로 구현해야 한다
class CircularDeque :public CircularQueue
{
public:
	CircularDeque(){}

	void addRear(int val) // 후단에 삽입
	{
		enqueue(val);
	}

	int deleteFront()
	{
		return dequeue();
	}

	int getFront()
	{
		return peek();
	}

	
	void addFront(int val) // 전단에 삽입
	{
		if (isFull())
			error("덱이 포화상태입니다");
		else
		{
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}

	int deleteRear()
	{
		if (isEmpty())
			error("덱에 데이터가 없습니다");
		else
		{
			int ret = data[rear];
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return ret;
		}
	}

	int getRear()
	{
		if (isEmpty())
			error("덱에 데이터가 없습니다");
		else
			return data[rear];
	}

	void display()
	{
		printf("덱의 내용 : ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;

		for (int i = front + 1; i <= maxi; i++)
			printf("[%d] ", data[i%MAX_QUEUE_SIZE]);

		printf("\n");
	}
};