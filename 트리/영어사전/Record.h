#pragma once

// Record.h 사전을 위한 레코드 클래스
#include <cstdio>
#include <cstring>

#define MAX_WORD_SIZE 40
#define MAX_MEANING_SIZE 200

class Record
{
	// 단어 : 키 필드
	char word[MAX_WORD_SIZE];
	// 단어의 의미 : 키 필드가 아님
	char meaning[MAX_MEANING_SIZE];

public:
	Record(const char* w = "", const char* m = "")
	{
		set(w, m);
	}

	void set(const char* w, const char* m)
	{
		strcpy_s(word, w);
		strcpy_s(meaning, m);
	}

	// 비교 함수
	// compare(char* w) 는 현재 레코드의 word 필드와 문자열 w를 비교한다
	// 문자열의 복사에는 strcpy() 함수를 문자열 비교에는 strcmp() 함수를 사용한다
	// strcmp() 함수는 두 문자열이 같으면 0을 다르면 두 단어의 사전적 순서에 따라 양수와 음수를 반환한다(자세한건 문자열 처리 함수의 매뉴얼 참고)
	int compare(Record* n) { return compare(n->word); }
	int compare(char* w) { return strcmp(w, word);}

	// 의미를 이용한 검색에는 compareMeaning(char* m) 을 사용하는데 meaning 필드와 문자열 m을 비교한 결과를 반환한다
	int compareMeaning(char* m) { return strcmp(meaning, m); }

	// 단어 : 의미 형태로 화면에 출력한다
	void display() { printf(" %12s : %-40s\n", word, meaning); }

	// copy(Record* r) 연산은 레코드 r의 내용을 자신에 복사한다
	void copy(Record* n) { set(n->word, n->meaning); }
};