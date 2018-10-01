#pragma once

// 하나의 고객 정보를 관리하기 위한 클래스
struct Customer
{
	int id; // 고객 번호
	int tArrival; // 고객이 도착한 시각
	int tService; // 이 고객의 서비스에 필요한 시간

	Customer(int i = 0, int tArr = 0, int tServ = 0)
		:id(i), tArrival(tArr), tService(tServ){}
};