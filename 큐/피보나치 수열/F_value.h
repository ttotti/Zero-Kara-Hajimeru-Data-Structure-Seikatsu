#pragma once

#include <iostream>

using namespace std;

class F_value
{
public:
	int _n;

	F_value(int n = 0) { _n = n; }

	int F(int n);
	void input();
};

int F_value::F(int n)
{
	return n;
}

void F_value::input()
{
	printf("�� ��° ���� ���� ��������Ű���? ");
	scanf("%d", &_n);
}