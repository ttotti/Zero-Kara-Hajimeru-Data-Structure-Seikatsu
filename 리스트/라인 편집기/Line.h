#pragma once

// 한 줄의 문장을 저장하고 처리하는 항목 클래스

#include <cstdio>
#include <cstring>

#define MAX_CHAR_PER_LINE 1000

class Line
{
private:
	char data[MAX_CHAR_PER_LINE];
	
public:
	// 생성자 : 라인의 문자열 초기화
	Line(const char* line = "") { strcpy(data, line); }

	// 출력 함수 : 화면이나 파일에 출력할 수 있음
	void display(FILE* fp = stdout) { fprintf(fp, "%s\n", data); }

	// 비교 함수 : 이 라인이 str 문자열과 동일한지를 검사
	bool hasData(char* str) { return strcmp(str, data) == 0; }
};
