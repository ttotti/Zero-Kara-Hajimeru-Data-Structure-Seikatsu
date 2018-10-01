#include "ArrayStack.h"

bool checkMatching(char* filename)
{
	// �־��� ������ �о� ��ȣ ��Ī�� �˻��ϰ� ����� ����ϴ� �Լ�
	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
		error("Error : ���� �������� �ʽ��ϴ�\n");

	int nLine = 1; // ���� ������ ����
	int nChar = 0; // ���� ���� ����

	ArrayStack stack;
	char ch;

	// �� ����� �ȵɱ� ���� ��û�ϰ� ((ch == getc(fp) != EOF)) �̷��� ������ȴ�.. ��ȣ��ġ�ϰ� == �κ��� �߸�������
	while ((ch = getc(fp)) != EOF)
	{
		if (ch == '\n')
			nLine++;

		nChar++;

		if (ch == '[' || ch == '{' || ch == '(')
			stack.push(ch);

		else if (ch == ']' || ch == '}' || ch == ')')
		{
			int prev = stack.pop();

			if ((ch == ']'&&prev != '[') || (ch == '}'&&prev != '{') || (ch == ')'&&prev != '('))
			{
				break;
			}
		}
	}

	fclose(fp);
	printf("[%s] ���� �˻� ���: \n", filename);
	if (!stack.isEmpty())
		printf("Error : ���� �߰�!(���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	else
		printf("Ok : ��ȣ�ݱ�����(���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	return stack.isEmpty();
}

int main()
{
	//checkMatching("d");
	checkMatching("ArrayStack.h");
	//checkMatching("C:\Users\Lim-ttotti\Documents\Visual Studio 2017\Projects\�ڷᱸ��\����\��ȣ �˻� ���α׷� ����");

	return 0;
}