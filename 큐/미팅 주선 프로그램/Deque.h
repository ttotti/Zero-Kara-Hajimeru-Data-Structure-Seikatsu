#pragma once

#include "Queue.h"

class Deque :public Queue
{
public:
	void addrear(Students d)
	{
		q_push(d);
	}

	Students delectfront()
	{
		return q_pop();
	}

	Students Getfront()
	{
		return q_peek();
	}

	void addfront(Students d)
	{
		if (isFull())
			error("큐의 공간이 꽉 찼습니다");
		else
		{
			data[front] = d;

			front = (front - 1 + MAX_STUDENT) % MAX_STUDENT;
		}
	}

	Students delectrear()
	{
		if (isEmpty())
			error("큐의 공간에 데이터가 없습니다");
		else
		{
			int ret = rear;

			rear = (rear - 1 + MAX_STUDENT) % MAX_STUDENT;

			return data[ret];
		}
	}

	Students Getrear()
	{
		return data[rear];
	}
};