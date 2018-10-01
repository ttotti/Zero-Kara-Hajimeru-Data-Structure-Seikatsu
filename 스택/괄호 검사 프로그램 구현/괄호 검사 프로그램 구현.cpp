#include "ArrayStack.h"

bool checkMatching(char* filename)
{
	// 주어진 파일을 읽어 괄호 매칭을 검사하고 결과를 출력하는 함수
	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
		error("Error : 파일 존재하지 않습니다\n");

	int nLine = 1; // 읽은 라인의 개수
	int nChar = 0; // 읽은 문자 개수

	ArrayStack stack;
	char ch;

	// 왜 출력이 안될까 보니 멍청하게 ((ch == getc(fp) != EOF)) 이렇게 적어버렸다.. 괄호위치하고 == 부분을 잘못적었다
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
	printf("[%s] 파일 검사 결과: \n", filename);
	if (!stack.isEmpty())
		printf("Error : 문제 발견!(라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	else
		printf("Ok : 괄호닫기정상(라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	return stack.isEmpty();
}

int main()
{
	//checkMatching("d");
	checkMatching("ArrayStack.h");
	//checkMatching("C:\Users\Lim-ttotti\Documents\Visual Studio 2017\Projects\자료구조\스택\괄호 검사 프로그램 구현");

	return 0;
}