#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include "Polynomial.h"

// 하나의 항을 표현하는 클래스
struct Term
{
	int expon; // 항의 지수
	float coeff; // 항의 계수
};

// 희소 다항식 클래스
class SparseMatrix :public Polynomial
{
private:
	int nTrems; // 계수가 0이 아닌 항의 계수
	Term term[MAX_DEGREE]; // 계수가 0이 아닌 항의 배열

public:
	SparseMatrix() { nTrems = 0; }

	void read();
	void add(SparseMatrix a, SparseMatrix b);
	void display(char* str = "SPoly = ");
};

#endif // !SPARSEMATRIX_H

