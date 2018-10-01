#pragma once

#include <cstdio>


void error(const char* message)
{
	printf("%s\n", message);
}

// 리스트는 스택과 큐와 같이 선형자료형 이지만 전단과 후단뿐만 아니라 중간에 있는 요소들에 대한 삽입이나 삭제연산을 허용한다
// 따라서 리스트를 배열로 구현하면 비효율적인 공간크기와 중간 삽입 또는 중간 삭제 시 많은 자료의 이동이 필요하다
// 이를 해결하기 위해 연결리스트를 사용하여 리스트를 구현할 수 있다

#define MAX_LIST_SIZE 100

class ArrayList
{
private:
	int data[MAX_LIST_SIZE]; // 실제로 항목의 값들이 들어감
	int length;				 // 현재 리스트 내의 항목들의 개수
							 // length 는 항상 데이터가 비어있는곳에 위치한다 

public:
	// 생성자 ==> length 을 초기화
	ArrayList(void) { length = 0; }

	// 공백 및 포화 상태 검사
	// length 가 0 이면 리스트에 데이터가 없음
	// length 가 최대 배열 수와 같으면 공간 꽉참
	bool isEmpty() { return length == 0; }
	bool isFull() { return length == MAX_LIST_SIZE; }

	// 삽입 연산 : 리스트의 pos번째에 항목 e 추가
	void insert(int pos, int e)
	{
		// 리스트에 공간이 충분한지 검사하고
		// 함수의 안전한 사용을 위해 입력된 pos 위치가 유효한지를 검사하는 코드를 추가하였다
		// 유효한 pos의 범위는 0부터 length까지이다 리스트의 맨 끝에도 자료를 추가할 수 있어야 한다
		if (!isFull() && pos >= 0 && pos <= length)
		{
			// 먼저 데이터를 한 칸씩 밀고
			for (int i = length; i > pos; i--)
			{
				data[i] = data[i - 1];
			}
			// pos에 e를 복사하고
			data[pos] = e;
			// 리스트 항목의 개수 증가
			length++;
		}
		else error("포화상태 오류 또는 삽입 위치 오류");
	}

	// 삭제 연산 : pos번째에 항목을 리스트에서 제거
	void remove(int pos)
	{
		// 리스트가 비어있는지 확인하고
		// 삭제하고자 하는 위치가 유효한 위치인지를 검사하는 코드를 추가했다
		// 유효한 pos의 범위는 0부터 length-1 까지 이다
		if (!isEmpty() && pos >= 0 && pos < length)
		{
			// 먼저 데이터를 앞으로 당기고
			for (int i = pos + 1; i < length; i++)
			{
				data[i - 1] = data[i];
			}
			// 개수 감소
			length--;
		}
		else error("공백상태 오류 또는 삭제 위치 오류");
	}

	// pos번째 항목을 반환
	int getEntry(int pos) { return data[pos]; }

	// item 항목이 있는지 검사
	bool find(int item)
	{
		// 배열안에 데이터를 처음부터 데이터 갯수만큼 조사한다
		for (int i = 0; i < length; i++)
		{
			if (data[i] == item)
				return true;
		}

		return false;
	}

	// pos위치의 요소 변경
	void replace(int pos, int e)
	{
		data[pos] = e;
	}

	// 리스트의 길이 반환
	int size() { return length; }

	// 리스트의 항목을 출력
	void display()
	{
		printf("[배열로 구현한 리스트 전체 항목 수 = %2d] : ", size());
		for (int i = 0; i < length; i++)
		{
			printf("[%2d]", data[i]);
		}
		printf("\n");
	}

	// 모든 요소 제거
	void clear() { length = 0; }
};