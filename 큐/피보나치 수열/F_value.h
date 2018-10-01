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
	printf("몇 번째 수열 값을 보고싶으신가요? ");
	scanf("%d", &_n);
}