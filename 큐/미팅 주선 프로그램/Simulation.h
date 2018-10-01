#pragma once
//#include "Students.h"
//#include "Queue.h"
#include "Deque.h"
#include <iostream>
#include <Windows.h>

using namespace std;

class Simulation
{
private:
	// �Է�
	int nSimulation; // �ùķ��̼� �� �ִ� �ο�
	double probArrival; // ���� �ð��� ����ϴ� �л� ��

	//���
	int MeetingNumber; // ��ü ����Ƚ��
	int m_totalWaitTime; // ��ü ���� ���ð�
	int f_totalWaitTime; // ��ü ���� ���ð�

public:
	// ��, �� ť ����Ʈ
	Deque m_Deq;
	Deque f_Deq;
	// ���� �ּ��� ������ ť ����Ʈ
	Deque success_Deq;

public:
	Simulation()
		:MeetingNumber(0),m_totalWaitTime(0),f_totalWaitTime(0) {}
	void run();
	void InputData(int time);
	void inputParameter();
	bool IsNewPeople();
	char* RandomGender();
	double Random();
	void printStat();
};

void Simulation::inputParameter()
{
	printf("�ùķ��̼� �� �ִ� �ο��� �Է��ϼ���(��: 100): ");
	scanf("%d", &nSimulation);
	printf("�����ð��� ����ϴ� �л� ���� �Է��ϼ���(��: 0.5): ");
	scanf("%lf", &probArrival);
}

void Simulation::InputData(int time)
{
	Students s(time, RandomGender());
	printf("�л�: %d��, ����: %s  ����\n", s._id, s._gender);
	if (s._gender == "��")
		m_Deq.addrear(s);
	else
		f_Deq.addrear(s);
}

char* Simulation::RandomGender()
{
	int i;
	char* g;

	i = rand() % 2;

	if (i == 0)
	{
		g = "��";
		return g;
	}
	else
	{
		g = "��";
		return g;
	}
}

bool Simulation::IsNewPeople()
{
	return Random() > probArrival;
}

double Simulation::Random()
{
	return rand() / (double)RAND_MAX;
}

void Simulation::run()
{
	printf("=====================================\n");

	int clock = 0; // ���� �ð�
	int m_serviceTime = 0; // ������ ���ð�
	int f_serviceTime = 0; // ������ ���ð�

	while (clock < nSimulation)
	{
		clock++;
		printf("����ð�=%d\n", clock);

		if (IsNewPeople())
			InputData(clock);

		// ���� ����Ʈ�� ���� ����Ʈ�� �����Ͱ� ������ ���涧���� ��ٸ���
		if (m_Deq.isEmpty() && f_Deq.isEmpty())
		{
			continue;
		}

		if (m_Deq.isEmpty())
		{
			++f_totalWaitTime;
			continue;
		}
		else if (f_Deq.isEmpty())
		{
			++m_totalWaitTime;
			continue;
		}
		else
		{
			Students m = m_Deq.delectfront();
			Students f = f_Deq.delectfront();

			success_Deq.addrear(m);
			success_Deq.addrear(f);
			MeetingNumber++; // ���� �ּ� Ƚ��
		}
	}
}

void Simulation::printStat()
{
	printf("=====================================\n");
	printf("���� �ּ��� ������ Ŀ���� ���� ��ȣ : ");
	while (!success_Deq.isEmpty())
	{
		Students m = success_Deq.delectfront();
		Students f = success_Deq.delectfront();
		printf("(%d��,%d��) ", m._id, f._id);
	}
	int false_m = 0;
	int false_f = 0;
	while (!m_Deq.isEmpty())
	{
		m_Deq.delectfront();
		false_m += 1;
	}
	while (!f_Deq.isEmpty())
	{
		f_Deq.delectfront();
		false_f += 1;
	}
	printf("\n���� ���� ��: %d\n", false_m);
	printf("���� ���� ��: %d\n", false_f);
	printf("��ü ���� �ּ� Ƚ��: %d\n", MeetingNumber);
	printf("���л��� ��� ��� �ð�: %-5.2lf��\n", (double)m_totalWaitTime / MeetingNumber);
	printf("���л��� ��� ��� �ð�: %-5.2lf��\n", (double)f_totalWaitTime / MeetingNumber);
	printf("\n");
}
