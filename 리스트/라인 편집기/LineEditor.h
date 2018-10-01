#pragma once

// 최종적인 라인 편집기 클래스 LineEditor는 LinkedList를 상속하여 만든다
#include "LinkedList.h"

class LineEditor :public LinkedList
{
public:
	// 화면에 보기 좋게 출력
	void Display(FILE* fp = stdout)
	{
		int i = 0;

		for (Node* p = getHead(); p != NULL; p = p->getLink(), i++)
		{
			// stderr 표준오류
			// Windows에서는 stdout와 stdree가 동일하다 (자세한건 인터넷을 참고한다)
			fprintf(stderr, "%3d: ", i);
			p->display(fp);
		}

		//while (getchar() != '\n');
	}

	// 한 라인 입력 처리
	void InsertLine()
	{
		int position;
		char line[MAX_CHAR_PER_LINE];

		printf(" 입력행 번호: ");
		scanf("%d", &position);

		printf(" 입력행 내용: ");
		// 엔터키 처리
		//fflush(stdin); // 이 함수를 써도 \n(개행문자)가 안사라진다
		// 그래서 표준 입력 버퍼에 데이터가 채워지는 순간이 키보드의 '\n'(Enter) 가 입력되는 때임을 감안한다면
		// 다음과 같은 방법으로 버퍼에 남아있는 데이터를 없앨 수 있다
		while (getchar() != '\n');
		scanf("%s", line);
		//fgets(line, MAX_CHAR_PER_LINE, stdin);

		insert(position, new Node(line));
	}

	// 한 라인 삭제 처리
	void DeleteLine()
	{
		printf(" 삭제행 번호: ");
		int position;
		scanf("%d", &position);

		delete remove(position);

		//while (getchar() != '\n');
	}

	// 한 라인 변경 처리
	void ReplaceLine()
	{
		int position;
		char line[MAX_CHAR_PER_LINE];

		printf(" 변경행 번호: ");
		scanf("%d", &position);

		printf(" 변경행 내용: ");
		// 엔터키 처리
		while (getchar() != '\n');
		//fflush(stdin);
		fgets(line, MAX_CHAR_PER_LINE, stdin);

		replace(position, new Node(line));
	}

	// 파일 로드
	void LoadFile(const char* fname)
	{
		FILE* fp = fopen(fname, "r");

		if (fp != NULL)
		{
			char line[MAX_CHAR_PER_LINE];

			while (fgets(line, MAX_CHAR_PER_LINE, fp))
			{
				insert(size(), new Node(line));
			}
			printf("파일을 성공적으로 읽어왔습니다!\n");
			fclose(fp);
		}
	}

	// 파일 저장
	void StoreFile(const char* fname)
	{
		FILE* fp = fopen(fname, "w");

		if (fp != NULL)
		{
			Display(fp);
			fclose(fp);
		}
	}
};