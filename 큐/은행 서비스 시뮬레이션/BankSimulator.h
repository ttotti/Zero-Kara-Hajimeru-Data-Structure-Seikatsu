#pragma once

#include "CustomerQueue.h"

class BankSimulator
{
private:
	int nSimulation;		// �Է�: ��ü �ùķ��̼� Ƚ��
	double probArrival;		// �Է�: �����ð��� �����ϴ� ��� �� ��
	int tMaxService;		// �Է�: �� ���� ���� �ִ� ���� �ð�

	int totalWaitTime;		// ���: ������ ��ٸ� ��ü�ð�
	int nCustomers;			// ���: ��ü �� ��
	int nServedCustomers;	// ���: ���� ���� ����

	CustomerQueue que;		// �� ��� ť

	// ���� ���ڸ� �����Ͽ� �� ���� ���ο� ���� �ð� �ڵ� ���� �ڵ�
	double Random() 
	{ 
		return rand() / (double)RAND_MAX;
	}
	bool IsNewCustomer() { return Random() > probArrival; }
	int RandServiceTime() { return (int)(tMaxService*Random()) + 1; }

	// ���� ������ ���� ť�� ����
	void InsertCustomer(int arrivalTime)
	{
		Customer a(++nCustomers, arrivalTime, RandServiceTime());
		printf(" �� %d �湮 (���� �ð� %d��)\n", a.id, a.tService);
		que.enqueue(a);
	}

public:
	BankSimulator()
		:nCustomers(0),totalWaitTime(0),nServedCustomers(0){}

	// �ùķ��̼� �Ķ���� �Է�
	void readSimlationParameters()
	{
		printf("�ùķ��̼� �� �ִ� �ð�(��:10) = ");
		scanf("%d", &nSimulation);
		printf("�����ð��� �����ϴ� �� ��(��:0.7) = ");
		scanf("%lf", &probArrival);
		printf("�� ���� ���� �ִ� ���� �ð�(��:5) = ");
		scanf("%d", &tMaxService);
		printf("================================================\n");
	}

	// �ùķ��̼� ����
	void run()
	{
		int clock = 0; // ���� �ð�
		int serviceTime = -1; // ó���� �ɸ��� �ܿ� �ð�

		while (clock < nSimulation)
		{
			clock++;
			printf("����ð�=%d\n", clock);

			if (IsNewCustomer()) // ���ο� ���� ���������� ť�� ����
				InsertCustomer(clock);

			if (serviceTime > 0)
				serviceTime--; // ���� �� ���� ��
			else
			{
				if (que.isEmpty())
					continue; // ��ٸ��� �� ����

				Customer a = que.dequeue(); // ���� ���� �� ��
				nServedCustomers++; // ���� �� �� ��

				totalWaitTime += clock - a.tArrival; // �� ���ð�
				printf(" �� %d ���� ���� (���ð�:%d��)\n", a.id, clock - a.tArrival);
				serviceTime = a.tService - 1;
			}
		}
	}

	// �ùķ��̼� ����� ����Ѵ�
	void printStat()
	{
		printf("================================================\n");
		printf(" ���� ���� ���� = %d\n", nServedCustomers);
		printf(" ��ü ��� �ð� = %d��\n", totalWaitTime);
		printf(" ���񽺰� ��մ��ð� = %-5.2f��\n", (double)totalWaitTime / nServedCustomers);
		printf(" ���� ��� �� �� = %d\n", nCustomers - nServedCustomers);
	}
};