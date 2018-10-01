#pragma once

#include <cstdio>
#include <cstring>

// 탐색키의 최대 길이
#define KEY_SIZE 64
// 탐색키와 관련된 정보
#define VALUE_SIZE 64

// 먼저 해시 맵에 저장할 레코드를 정의해야 한다
// 레코드는 key와 문자열 value 를 갖도록 한다
class Record
{
private:
	// 키 필드 (사전의 경우 "단어")
	char key[KEY_SIZE];
	// 키와 관련된 자료 ("의미")
	char value[VALUE_SIZE];

public:
	Record(const char* k = "", const char* v = "") { set(k, v); }

	// 문자열 복사 함수를 사용해 key와 value 를 설정함
	void set(const char* k, const char* v = "")
	{
		strcpy(key, k);
		strcpy(value, v);
	}

	// 레코드 초기화는 key 에 "" 를 넣음 (key[0] == '\0' 와 동일)
	void reset() { set("", ""); }

	// 공백 상태 검사 공백 상태는 (key[0] == '\0'인 경우임)
	bool isEmpty() { return key[0] == '\0'; }

	// k와 key가 같으면 true 반환, 아니면 false 반환
	bool equal(const char* k) { return strcmp(k, key) == 0; }

	// 현재 레코드를 화면에 출력
	void display() { printf("%20s = %s\n", key, value); }

	char* getKey() { return key; }
};

// 해싱의 오버플로우 처리 방법
// 해싱에서 오버플로우를 잘 처리하는 것은 매우 중요하다, 이러한 오버플로우를 처리 방법은 다음의 두 가지로 나눌 수 있다
/*
	1. 선형 조사법(linear probing): 충돌이 일어나면 해시 테이블의 다른 위치에 찾아 항목을 저장한다

	2. 체이닝(chaining): 해시 테이블의 하나의 위치가 여러 개의 항목을 저장할 수 있도록 해시 테이블의 구조를 변경한다
*/

// 선형 조사법
/*
	선형 조사법은 해싱 함수로 구한 버켓에 빈 슬롯이 없으면 그 다음 버켓에서 빈 슬롯이 있는지를 찾는 방법이다
	이때 비어 있는 공간을 찾는 것을 조사(probing) 이라고 하는데, 여러 가지의 조사 방법이 가능하다

	만약 ht[k] 에서 충돌이 발생했다고 하자, 선형 조사법은 먼저 ht[k+1] 이 비어 있는지를 살핀다
	비어있지 않다면 다음 위치인 ht[k+2] 를 살펴보는데, 이런 식으로 비어있는 공간이 나올 때까지 계속 조사하는 방법이다
	만약 테이블의 끝에 도달하게 되면 다시 테이블의 처음으로 간다
	처음 충돌이 났던 곳으로 다시 돌아오면 테이블이 가득 찬 것이 된다
	따라서 조사되는 위치는 다음과 같은 순서이다

	h(k), h(k)+1, h(k)+2, h(k)+3, ... mod M

	크기가 7인 해시 테이블에서 해시 함수로 h(k) = k mod 7 을 사용한다고 가정하고
	8, 1, 9, 6, 13 의 순으로 탐색키를 저장해보자
	아래에서 살펴본 바와 같이 선형 조사법은 오버플로우가 발생하면 항목의 저장을 위하여 빈 버켓을 순차적으로 탐색해 나간다

	1단계 (8 저장)  : k(8) = 8 mod 7 = 1(저장)
	2단계 (1 저장)  : h(1) = 1 mod 7 = 1(충돌) -> (h(1)+1) mod 7 = 2(저장)
	3단계 (9 저장)  : h(9) = 9 mod 7 = 2(충돌) -> (h(9)+1) mod 7 = 3(저장)
	4단계 (6 저장)  : h(6) = 6 mod 7 = 6(저장)
	5단계 (13 저장) : h(13) = 13 mod 7 = 6(충돌) -> h((13)+1) mod 7 = 0(저장)
*/