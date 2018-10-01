#include "LinkedStack.h"

int main()
{
	LinkedStack stack;

	// 스택 객체를 통해 push() 연산을 호출할 때 Node 객체를 동적으로 할당하여 매개변수로 전달해야 한다
	stack.push(new Node(201613096, "임태민", "게임 콘텐츠 스쿨"));
	stack.push(new Node(201634833, "박찬엽", "방송 기술과"));
	stack.push(new Node(201513013, "윤명준", "컴퓨터 제어과"));
	stack.display();

	Node* node = stack.pop();
	printf("[pop항목]\n");
	node->display();
	printf("\n");
	
	delete node;

	stack.display();

	return 0;
}