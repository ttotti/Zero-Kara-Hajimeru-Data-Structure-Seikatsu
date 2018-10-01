#pragma once

#include "Student.h"

// 배열을 이용한 스택에서 구현한 학생정보스택을 연결 리스트를 이용해 다시 구현
// 먼저 노드에는 링크 필드가 있어야하고 데이터 필드는 학생 정보가 되어야 한다
// 이를 위한 가장 단순한 방법은 Node 클래스에 Student 객체를 다음과 같이 포함시키는 방법이다
// 그리고 상속을 이용할 수도 있다 코드의 재사용성을 극대화하기 위해서는 상속하는 것이 바람직하다
class Node :public Student
{
private:
	// Student person; // 데이터 필드 : Student 객체를 포함

	// 다음 노드를 가리키는 포인터 변수
	Node* link; // 링크 필드

public:
	// 생성자에서는 Student의 생성자 호출을 위한 약간의 고려가 필요하다
	// link는 반드시 NULL로 초기화 해야 한다

	Node(int id = 0, char* name = "", char* dept = "")
		:Student(id, name, dept)
	{
		link = NULL;
	}

	~Node() {  }
	
	// Node 클래스의 멤버함수는 private로 선언된 링크 필드에 접근하기 위한 접근자만 있으면 된다
	// 링크의 주소를 반환하고 설정하는 함수들

	// 다음 노드를 반환한다
	Node* getLink() { return link; }
	// 현재 노드의 링크에 연결한다
	void setLink(Node* p) { link = p; }
};