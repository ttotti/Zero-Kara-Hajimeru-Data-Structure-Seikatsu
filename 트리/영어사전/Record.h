#pragma once

// Record.h ������ ���� ���ڵ� Ŭ����
#include <cstdio>
#include <cstring>

#define MAX_WORD_SIZE 40
#define MAX_MEANING_SIZE 200

class Record
{
	// �ܾ� : Ű �ʵ�
	char word[MAX_WORD_SIZE];
	// �ܾ��� �ǹ� : Ű �ʵ尡 �ƴ�
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

	// �� �Լ�
	// compare(char* w) �� ���� ���ڵ��� word �ʵ�� ���ڿ� w�� ���Ѵ�
	// ���ڿ��� ���翡�� strcpy() �Լ��� ���ڿ� �񱳿��� strcmp() �Լ��� ����Ѵ�
	// strcmp() �Լ��� �� ���ڿ��� ������ 0�� �ٸ��� �� �ܾ��� ������ ������ ���� ����� ������ ��ȯ�Ѵ�(�ڼ��Ѱ� ���ڿ� ó�� �Լ��� �Ŵ��� ����)
	int compare(Record* n) { return compare(n->word); }
	int compare(char* w) { return strcmp(w, word);}

	// �ǹ̸� �̿��� �˻����� compareMeaning(char* m) �� ����ϴµ� meaning �ʵ�� ���ڿ� m�� ���� ����� ��ȯ�Ѵ�
	int compareMeaning(char* m) { return strcmp(meaning, m); }

	// �ܾ� : �ǹ� ���·� ȭ�鿡 ����Ѵ�
	void display() { printf(" %12s : %-40s\n", word, meaning); }

	// copy(Record* r) ������ ���ڵ� r�� ������ �ڽſ� �����Ѵ�
	void copy(Record* n) { set(n->word, n->meaning); }
};