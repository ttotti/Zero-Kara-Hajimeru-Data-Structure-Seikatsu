#include "LinkedQueue.h"

int main()
{
	LinkedQueue que;

	que.enqueue(new Node(201613096, "���¹�", "���� ������ ����"));
	que.enqueue(new Node(201613254, "������", "��� ��� �����"));
	que.enqueue(new Node(201613789, "������", "��ǻ�� �����"));

	que.display();

	delete que.dequeue();

	que.display();

	return 0;
}