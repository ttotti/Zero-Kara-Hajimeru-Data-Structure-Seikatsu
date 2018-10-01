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
	// 입력
	int nSimulation; // 시뮬레이션 할 최대 인원
	double probArrival; // 단위 시간에 등록하는 학생 수

	//출력
	int MeetingNumber; // 전체 미팅횟수
	int m_totalWaitTime; // 전체 남자 대기시간
	int f_totalWaitTime; // 전체 여자 대기시간

public:
	// 남, 여 큐 리스트
	Deque m_Deq;
	Deque f_Deq;
	// 미팅 주선에 성공한 큐 리스트
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
	printf("시뮬레이션 할 최대 인원을 입력하세요(예: 100): ");
	scanf("%d", &nSimulation);
	printf("단위시간에 등록하는 학생 수를 입력하세요(예: 0.5): ");
	scanf("%lf", &probArrival);
}

void Simulation::InputData(int time)
{
	Students s(time, RandomGender());
	printf("학생: %d번, 성별: %s  입장\n", s._id, s._gender);
	if (s._gender == "남")
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
		g = "남";
		return g;
	}
	else
	{
		g = "여";
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

	int clock = 0; // 현재 시각
	int m_serviceTime = 0; // 남자의 대기시간
	int f_serviceTime = 0; // 여자의 대기시간

	while (clock < nSimulation)
	{
		clock++;
		printf("현재시각=%d\n", clock);

		if (IsNewPeople())
			InputData(clock);

		// 남자 리스트나 여자 리스트에 데이터가 없으면 생길때까지 기다린다
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
			MeetingNumber++; // 미팅 주선 횟수
		}
	}
}

void Simulation::printStat()
{
	printf("=====================================\n");
	printf("미팅 주선에 성공한 커플의 쌍의 번호 : ");
	while (!success_Deq.isEmpty())
	{
		Students m = success_Deq.delectfront();
		Students f = success_Deq.delectfront();
		printf("(%d번,%d번) ", m._id, f._id);
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
	printf("\n남은 남자 수: %d\n", false_m);
	printf("남은 여자 수: %d\n", false_f);
	printf("전체 미팅 주선 횟수: %d\n", MeetingNumber);
	printf("남학생의 평균 대기 시간: %-5.2lf분\n", (double)m_totalWaitTime / MeetingNumber);
	printf("여학생의 평균 대기 시간: %-5.2lf분\n", (double)f_totalWaitTime / MeetingNumber);
	printf("\n");
}
