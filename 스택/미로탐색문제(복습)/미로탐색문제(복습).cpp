#include "Location.h"
#include "Stack.h"

char map[HEIGHT][WIGHT] = { // 미로 맵 데이터
	{ '1','1','1','1','1','1' },
	{ 'e','0','1','0','0','1' },
	{ '1','0','0','0','1','1' },
	{ '1','0','1','0','1','1' },
	{ '1','0','1','0','0','x' },
	{ '1','1','1','1','1','1' },
};

bool isOk(int h, int w)
{
	if (w<0 || h<0 || w>WIGHT || h>HEIGHT)
		return false;
	else
		return map[h][w] == '0' || map[h][w] == 'x';
}

int main()
{
	stack st;
	Location miro(1, 0);

	st.push(miro);
	Location here;

	while (!st.isEmpty())
	{
		here = st.pop();

		int w = here.wig;
		int h = here.hei;
		printf("( %d, %d )", h, w);

		if (map[h][w] == 'x')
		{
			printf("미로 탐색 성공! \n");
			return 0;
		}
		else
		{
			map[h][w] = '.';
			if (isOk(h - 1, w))
			{
				st.push(Location(h - 1, w));
			}
			if (isOk(h + 1, w))
			{
				st.push(Location(h + 1, w));
			}
			if (isOk(h, w - 1))
			{
				st.push(Location(h, w - 1));
			}
			if (isOk(h, w + 1))
			{
				st.push(Location(h, w + 1));
			}
		}
	}

	printf("미로 탐색 실패\n");

	return 0;
}