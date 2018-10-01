#pragma once

#include "Node.h"
#include "hashFunctions.h"

class HashChainMap
{
private:
	// 데이터 멤버는 연결 리스트의 헤더 포인터의 배열이 됨(Node*)
	Node* table[TABLE_SIZE];

public:
	// 초기에는 모든 연결 리스트의 헤더가 NULL 이 되어야 함
	HashChainMap()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			table[i] = NULL;
		}
	}

	// 맵 전체의 내용을 화면에 출력함
	void display()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			printf("[%2d] ", i);

			// 연결 리스트이 각 노드를 방문하기 위한 다음 코드를 유의할 것
			for (Node* p = table[i]; p != NULL; p = p->getLink())
				printf("%10s", p->getKey());

			printf("\n");
		}
	}

	// 체인법을 이용하여 테이블에 키를 삽입
	// 체이닝에 의한 레코드 삽입 함수
	void addRecord(Node* n)
	{
		// 탐색키에 대하여 해시 주소 hashValue 를 계산
		int hashValue = hashFunction(n->getKey());
		
		for (Node* p = table[hashValue]; p != NULL; p = p->getLink())
		{
			// 해당 버켓에 연결 리스트로 들어 있는 노드 p에 대해, p가 현재 검색 키와 동일하면
			if (p->equal(n->getKey()))
			{
				// 삽입 연산 : 저장하려는 키가 이미 들어 있으므로 저장하지 않음
				printf("이미 탐색키가 저장되어 있음\n");
				delete n;
				return;
			}
		}

		// 삽입 연산 : 이미 저장되어 있지 않으면 리스트에 저장
		// 삽입 연산 : 연산을 간편하게 하기 위해 새로운 노드를 헤더 포인터에 삽입
		n->setLink(table[hashValue]);
		table[hashValue] = n;
	}

	// 체인법을 이용하여 테이블에 저장된 키를 탐색
	// 체이닝에 의한 레코드 검색 함수
	void searchRecord(const char* key)
	{
		// 탐색키에 대하여 해시 주소 hashValue 를 계산
		int hashValue = hashFunction(key);

		for (Node* p = table[hashValue]; p != NULL; p = p->getLink())
		{
			// 해당 버켓에 연결 리스트로 들어 있는 노드 p에 대해, p가 현재 검색 키와 동일하면
			if (p->equal(key))
			{
				// 탐색 연산 : 탐색 성공 메시지를 출력하고 반환
				printf("탐색 성공 ");
				p->display();
				return;
			}
		}

		// 탐색 실패
		printf("탐색 실패 : %s\n", key);
	}
};

// 체이닝
// 체이닝은 하나의 버켓에 여러 개의 레코드를 저장할 수 있도록 하는 방법이다
// 버켓은 여러 가지 방법으로 구현될 수 있겠지만 저장할 항목의 수를 예측할 수 없으므로 연결 리스트로 구현하는 것이 적절할 것이다
// 이와 같은 오버플로우 해결 방법을 체이닝(chaining) 이라고 한다

// 다음은 크기가 7인 해시 테이블에 h(k) = k mod 7의 해시 함수를 이용해서 8, 1, 9, 6, 13 을 삽입할 때에의 체이닝에 의한 충돌 처리를 보여준다
/*
	8, 1, 9, 6, 13

	1단계 (8 저장)  : h(8) = 8 mod 7 = 1(저장)
	2단계 (1 저장)  : h(1) = 1 mod 7 = 1(충돌) -> 새로운 노드 생성 및 저장
	3단계 (9 저장)  : h(9) = 9 mod 7 = 2(저장)
	4단계 (6 저장)  : h(6) = 6 mod 7 = 6(저장)
	5단계 (13 저장) : h(13) = 13 mod 7 = 6(충돌) -> 새로운 노드 생성 및 저장
*/

// 체이닝 항목을 검색하거나 삽입하고자 하면 키 값의 버켓에 해당하는 연결 리스트에서 독립적으로 탐색이나 삽입이 이루어진다
// 체이닝은 해시 테이블을 연결 리스트로 구성하므로 필요한 만큼의 메모리만 사용하게 되어 공간적 사용 효율이 매우 우수하다
// 또한 오버플로우가 발생할 경우에도 해당 버켓에 할당된 연결 리스트만 처리하게 되므로 수행 시간 면에서도 매우 효율적이다