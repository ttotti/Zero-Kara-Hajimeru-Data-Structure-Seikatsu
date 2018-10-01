#include "OperandStack.h"

// ��ü�� �켱���� ���
// ���ڰ� Ŭ���� �켱���� ����
inline int precedence(char op)
{
	switch (op)
	{
	case '[':
	case ']':
		return 0;

	case '{':
	case '}':
		return 1;

	case '(':
	case ')':
		return 2;

	case '+':
	case '-':
		return 3;

	case '*':
	case '/':
		return 4;
	}

	return -1;
}

// ���� ǥ�� ������ ���� ǥ�� �������� ��ȯ�ϴ� ����
void infix2Postfix(FILE* fp = stdin)
{
	char c ,op; // �Է� ���ڿ� ���ÿ��� ���� ���� ���� ����
	double val; // ���� -> ���� ��ȯ ����
	OperandStack st;

	while ((c = getc(fp)) != '\n') // ���� ���� �Է� ������
	{
		// �ǿ������̸� --> �״�� ���
		if (c >= '0'&&c <= '9') // ������(����)�� �����̸�
		{
			ungetc(c, fp); // ���ڸ� ��������
			fscanf(fp, "%lf", &val); // double�� �ٽ� ����
			printf("%4.1f ", val);
		} 
		// '('�̸� --> ���ÿ� ����
		else if (c == '(')
		{
			st.push(c);
		}
		// ')'�̸� --> '('�� ���ö����� ������ ���
		else if (c == ')')
		{
			while (!st.isEmpty())
			{
				op = st.pop();
				if (op == '(')
					break;
				else
					printf("%c ", op);
			}
		}

		else if (c == '{')
		{
			st.push(c);
		}
		// ')'�̸� --> '('�� ���ö����� ������ ���
		else if (c == '}')
		{
			while (!st.isEmpty())
			{
				op = st.pop();
				if (op == '{')
					break;
				else
					printf("%c ", op);
			}
		}

		else if (c == '[')
		{
			st.push(c);
		}
		// ')'�̸� --> '('�� ���ö����� ������ ���
		else if (c == ']')
		{
			while (!st.isEmpty())
			{
				op = st.pop();
				if (op == '[')
					break;
				else
					printf("%c ", op);
			}
		}

		// ������ �̸� --> �켱���� �� ó��
		else if (c == '+' || c == '-' || c == '/' || c == '*')
		{
			while (!st.isEmpty())
			{
				op = st.peek();
				if (precedence(c) <= precedence(op))
				{
					printf("%c ",op);
					st.pop();
				}
				else break;
			}
			st.push(c);
		}

	}

	while (!st.isEmpty())
	{
		printf("%c ", st.pop());
	}

	printf("\n");
}

int main()
{
	printf("���� �Է�(Infix) = ");
	infix2Postfix();

	return 0;
}