#include "ArrayStack.h"
#include "Student.h"

int main()
{
	ArrayStack stack;
	Student s(200012345, "박찬엽", "방송기술과");
	stack.push(s);
	stack.display();

	s.set(201613096, "임태민", "게임과");
	stack.push(s);
	stack.display();

	stack.push(Student(123456789, "윤명준", "컴퓨터공학과")); // 코드가 길다면 이렇게 선언해도 된다 // 임시객체를 만들어 전달하고 임시객체는 삭제된다
	stack.display();

	stack.pop();
	stack.display();

	return 0;
}