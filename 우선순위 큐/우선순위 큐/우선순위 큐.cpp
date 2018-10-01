#include "MaxHeap.h"

int main()
{
	// 힙의 삽입, 삭제의 시간 복잡도는 O(log2n) 이다
	MaxHeap heap;

	heap.insert(10);
	heap.insert(5);
	heap.insert(30);
	heap.insert(8);
	heap.insert(9);
	heap.insert(3);
	heap.insert(7);

	heap.display();

	heap.remove();
	heap.display();

	heap.remove();
	heap.display();

	printf("\n");
	return 0;
}