#pragma once

#include <cstdio>

// ���� ������ ��� Ŭ����

class HeapNode
{
	// key ��
	int key;

public:
	HeapNode(int k = 0)
		:key(k){}

	void setKey(int k) { key = k; }
	int getKey() { return key; }

	void display() { printf("%4d", key); }
};