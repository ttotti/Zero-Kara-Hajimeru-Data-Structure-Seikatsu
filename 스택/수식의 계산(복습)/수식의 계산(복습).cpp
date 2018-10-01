#include "Stack.h"

void s_input(FILE* fp = stdin)
{
	char c;
	Stack st;

	while ((c = getc(fp)) != '\n')
	{
		if (c >= '0' && c <= '9')
		{
			ungetc(c, fp);
			double val;
			fscanf(fp, "%lf", &val);
			st.push(val);
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			double val2 = st.pop();
			double val1 = st.pop();
			switch (c)
			{
			case '+':
				st.push(val1 + val2);
				break;
			case '-':
				st.push(val1 - val2);
				break;
			case '*':
				st.push(val1 * val2);
				break;
			case '/':
				st.push(val1 / val2);
				break;
			}
		}
	}

	st.diplay();
}


int main()
{
	printf("수식을 입력해주세요: ");
	s_input();

	return 0;
}