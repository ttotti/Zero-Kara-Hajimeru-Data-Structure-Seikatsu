#include <cstdio>
#include <cstring>

// 생일 클래스
class Birthday
{
public:
	int month;
	int date;
};

// 학생 클래스
class Student
{
public:
	char name[80];
	Birthday bDay; // 생일 객체 포함
};

int main()
{
	// 학생 객체 30개 생성
	Student students[30];

	// 학생 이름 초기화
	strcpy(students[0].name, "Lim-ttotti");

	// 학생클래스 안에 있는 생일 객체를 통해 생일 클래스의 멤버를 사용할수있다
	students[0].bDay.month = 10;
	students[0].bDay.date = 28;

	return 0;
}