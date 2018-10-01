#include "F_value.h"
#include "Queue.h"
#include <iostream>

using namespace std;

int main()
{
	Queue q;
	F_value F;

	q.push(F_value(0));
	q.push(F_value(1));

	F.input();
	if (F._n == 0)
	{
		printf("결과 : %d\n", q.pop());
		return 0;
	}
	else if (F._n == 1)
	{
		q.pop();
		printf("결과 : %d\n", q.pop());
		return 0;
	}

	F_value H_e;
	F_value M_e;

	for (int i = 0; i < F._n; i++)
	{
		H_e = q.pop();
		M_e = q.peek();

		int e = H_e._n;
		int g = M_e._n;
		
		q.push(e + g);
	}

	printf("결과 : %d\n", q.pop());

	return 0;
}