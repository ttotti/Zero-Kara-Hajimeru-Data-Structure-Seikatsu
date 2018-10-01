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
	
	// ������
	Car() {};
	Car(int s, char* n, int g)
		:speed(s), gear(g)
	{
		strcpy(name, n);
	}
	~Car() {};

	void changeGear(int g = 4) { gear = g; } // ����Ʈ �Ű����� // �� �Լ��� �Ű����� ���� �����ϸ� g�� 4�� �ڵ����� ���ԵǾ� �����Ѵ�
	void speedUP() { speed += 5; }
	void display() { printf("[%s] : ��� = %d�� �ӵ� = %dkmph\n", name, gear, speed);}
	void whereAmI() { printf("��ü �ּ� = %x\n", this); }

	// �ӵ��� ������ 0, b���� ������ ���, b���� ������ ������ ��ȯ
	int Compare(Car& b)
	{
		return speed - b.speed;
	}

};

class SportCar :public Car
{
public:
	// ������
	SportCar() {};
	SportCar(int s, char* n, int g)
		:Car(s, n, g)
	{
	}

public:
	bool bTurbo;

	void SetTurbo(bool bTur) { bTurbo = bTur;}

	// �������̵� �θ�Ŭ������ �ִ� �Լ��� ������ �Ǿ���
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
		printf("a�� b�� �ӵ��� ����\n");
	else if (a.Compare(b) > 0)
		printf("a�� b���� �ӵ��� ����\n");
	else
		printf("a�� b���� �ӵ��� ����\n");

	SportCar a2(30, "mySportCar", 6), b2(10, "mySportCar", 10);
	
	if (a2.Compare(b2) == 0)
		printf("a�� b�� �ӵ��� ����\n");
	else if (a2.Compare(b2) > 0)
		printf("a�� b���� �ӵ��� ����\n");
	else
		printf("a�� b���� �ӵ��� ����\n");

	return 0;
}