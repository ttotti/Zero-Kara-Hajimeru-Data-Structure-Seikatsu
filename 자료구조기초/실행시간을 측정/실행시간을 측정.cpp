#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	// 시작 시간과 종료 시각을 저장할 변수
	clock_t start, finish;
	// 실행 시간을 저장할 변수
	double duration;

	// 컴퓨터의 현재 시각을 저장
	start = clock();

	// 실행 시간을 측정하고자 하는 코드
	// ....

	// 코드 실행후의 현재 시각을 저장
	finish = clock();

	// 실행시간을 (finish - start) CLOCKS_PER_SEC 로 나누어 초 단위의 실행시간을 계산
	// 나눗셈 연산을 하므로 double 으로 형변환해야함
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f 초입니다\n", duration);

	// 이 알고리즘은 성능을 비교하는데 몇 가지 문제가 있다
	// 현재시간을 저장하고 계산하는 알고리즘이 포함되있어야 한다 큰 프로젝트에는 부담이 될수있다
	// 동일한 조건의 하드웨어을 사용하여 실행시간을 측정해야한다 컴퓨터마다 시간이 빠르게 갈수도 느리게 갈수도 있기때문이다
	// 사용한 소프트웨어 환경도 동일해야한다 예를 들어 프로그래밍 언어에도 실행속도가 크게 달라질수 있기 때문이다
	// 성능 비교에 사용했던 데이터가 아니니 다른 데이터에 대해서는 다른 결과가 나올 수 있어 실험되지 않은 입력에 대해서는 실행 시간을 주장할 수 없다

	return 0;
}