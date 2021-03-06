#pragma once

#include "Record.h"
#include "hashFunctions.h"

class HashMap
{
private:
	// 해싱 테이블, 크기는 13
	Record table[TABLE_SIZE];

public:
	// 생성자, 모든 버켓을 비움
	HashMap() { reset(); }

	// 모든 버켓을 비움
	void reset()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			table[i].reset();
		}
	}

	// 맵의 전체 내용을 출력
	void display()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			printf("[%2d] ", i);
			table[i].display();
		}
	}

	// HashMap::addLinearProb(); 선형 조사법을 이용한 삽입
	// 선형 조사법에 의한 레코드 삽입 함수
	void addLinearProb(const char* key, const char* value)
	{
		int i, hashValue;

		// 탐색키에 대하여 해시 주소 i를 계산
		hashValue = i = hashFunction(key);

		// 주소 i가 비어 있는지를 검사해서 비어 있지 않으면
		while (table[i].isEmpty() == false)
		{
			// i에 저장된 탐색키와 삽입하려고 하는 탐색키가 동일한지를 체크해서 동일하면 에러 메시지를 출력하고 반환함, 삽입하지 않음
			if (table[i].equal(key))
			{
				printf("[%s] 탐색키가 중복되었습니다\n", key);
				return;
			}

			// 다음 주소 계산
			i = (i + 1) % TABLE_SIZE;

			// 처음의 주소로 돌아왔으면, 테이블이 가득 찬 상황, 에러 메시지 출력 후 반환
			if (i == hashValue)
			{
				printf("[%s] 테이블이 가득찼습니다\n", key);
				return;
			}
		}

		// 현재 위치 i에 레코드 삽입
		table[i].set(key, value);
	}

	// HashMap::searchLinearProb(); 선형 조사법을 이용한 키를 탐색
	// 선형 조사법에 의한 레코드 검색 함수
	Record* searchLinearProb(const char* key)
	{
		int i, hashValue;

		// 탐색키에 대하여 해시 주소 i를 계산
		hashValue = i = hashFunction(key);

		// 주소 i가 비어 있는지를 검사해서 비어 있지 않으면
		while (table[i].isEmpty() == false)
		{
			// 검색 키와 현재 레코드와 키가 같으면 탐색 성공, 메시지 출력 후 해당 레코드 반환
			if (table[i].equal(key))
			{
				printf("[%s] 탐색성공[%d]", key, i);
				table[i].display();
				return table + i;
			}

			// 다음 주소 계산
			i = (i + 1) % TABLE_SIZE;

			// 탐색 실패
			if (i == hashValue) 
				break;
		}

		// 탐색 실패
		printf("[%s] 탐색 실패: 찾는 값이 테이블에 없음\n", key);
		return NULL;
	}
};

// 선형 조사법의 삭제 연산
// 선형 조사법은 간단하다는 장점이 있으나, 오버플로우가 자주 발생하면 군집화 현상에 따라 탐색의 효율이 크게 저하될 수 있다
// 또 다른 문제가 있다, 항목을 삭제하는 함수를 생각해보자
// 선형 조사법에서 항목이 삭제되면 탐색이 불가능해질 수가 있다
// 예를 들어, 크기가 10인 해시 테이블과 h(k) = k mod 10 인 해시 함수를 가정하자
// 탐색키가 5, 15, 25 순서로 삽입되었다고 하면 모두 충돌이 발생하게 되고 해시 테이블의 내용은 (책 588p 그림) 처럼 된다
// 만약 이 상태에서 탐색키 15를 삭제하였다고 가정해보자, 탐색키 25를 탐색하면 중간이 비어있기 때문에 25가 있는 위치로 갈 수가 없다
// 이 문제를 어떻게 해결 할 수 있을까?
// 버켓을 몇 가지로 분류해야 한다, 
// 즉, 한 번도 사용하지 않은 버켓과 사용은 되었지만 현재는 비어있는 버켓, 현재 사용 중인 버켓으로 분류하여야 한다
// 탐색 함수에서는 한 번도 사용이 안 된 버켓을 만나야만이 탐색이 중단되도록 하여야 한다



// 이차 조사법 (quadratic probing)
/*
	이차 조사법은 선형 조사법과 유사하지만, 충돌 발생 시 다음에 조사할 위치를 다음 식에 의하여 결정한다

	(h(k)+i*i) mod M  for  i=0, 1, ..., M-1

	따라서 조사되는 위치는 다음과 같이 된다

	h(k), h(k)+1, h(k)+4, h(k)+9, ... mod M

	여기서 주의할 것은 모든 위치를 조사하게 만들려면 여전히 테이블 크기는 소수여야 한다는 점이다
	이 방법은 선형 조사법에서의 문제점인 군집화 현상을 크게 완화시킬 수 있다
	이 방법도 2차 집중 문제를 일으킬 수 있지만 1차 집중처럼 심각한 것은 아니다
	2차 집중의 이유는 동일한 위치로 사상되는 여러 탐색키들이 같은 순서에 의하여 빈 버켓을 조사하기 때문이다
	이것은 다음에 소개할 이중 해싱법으로 해결할 수 있다

	이차 조사법은 다음에 조사할 위치를 계산하는 부분만 다음과 같이 변경시키면 된다 (55행, 90행)
	inc = inc+1;
	i=(i+inc*inc) % TABLE_SIZE
*/

// 이중 해싱법 (double hashing)
/*
	이중 해싱법 또는 재해싱(rehashing) 은 오버플로우가 발생함에 따라 항목을 저장할 다음 위치를 결정할 때
	원래 해시 함수와 다른 별개의 해시 함수를 이용하는 방법이다
	이 방법은 항목들을 해시 테이블에 보다 균일하게 분포시킬 수 있으므로 효과적인 방법이라 할 수 있다

	선형 조사법과 이차 조사법은 충돌이 발생했을 경우에 해시 함수값에 어떤 값을 더해서 다음 위치를 얻는다
	선형 조사법에서는 더해지는 값이 1이고, 이차 조사법에서는 j^2 이 된다

	따라서 해시 함수값이 같으면 차후에 조사되는 위치도 같게 된다
	예를 들어, 크기가 10인 해시 테이블에서 제산 함수를 해싱 함수로 사용한다고 할 때
	15, 25는 이차 조사법에서 5, 6, 9, 14... 와 같은 조사 순서를 생성한다

	이중 해싱법에서는 탐색키를 참조하여 더해지는 값이 결정된다
	따라서 해시 함수값이 같더라도 탐색키가 다르면 서로 다른 조사 순서를 갖는다
	따라서 이중 해싱법은 이차집중을 피할 수 있다

	두 번째 해시 함수는 조사 간격을 결정하게 된다, 일반적인 형태는 다음과 같다

	step = C-(k mod C) = 1+k mod C

	이런 형태의 함수는 [1...C] 사이의 값을 생성한다
	충돌이 발생했을 경우, 조사되는 위치는 다음과 같이 된다

	h(k), h(k)+step, h(k)+2*step, h(k)+3*step ... mod M

	C는 보통 테이블의 크기인 M보다 약간 작은 소수이다
	이중 해싱에서는 보통 집중 현상이 매우 드물다,
	이유는 같은 버켓과 같은 탐색 순서를 가지는 요소들이 거의 없기 때문이다
*/
