#include "OperandStack.h"

// �Է����κ��� ���� ǥ�� ������ �о� ����ϴ� �Լ�
double calcPostfixExpr(FILE *fp = stdin) // stdin �̶� ǥ�� �Է¿� ���� ������
{
	char c;
	OperandStack st; // ���� ��ü

	// �� ����� �ȵɱ� ���� ��û�ϰ� ((c = getc(fp) != '\n')) �̷��� ������.. ��ȣ�� ��ġ�� �߸��ƴ�..
	// getc() �̶� �Է½�Ʈ������ ���ڸ� �о� �� ���ڿ� �ش��ϴ� ������ ��ȯ�Ѵ�
	// FILE�� �����͸� ����Ͽ� ������ ó������ ������ ���ڴ����� ó���� �����ϸ� stdin�� ����Ͽ� Ű���� �Է��� �޴°͵� �����ϴ� // ������ ���̰ų� ������ �߻��ϸ� EOF�� ��ȯ�Ѵ�
	while ((c = getc(fp)) != '\n') // '\n' �Է� ������
	{
		if (c == '+' || c == '-' || c == '*' || c == '/') // �������̸�
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
		else if (c >= '0'&& c <= '9') // �� ������(����)�� �����̸�
		{
			ungetc(c, fp); // ���ڸ� �Է� ���ۿ� �����ְ�
			double val;
			fscanf(fp, "%lf", &val); // double �� �ٽ� ���� // txt������ ���� ������ �����Ѵ�
			st.push(val); // ���� ���� ���ÿ� ����
		}
	}

	// ���������� ����� ���´� �װ� ��ȯ
	return (st.pop());
}

int main()
{
	// ���� ǥ�� ������ �Է��� �� �� �ǿ����ڵ��� �ݵ�� ���鹮�ڳ� �� ������ �и����־�� �Ѵ�
	printf("���� �Է� (Postfix) = ");
	double res = calcPostfixExpr();
	printf("��� ��� : %f\n", res);

	return 0;
}