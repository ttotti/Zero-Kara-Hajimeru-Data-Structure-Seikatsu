#include "MinHeap.h"

// 허프만 코드
// 영어 단어들을 공부하다 보면 많은 알파벳 'e'가 많이 나오는 것에 비해 'z'가 들어 있는 단어는 많지 않음을 알 수 있다
// 각 알파벳의 빈도가 알려져 있다면 이진트리를 이용하여 이 문서를 압축하고 용량을 줄일 수 있다

// 예를 들면 영문 텍스트에서 e의 빈도가 123인데 비해 z는 1일 때 이것은 e가 123배 더 많이 사용되었다는 것을 의미한다 
// 우리가 흔히 사용하는 아스키(ASCII) 코드는 모든 문자를 동일한 비트수로 표현한다, 이것은 압축의 관점에서는 적절하지 않다
// 많이 사용되는 문자는 적은 비트수를 부여하고 그렇지 않은 문자는 많은 비트수를 부여할 수 있다

// 1. 모든 문자를 7비트로 표현 : 7bit * (e 123회 + z 1회) = 868비트
// 2. e는 2비트로, z를 20비트로 표현 : 2bit * (e 123회) + 20bit * (z 1회) = 266비트

// 첫 번째 방법에 비해 두 번째 방법은 적은 비트수로 동일한 단어를 표현할 수 있다
// 따라서 데이터를 압축할 때는 아스키(ASCII) 코드와 같은 고정 길이 코드를 사용하지 않고, 가변 길이 코드를 흔히 사용한다
// 각 글자의 빈도수에 따라서 가장 많이 등장하는 글자에는 짧은 비트열을 사용하고 잘 나오지 않는 글자에는 긴 비트열을 사용하여 전체의 크기를 줄이는 방법이다

// 가변 길이 코드를 사용하면 텍스트의 경우 단어를 어떻게 표현할까?

// FACE 란 단어의 경우 (임의로 비트 부여)
/* 고정 길이 코드 :    F     A     C     E
                     0101  0000  0010  0100  */
/* 가변 길이 코드 :   0111  00    0110  10    */

// 고정 길이 코드의 경우 0101000000100100 에서 순서대로 4비트씩 끊어서 코드를 적거나 읽으면 된다
// 가변 길이 코드의 경우 011100011010 에서 한 비트씩 읽으면서 코드 테이블에 코드가 있으면 한 문자로 처리한다
// 예를 들어, 첫 문자인 0은 테이블에 없으므로 다음 코드까지 읽는다, 01도 테이블에 없다, 011도 마찬가지다, 마지막으로 0111은 테이블에서 F에 해당하는 코드다
// 따라서 첫 문자는 4비트를 사용한 F가 된다 이 방법을 반복하여 "FACE" 라는 윈문을 추출할 수 있다

// 이런 해독 과정을 가능하려면 모든 가변 길이 코드가 다른 코드의 첫 부분이 아니라는 것이다,
// 따라서 코딩된 비트열을 왼쪽에서 오른쪽으로 조사하여 보면 정확히 하나의 코드만 일치하는 것을 알 수 있다
// 이러한 특수한 코드를 만들기 위하여 이진트리를 사용할 수 있다

// 허프만 크드 생성 함수
// 빈도수 배열을 받아 허프만 트리를 만드는 함수
void MakeTree(int freq[], int n)
{
	// 최소 힙 객체 heap을 생성
	MinHeap heap;

	// 모든 노드 삽입
	for (int i = 0; i < n; i++)
	{
		heap.insert(freq[i]);
	}

	// n-1번 병합 과정을 처리함
	for (int i = 1; i < n; i++)
	{
		// 최소 힙에서 우선순위가 가장 낮은 두 개의 노드를 꺼냄
		// 최소 노드 삭제
		HeapNode e1 = heap.remove();
		// 다음 최소 노드 삭제
		HeapNode e2 = heap.remove();

		// 합한 노드 추가
		// 꺼낸 두 노드를 합하고, 합한 노드를 힙에 다시 삽입
		heap.insert(e1.getKey() + e2.getKey());

		// 합해진 노드의 빈도를 화면에 출력
		printf("(%d+%d)\n", e1.getKey(), e2.getKey());
	}
}

int main()
{
	// 5개 문자의 빈도수를 나타내는 배열
	int freq[] = { 15,12,8,6,4 };

	// 허프만 트리를 생성함
	MakeTree(freq, 5);

	return 0;
}