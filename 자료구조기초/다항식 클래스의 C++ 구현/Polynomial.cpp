#include "Polynomial.h"

// 다항식의 내용을 입력받는 멤버함수
void Polynomial::read()
{
	printf("다항식의 최고 차수를 입력하시오: ");
	scanf("%d", &degree);

	printf("각 항의 계수를 입력하시오 (총 %d개): ", degree + 1);
	for (int i = 0; i <= degree; i++)
	{
		scanf("%f", coef + i);
	}
}

// 다항식의 내용을 화면에 출력하는 함수
void Polynomial::display(char * str) // 디폴트 매개변수 사용
{
	printf("\t%s", str);
	for (int i = 0; i < degree; i++)
	{
		if (coef[i] == 0.0)
			continue;
		else if(coef[i]==1.0)
			printf("x^%d + ", degree - i);
		else
			printf("%5.1f x^%d + ", coef[i], degree - i);
	}

	printf("%4.1f\n", coef[degree]);
}

// 다항식 a와 b를 더하는 함수 a와 b를 더해 자신의 다항식 설정
void Polynomial::add(Polynomial a, Polynomial b)
{
	if (a.degree > b.degree) // a항 > b항
	{
		*this = a; // a 다항식을 자기 객체에 복사
		for (int i = 0; i <= b.degree; i++)
			coef[i + (degree - b.degree)] += b.coef[i];
	}
	else // a항 <= b항
	{
		*this = b; // b 다항식을 자신에 복사
		for (int i = 0; i <= a.degree; i++)
		{
			coef[i + (degree = a.degree)] += a.coef[i];
		}
	}
}

void Polynomial::sub(Polynomial a, Polynomial b)
{
	if (a.degree > b.degree) // a항 > b항
	{
		*this = a; // a 다항식을 자기 객체에 복사
		for (int i = 0; i <= b.degree; i++)
			coef[i + (degree - b.degree)] -= b.coef[i];
	}
	else // a항 <= b항
	{
		*this = b; // b 다항식을 자신에 복사
		for (int i = 0; i <= a.degree; i++)
		{
			coef[i + (degree = a.degree)] -= a.coef[i];
		}
	}
}

void Polynomial::mult(Polynomial a, Polynomial b)
{
	if (a.degree > b.degree) // a항 > b항
	{
		*this = a; // a 다항식을 자기 객체에 복사
		for (int i = 0; i <= b.degree; i++)
			coef[i + (degree - b.degree)] *= b.coef[i];
	}
	else // a항 <= b항
	{
		*this = b; // b 다항식을 자신에 복사
		for (int i = 0; i <= a.degree; i++)
		{
			coef[i + (degree = a.degree)] *= a.coef[i];
		}
	}
}

void Polynomial::trim()
{

}

// 모든 계수의 부호를 바꿈
void Polynomial::negate()
{
	for (int i = 0; i < degree; i++)
	{
		coef[i] = -coef[i];
	}
}
