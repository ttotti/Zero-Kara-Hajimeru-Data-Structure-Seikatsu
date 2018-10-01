#pragma once

// �� ���� ������ �����ϰ� ó���ϴ� �׸� Ŭ����

#include <cstdio>
#include <cstring>

#define MAX_CHAR_PER_LINE 1000

class Line
{
private:
	char data[MAX_CHAR_PER_LINE];
	
public:
	// ������ : ������ ���ڿ� �ʱ�ȭ
	Line(const char* line = "") { strcpy(data, line); }

	// ��� �Լ� : ȭ���̳� ���Ͽ� ����� �� ����
	void display(FILE* fp = stdout) { fprintf(fp, "%s\n", data); }

	// �� �Լ� : �� ������ str ���ڿ��� ���������� �˻�
	bool hasData(char* str) { return strcmp(str, data) == 0; }
};
