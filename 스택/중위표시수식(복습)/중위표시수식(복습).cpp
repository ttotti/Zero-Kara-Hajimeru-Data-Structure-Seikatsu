#include "Stack.h"

int priority(char c)
{
	if (c == '(' || c == ')')
		return 0;
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
}

void s_input(FILE* fp = stdin)
{
	char c;
	stack st;

	while ((c = getc(fp)) != '\n')
	{
		if (c >= '0'&&c <= '9')
		{
			printf("%c", c);
		}
		else if (c == '(')
		{
			st.push(c);
		}
		else if (c == ')')
		{
			while (st.peek() != '(')
			{
				printf("%c", st.pop());
			}
			st.pop();
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (st.isEmpty())
			{
				st.push(c);
			}
			else
			{
				char val = st.peek();

				if (priority(c) <= priority(val))
					printf("%c", st.pop());
				else
					st.push(c);
			}
		}
	}

	while (!st.isEmpty())
	{
		printf("%c", st.pop());
	}

	printf("\n");
}

int main()
{
	printf("수식을 입력해주세요: ");
	s_input();

	return 0;
}