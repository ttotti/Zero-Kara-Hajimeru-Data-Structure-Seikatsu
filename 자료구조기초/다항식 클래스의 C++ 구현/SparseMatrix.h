#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include "Polynomial.h"

// �ϳ��� ���� ǥ���ϴ� Ŭ����
struct Term
{
	int expon; // ���� ����
	float coeff; // ���� ���
};

// ��� ���׽� Ŭ����
class SparseMatrix :public Polynomial
{
private:
	int nTrems; // ����� 0�� �ƴ� ���� ���
	Term term[MAX_DEGREE]; // ����� 0�� �ƴ� ���� �迭

public:
	SparseMatrix() { nTrems = 0; }

	void read();
	void add(SparseMatrix a, SparseMatrix b);
	void display(char* str = "SPoly = ");
};

#endif // !SPARSEMATRIX_H

