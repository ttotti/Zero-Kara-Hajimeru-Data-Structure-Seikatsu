#include "OperandStack.h"

// 입력으로부터 후위 표기 수식을 읽어 계산하는 함수
double calcPostfixExpr(FILE *fp = stdin) // stdin 이란 표준 입력에 대한 포인터
{
	char c;
	OperandStack st; // 스택 객체

	// 왜 출력이 안될까 보니 멍청하게 ((c = getc(fp) != '\n')) 이렇게 적었다.. 괄호의 위치가 잘못됐다..
	// getc() 이란 입력스트림에서 문자를 읽어 그 문자에 해당하는 정수를 반환한다
	// FILE형 포인터를 사용하여 파일을 처음부터 끝까지 문자단위로 처리가 가능하며 stdin을 사용하여 키보드 입력을 받는것도 가능하다 // 파일의 끝이거나 에러가 발생하면 EOF를 반환한다
	while ((c = getc(fp)) != '\n') // '\n' 입력 전까지
	{
		if (c == '+' || c == '-' || c == '*' || c == '/') // 연산자이면
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
		else if (c >= '0'&& c <= '9') // 피 연산자(숫자)의 시작이면
		{
			ungetc(c, fp); // 문자를 입력 버퍼에 돌려주고
			double val;
			fscanf(fp, "%lf", &val); // double 로 다시 읽음 // txt파일의 값을 변수에 저장한다
			st.push(val); // 읽은 값을 스택에 저장
		}
	}

	// 마지막에는 결과만 남는다 그걸 반환
	return (st.pop());
}

int main()
{
	// 후위 표기 수식을 입력할 때 각 피연산자들은 반드시 공백문자나 탭 등으로 분리해주어야 한다
	printf("수식 입력 (Postfix) = ");
	double res = calcPostfixExpr();
	printf("계산 결과 : %f\n", res);

	return 0;
}