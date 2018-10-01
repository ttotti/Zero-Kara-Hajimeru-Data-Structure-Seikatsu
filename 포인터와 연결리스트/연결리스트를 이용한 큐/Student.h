#pragma once
#include <cstdio>
#include <cstdlib>
#include <string>

#define MAX_STRING 100

class Student
{
private:
	int id; // 학번
	char name[MAX_STRING]; // 이름
	char dept[MAX_STRING]; // 학과

public:
	Student(int i = 0, char* n = "", char* d = "") { set(i, n, d); }
	~Student() {}

	void set(int i,char* n,char* d)
	{
		id = i;
		strcpy(name, n);
		strcpy(dept, d);
	}

	void display()
	{
		printf("학번 : %d 성명 : %s 학과 : %s\n", id, name, dept);
	}
};