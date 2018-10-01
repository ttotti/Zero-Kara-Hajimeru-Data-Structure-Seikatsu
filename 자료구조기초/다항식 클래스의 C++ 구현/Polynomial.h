#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <cstdio>

#define MAX_DEGREE 80 // ���׽��� ó�� ������ �ִ� ����+1

class Polynomial
{
protected:
	int degree; // ���׽��� �ְ� ����
	float coef[MAX_DEGREE]; // �� �׿� ���� ���

public:
	// ������ // �ִ� ������ 0���� �ʱ�ȭ
	Polynomial() { degree = 0; }

	// ���׽��� �Է� �޴´�
	void read();

	// ���׽��� ȭ�鿡 ����Ѵ�
	void display(char* str = " Poly ");

	// ���׽� p1�� p2�� ���Ѵ�
	void add(Polynomial a, Polynomial b);

	// ���׽� ����
	void sub(Polynomial a, Polynomial b);

	// ���׽� ����
	void mult(Polynomial a, Polynomial b);

	// ���׽��� �ְ������� ����� 0�� �ƴ� ���� ������ �Ѵ�
	void trim();

	// �ְ� ������ 0������ �˻��Ͽ� 0�̸� true�� ��ȯ�Ѵ�
	bool isZero() { return degree == 0; }

	// ��� ����� ��ȣ�� �ٲ۴�
	void negate();
};

#endif // !POLYNOMIAL_H

