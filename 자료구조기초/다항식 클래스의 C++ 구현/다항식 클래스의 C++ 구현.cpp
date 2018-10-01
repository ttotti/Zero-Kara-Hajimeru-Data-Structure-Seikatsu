#include "Polynomial.h"
#include "SparseMatrix.h"
#include <cstdio>

int main()
{
	//Polynomial a, b, c;

	//a.read();
	//b.read();

	//a.display("A = ");
	//b.display("B = ");

	//c.add(a, b);
	//c.display("A+B = ");
	//c.sub(a, b);
	//c.display("A-B = ");
	//c.mult(a, b);
	//c.display("A*B = ");

	//printf("\n");

	SparseMatrix a_sm;
	SparseMatrix b_sm;
	SparseMatrix c_sm;

	a_sm.SparseMatrix::read();
	b_sm.SparseMatrix::read();
	
	a_sm.SparseMatrix::display("a_sm = ");
	b_sm.SparseMatrix::display("b_sm = ");

	c_sm.SparseMatrix::add(a_sm, b_sm);
	c_sm.SparseMatrix::display("a_sm + b_sm = ");

	return 0;
}