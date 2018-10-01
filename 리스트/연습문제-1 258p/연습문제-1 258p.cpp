#include "LinkedList.h"

int main()
{
	LinkedList List;

	List.insertNode(0, new Node(10));
	List.insertNode(1, new Node(20));
	List.insertNode(2, new Node(30));

	List.display();

	List.deleteNode(0);

	List.display();

	List.insertNode(1, new Node(50));

	List.display();

	return 0;
}