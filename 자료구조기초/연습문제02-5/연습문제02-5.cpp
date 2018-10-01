#include <cstdio>

class Rectangle
{
private:
	int _w, _h;

public:
	Rectangle() {}

	void input()
	{
		printf("사각형의 가로와 세로를 입력하세요: ");
		scanf("%d %d", &_w, &_h);
	}
	void output()
	{
		printf("사각형의 넓이 %d\n사각형의 둘레 %d\n", area(_w, _h), perimeter(_w, _h));
	}
	int area(int w, int h)
	{
		return w*h;
	}
	int perimeter(int w, int h)
	{
		return (w + h) * 2;
	}
};

int main()
{
	Rectangle r;

	r.input();
	r.output();

	return 0;
}