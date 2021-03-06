#include <cstdio>

// 순환(재귀함수)이란 어떤 알고리즘이나 함수가 자기 자신을 호출하여 문제를 해결하는 프로그래밍 기법이다
// 순환은 많은 문제들을 해결하는데 독특한 개념적인 프레임워크를 제공한다

// 프로그래밍 언어에서 하나의 함수가 자기 자신을 다시 호출하는 것은 다른 함수를 호출하는 것과 동일하다
// 즉 복귀주소가 시스템 스택에 저장되고 호출되는 함수를 위한 파라미터와 지역 변수를 스택으로부터 할당받는다
// 이러한 함수를 위한 시스템 스택에서의 공간을 활성 레코드라 한다
// 이러한 준비가 끝나면 호출된 함수의 코드 시작 위치로 이동하여 수행을 시작하는데 만약 호출된 함수가 자기 자신이라면 자기 자신의 시작위치로 점프하게 되는 것이다
// 호출된 함수가 끝나게 되면 시스템 스택에서 복귀주소를 꺼내 자신을 호출한 함수로 되돌아간다

// 호출 중의 시스템 스택의 변화(책266p, 인터넷 참고)

// 팩토리얼 함수
// 순환의 순서는 책264p, 인터넷을 참고한다
int factorial(int n)
{
	printf("factorial(%d)\n", n); // 순환 호출 순서 확인을 위한 출력문

	// 순환 알고리즘에는 꼭 순환 호출을 멈추는 부분이 있어야 한다
	// 만약 없다면 시스템 스택을 다 사용할 때까지 순환적으로 호출되다가 결국 에러를 내면서 멈출 것이다
	if (n == 1) return 1; // n == 1인 경우(종료 조건)

	else return (n*factorial(n - 1)); // n > 1인 경우(순환 호출)
}

int main()
{
	factorial(5);
	//for (int i = 1; i <= 32; i++)
	//{
	//	printf("%d\n", factorial(i));
	//}

	return 0;
}