#pragma once
#include <cstdio>
#include <cstdlib>

#include "Student.h"

inline void error(char* message)
{
	printf("%s\n", message);
	exit(1);
}

// 스택의 최대 크기
const int MAX_STACK_SIZE = 20;

class ArrayStack
{
private:
	int top; // 요소의 개수
	Student date[MAX_STACK_SIZE]; // 요소의 배열 // 학생의 정보를 저장할 Student 객체의 배열을 생성한다

public:
	// 생성자 // 배열은 0부터 시작하므로 초기값을 -1하고 추가시 +1을 한다
	ArrayStack() { top = -1; }
	~ArrayStack() {}

	bool isEmpty() { return top == -1; } // 요소의 개수인 top이 -1이면 스택에 아무것도 안들어있다는것
	bool isFull() { return top == MAX_STACK_SIZE - 1; } // 요소의 개수인 top가 최대크기-1 만큼 들어있다면 스택이 꽉 차있다는 것

	// 데이터를 삽입한다
	// Student 타입의 데이터를 삽입한다 // 데이터가 크다면 포인터나 레퍼런스로 넘겨도 된다
	void push(Student e)
	{
		// 스택공간이 꽉 차있다면 에러를 뿜고 종료한다
		if (isFull())
			error("스택 공백 에러");

		// 에러가 안뿜었다면 top을 먼저 +1 하고 배열에 데이터를 삽입한다
		date[++top] = e;
	}
	
	// 맨 위의 데이터를 삭제하고 반환한다
	// Student 타입의 데이터를 반환한다 // 이것 또한 포인터나 레퍼런스로 처리할수있다
	Student pop()
	{
		// 스택공간이 비어있다면 에러를 뿜는다
		if (isEmpty())
			error("스택 공백 에러");

		// 에러를 안 뿜었다면 데이터를 반환한후 top을 -1 한다
		return date[top--];
	}

	// 맨 위의 데이터를 삭제하지 않고 반환한다
	Student peek()
	{
		if (isEmpty())
			error("스택 공백 에러");

		// 데이터를 반환하고 top은 내버려둔다
		return date[top];
	}

	// 스택공간안에 있는 데이터를 출력한다
	// 각 학생의 정보는 Student 클래스의 멤버함수를 사용한다
	void display()
	{
		printf("[전체 학생의 수 = %2d] ==> \n", top + 1); // top은 -1부터 시작했으므로 출력은 +1을 한다
		for (int i = 0; i <= top; i++) // i<top을 하면 top-1만큼 실행하기 때문에 <= 으로 실행한다
			date[i].display();
		printf("\n");
	}
};