#include <cstdio>
#include <cstring>

// ���� Ŭ����
class Birthday
{
public:
	int month;
	int date;
};

// �л� Ŭ����
class Student
{
public:
	char name[80];
	Birthday bDay; // ���� ��ü ����
};

int main()
{
	// �л� ��ü 30�� ����
	Student students[30];

	// �л� �̸� �ʱ�ȭ
	strcpy(students[0].name, "Lim-ttotti");

	// �л�Ŭ���� �ȿ� �ִ� ���� ��ü�� ���� ���� Ŭ������ ����� ����Ҽ��ִ�
	students[0].bDay.month = 10;
	students[0].bDay.date = 28;

	return 0;
}