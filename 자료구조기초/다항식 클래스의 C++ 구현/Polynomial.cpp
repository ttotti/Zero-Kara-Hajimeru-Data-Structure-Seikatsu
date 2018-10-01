#include "Polynomial.h"

// ���׽��� ������ �Է¹޴� ����Լ�
void Polynomial::read()
{
	printf("���׽��� �ְ� ������ �Է��Ͻÿ�: ");
	scanf("%d", &degree);

	printf("�� ���� ����� �Է��Ͻÿ� (�� %d��): ", degree + 1);
	for (int i = 0; i <= degree; i++)
	{
		scanf("%f", coef + i);
	}
}

// ���׽��� ������ ȭ�鿡 ����ϴ� �Լ�
void Polynomial::display(char * str) // ����Ʈ �Ű����� ���
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

// ���׽� a�� b�� ���ϴ� �Լ� a�� b�� ���� �ڽ��� ���׽� ����
void Polynomial::add(Polynomial a, Polynomial b)
{
	if (a.degree > b.degree) // a�� > b��
	{
		*this = a; // a ���׽��� �ڱ� ��ü�� ����
		for (int i = 0; i <= b.degree; i++)
			coef[i + (degree - b.degree)] += b.coef[i];
	}
	else // a�� <= b��
	{
		*this = b; // b ���׽��� �ڽſ� ����
		for (int i = 0; i <= a.degree; i++)
		{
			coef[i + (degree = a.degree)] += a.coef[i];
		}
	}
}

void Polynomial::sub(Polynomial a, Polynomial b)
{
	if (a.degree > b.degree) // a�� > b��
	{
		*this = a; // a ���׽��� �ڱ� ��ü�� ����
		for (int i = 0; i <= b.degree; i++)
			coef[i + (degree - b.degree)] -= b.coef[i];
	}
	else // a�� <= b��
	{
		*this = b; // b ���׽��� �ڽſ� ����
		for (int i = 0; i <= a.degree; i++)
		{
			coef[i + (degree = a.degree)] -= a.coef[i];
		}
	}
}

void Polynomial::mult(Polynomial a, Polynomial b)
{
	if (a.degree > b.degree) // a�� > b��
	{
		*this = a; // a ���׽��� �ڱ� ��ü�� ����
		for (int i = 0; i <= b.degree; i++)
			coef[i + (degree - b.degree)] *= b.coef[i];
	}
	else // a�� <= b��
	{
		*this = b; // b ���׽��� �ڽſ� ����
		for (int i = 0; i <= a.degree; i++)
		{
			coef[i + (degree = a.degree)] *= a.coef[i];
		}
	}
}

void Polynomial::trim()
{

}

// ��� ����� ��ȣ�� �ٲ�
void Polynomial::negate()
{
	for (int i = 0; i < degree; i++)
	{
		coef[i] = -coef[i];
	}
}
