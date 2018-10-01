#pragma once

#include <cstdio>
#include <cstdlib>

#define MAX_QUEUE_SIZE 100

inline void error(const char* message)
{
	printf("%s", message);
	exit(1);
}

// 큐의 위치는 +1하고 그걸 나누고 난 후의 나머지값이다 (포인트!)
// 배열을 이용한 큐 또한 스택과 똑같이 크기가 제한된다 이는 연결리스트로 해결된다
// 큐는 데이터를 삽입할때 항상 한칸을 남겨놓아야한다 왜냐하면 전단과 후단이 같은위치에 있으면 공백상태로 인식하기 때문이다
class CircularQueue
{
protected:
	int front; // 첫 번째 요소의 앞의 위치 (전단) (삭제를 위한 변수)
	int rear; // 마지막 요소 위치 (후단) (삽입을 위한 변수)
	int data[MAX_QUEUE_SIZE]; // 요소의 배열

public:
	CircularQueue() { front = rear = 0; } // front == rear 이 되면 공백상태

	bool isEmpty() { return front == rear; } // front == rear 이 되면 공백상태
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; } // front가 rear보다 한칸 앞에 있으면 포화상태

	void enqueue(int val) // 큐에 삽입
	{
		if (isFull())
			error("큐가 포화상태입니다");
		else
		{
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}

	int dequeue() // 첫 항목을 큐에서 빼서 반환
	{
		if (isEmpty())
			error("큐에 데이터가 없습니다");
		else
		{
			front = (front + 1) % MAX_QUEUE_SIZE;

			return data[front];
		}
	}

	int peek() // 첫 항목을 큐에서 빼지 않고 반환
	{
		if (isEmpty())
			error("큐에 데이터가 없습니다");
		else
		{
			data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}

	void display()
	{
		printf("큐 내용");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;

		for (int i = front + 1; i <= maxi; i++)
			printf("[%d] ", data[i%MAX_QUEUE_SIZE]);

		printf("\n");
	}
};