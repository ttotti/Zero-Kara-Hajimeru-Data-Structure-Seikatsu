#include <cstdio>

class Rectangle
{
private:
	int _w, _h;

public:
	Rectangle() {}

	void input()
	{
		printf("�簢���� ���ο� ���θ� �Է��ϼ���: ");
		scanf("%d %d", &_w, &_h);
	}
	void output()
	{
		printf("�簢���� ���� %d\n�簢���� �ѷ� %d\n", area(_w, _h), perimeter(_w, _h));
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