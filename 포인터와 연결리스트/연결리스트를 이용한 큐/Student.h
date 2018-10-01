#pragma once
#include <cstdio>
#include <cstdlib>
#include <string>

#define MAX_STRING 100

class Student
{
private:
	int id; // �й�
	char name[MAX_STRING]; // �̸�
	char dept[MAX_STRING]; // �а�

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
		printf("�й� : %d ���� : %s �а� : %s\n", id, name, dept);
	}
};