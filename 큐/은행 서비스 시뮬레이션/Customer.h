#pragma once

// �ϳ��� �� ������ �����ϱ� ���� Ŭ����
struct Customer
{
	int id; // �� ��ȣ
	int tArrival; // ���� ������ �ð�
	int tService; // �� ���� ���񽺿� �ʿ��� �ð�

	Customer(int i = 0, int tArr = 0, int tServ = 0)
		:id(i), tArrival(tArr), tService(tServ){}
};