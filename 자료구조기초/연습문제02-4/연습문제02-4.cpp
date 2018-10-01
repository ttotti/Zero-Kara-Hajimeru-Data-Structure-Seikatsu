#include <cstdio>
#include <cmath>

class Complex_Number
{
private:
	float _a, _b;
public:
	Complex_Number() 
	{
		_a = 0.0f; 
		_b = 0.0f; 
	}
	
	void input()
	{
		printf("복소수로 나타낼 실수 2개를 입력하세요 : ");
		scanf("%f %f", &_a, &_b);
	}
	void output()
	{
		printf("\n복소수 %1.f + %1.fi\n", _a, _b);
	}

	void add(Complex_Number& a, Complex_Number& b)
	{
		this->_a = a._a + b._a;
		this->_b = a._b + b._b;
	}
};

int main()
{
	Complex_Number a, b, c;

	a.input();
	b.input();
	a.output();
	b.output();

	c.add(a, b);
	c.output();

	return 0;
}