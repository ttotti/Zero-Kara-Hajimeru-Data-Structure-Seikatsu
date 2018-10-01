#include "ArrayStack.h"
#include "Student.h"

int main()
{
	ArrayStack stack;
	Student s(200012345, "������", "��۱����");
	stack.push(s);
	stack.display();

	s.set(201613096, "���¹�", "���Ӱ�");
	stack.push(s);
	stack.display();

	stack.push(Student(123456789, "������", "��ǻ�Ͱ��а�")); // �ڵ尡 ��ٸ� �̷��� �����ص� �ȴ� // �ӽð�ü�� ����� �����ϰ� �ӽð�ü�� �����ȴ�
	stack.display();

	stack.pop();
	stack.display();

	return 0;
}