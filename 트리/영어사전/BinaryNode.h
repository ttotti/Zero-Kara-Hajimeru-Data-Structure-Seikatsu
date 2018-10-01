#pragma once

// 노드 클래스는 Record를 상속하므로 데이터 멤버로는 링크 필드만 추가로 선언하는데
// 이 부분을 제외하면 기본적인 노드 틀과 유사하다
// 링크 이외의 데이터 필드에 대한 처리는 Record에서 담당하므로 이들에 대한 처리 함수들은 필요없다
#include "Record.h"

class BinaryNode :public Record
{
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(const char* w = "", const char* m = "")
		:Record(w, m), left(NULL), right(NULL)
	{
	}

	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }
};