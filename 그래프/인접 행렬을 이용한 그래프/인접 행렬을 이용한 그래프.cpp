#include "AdjMatGraph.h"

int main()
{
	// ���ο� �׷��� ��ü ����
	AdjMatGraph g;

	// ���� ���� : 'A' 'B', ...
	for (int i = 0; i < 8; i++)
	{
		g.inserVertex('A' + i);
	}

	//// ���� ����
	//// A - B
	//g.insertEdge(0, 1);
	//// A - D
	//g.insertEdge(0, 3);
	//// B - C
	//g.insertEdge(1, 2);
	//// B - D
	//g.insertEdge(1, 3);
	//// C - D
	//g.insertEdge(2, 3);

	g.insertEdge(0, 1);
	g.insertEdge(0, 2);

	g.insertEdge(1, 0);
	g.insertEdge(1, 3);

	g.insertEdge(2, 0);
	g.insertEdge(2, 3);
	g.insertEdge(2, 4);

	g.insertEdge(3, 1);
	g.insertEdge(3, 2);
	g.insertEdge(3, 5);

	g.insertEdge(4, 2);
	g.insertEdge(4, 6);
	g.insertEdge(4, 7);

	g.insertEdge(5, 3);

	g.insertEdge(6, 4);
	g.insertEdge(6, 7);

	g.insertEdge(7, 4);
	g.insertEdge(7, 6);

	printf("���� ��ķ� ǥ���� �׷���\n");
	// �׷��� ��� -> ȭ��(stdout)���� ���
	g.display();

	// �׷��� g�� ���Ͽ� ����
	g.store("graph.txt");

	// �׷��� g�� �ʱ�ȭ
	g.reset();

	// ���Ͽ��� �׷��� ������ �о� g����
	g.load("graph.txt");
	printf("���� ��ķ� ǥ���� �׷��� (���� : graph.txt)\n");
	// �׷��� g�� ȭ�鿡 ���
	g.display();

	return 0;
}