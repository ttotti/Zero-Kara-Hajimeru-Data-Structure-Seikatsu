#include "LinkedQueue.h"

int main()
{
	LinkedQueue que;

	que.enqueue(new Node(201613096, "임태민", "게임 콘텐츠 스쿨"));
	que.enqueue(new Node(201613254, "박찬엽", "방송 통신 기술과"));
	que.enqueue(new Node(201613789, "윤명준", "컴퓨터 제어과"));

	que.display();

	delete que.dequeue();

	que.display();

	return 0;
}