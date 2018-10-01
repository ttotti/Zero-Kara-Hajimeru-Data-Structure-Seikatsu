#pragma once

#include <cstdio>

// 힙에 저장할 노드 클래스

class HeapNode
{
	// key 값
	int key;

public:
	HeapNode(int k = 0)
		:key(k){}

	void setKey(int k) { key = k; }
	int getKey() { return key; }

	void display() { printf("%4d", key); }
};