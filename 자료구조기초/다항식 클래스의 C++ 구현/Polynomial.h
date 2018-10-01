#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <cstdio>

#define MAX_DEGREE 80 // 다항식의 처리 가능한 최대 차수+1

class Polynomial
{
protected:
	int degree; // 다항식의 최고 차수
	float coef[MAX_DEGREE]; // 각 항에 대한 계수

public:
	// 생성자 // 최대 차수를 0으로 초기화
	Polynomial() { degree = 0; }

	// 다항식을 입력 받는다
	void read();

	// 다항식을 화면에 출력한다
	void display(char* str = " Poly ");

	// 다항식 p1과 p2를 더한다
	void add(Polynomial a, Polynomial b);

	// 다항식 뺄셈
	void sub(Polynomial a, Polynomial b);

	// 다항식 곱셈
	void mult(Polynomial a, Polynomial b);

	// 다항식의 최고차항의 계수가 0이 아닌 값만 나오게 한다
	void trim();

	// 최고 차수가 0인지를 검사하여 0이면 true를 반환한다
	bool isZero() { return degree == 0; }

	// 모든 계수의 부호를 바꾼다
	void negate();
};

#endif // !POLYNOMIAL_H

