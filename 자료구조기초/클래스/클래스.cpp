//#include <iostream>
#include <cstdio>
#include <cstring>

//using namespace std;

class Car
{
protected:
	int speed;
	char name[40];

public:
	int gear;
	
	// 생성자
	Car() {};
	Car(int s, char* n, int g)
		:speed(s), gear(g)
	{
		strcpy(name, n);
	}
	~Car() {};

	void changeGear(int g = 4) { gear = g; } // 디폴트 매개변수 // 이 함수를 매개변수 없이 선언하면 g에 4가 자동으로 대입되어 실행한다
	void speedUP() { speed += 5; }
	void display() { printf("[%s] : 기어 = %d단 속도 = %dkmph\n", name, gear, speed);}
	void whereAmI() { printf("객체 주소 = %x\n", this); }

	// 속도가 같으면 0, b보다 빠르면 양수, b보다 느리면 음수를 반환
	int Compare(Car& b)
	{
		return speed - b.speed;
	}

};

class SportCar :public Car
{
public:
	// 생성자
	SportCar() {};
	SportCar(int s, char* n, int g)
		:Car(s, n, g)
	{
	}

public:
	bool bTurbo;

	void SetTurbo(bool bTur) { bTurbo = bTur;}

	// 오버라이딩 부모클래스에 있는 함수가 재정의 되었다
	void speedUP()
	{
		if (bTurbo) speed += 20;
		else Car::speedUP();
	}
};

int main()
{
	Car k7(50, "K7", 1);

	k7.changeGear(6);
	k7.speedUP();
	k7.display();
	k7.whereAmI();

	SportCar Malibu(200, "MALIBU", 50);

	Malibu.bTurbo = true;
	Malibu.speedUP();
	Malibu.display();
	Malibu.whereAmI();

	Car a(30, "myCar", 3), b(50, "myCar2", 5);

	if (a.Compare(b) == 0)
		printf("a와 b의 속도가 같음\n");
	else if (a.Compare(b) > 0)
		printf("a가 b보다 속도가 빠름\n");
	else
		printf("a가 b보다 속도가 느림\n");

	SportCar a2(30, "mySportCar", 6), b2(10, "mySportCar", 10);
	
	if (a2.Compare(b2) == 0)
		printf("a와 b의 속도가 같음\n");
	else if (a2.Compare(b2) > 0)
		printf("a가 b보다 속도가 빠름\n");
	else
		printf("a가 b보다 속도가 느림\n");

	return 0;
}