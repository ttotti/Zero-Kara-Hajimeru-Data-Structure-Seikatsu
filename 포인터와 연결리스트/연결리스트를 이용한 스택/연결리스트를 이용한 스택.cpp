#include "LinkedStack.h"

int main()
{
	LinkedStack stack;

	// ���� ��ü�� ���� push() ������ ȣ���� �� Node ��ü�� �������� �Ҵ��Ͽ� �Ű������� �����ؾ� �Ѵ�
	stack.push(new Node(201613096, "���¹�", "���� ������ ����"));
	stack.push(new Node(201634833, "������", "��� �����"));
	stack.push(new Node(201513013, "������", "��ǻ�� �����"));
	stack.display();

	Node* node = stack.pop();
	printf("[pop�׸�]\n");
	node->display();
	printf("\n");
	
	delete node;

	stack.display();

	return 0;
}