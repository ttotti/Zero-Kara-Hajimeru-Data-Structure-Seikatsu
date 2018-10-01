#include "SparseMatrix.h"

void SparseMatrix::read()
{
	Polynomial::read();

	for (int i = 0; i <= degree; i++)
	{
		if (coef[i] != 0.0)
		{
			term[nTrems].coeff = coef[i];
			term[nTrems].expon = degree - i;
			nTrems++;
		}
		else
			continue;
	}
	nTrems = degree;
}

void SparseMatrix::add(SparseMatrix a, SparseMatrix b)
{
	if (a.term->expon > b.term->expon)
	{
		*this = a;
		for (int i = 0; i <= b.term->expon; i++)
		{
			term[i + (term->expon - b.term->expon)].coeff += b.term->coeff;
		}
	}
	else
	{
		*this = b;
		for (int i = 0; i <= a.term->expon; i++)
		{
			term[i + (term->expon - a.term->expon)].coeff += a.term->coeff;
		}
	}
}

void SparseMatrix::display(char* str)
{
	printf("\t%s", str);
	for (int i = 0; i < term->expon; i++)
	{
		printf("%5.1f x^%d + ", term[i].coeff, term[i].expon);
	}
	//printf("\n");
	printf("%4.1f\n",nTrems);
}
