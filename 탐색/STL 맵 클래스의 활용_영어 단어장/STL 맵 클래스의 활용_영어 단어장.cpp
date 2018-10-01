
// 표준 템플릿 라이브러리는 맵 클래스를 제공한다
// 맵은 탐색을 위한 자료구조로 지금까지 맵을 구현할 수 있는 다양한 방법을 공부했다
// 우리는 STL의 맵이 어떤 방법으로 구현되었는지는 관심을 갖지 않는다
// 그리고 탐색을 수행하는 자료의 특성에 따라 효율적인 구현하는 방법이 달라질 수 있다

// 여기서는 STL의 맵을 이용하여 간단한 영어 단어장을 만들고 검색하는 방법을 소개한다
// STL의 맵을 사용하기 위해서는 해싱이나 이진 탐색 트리를 고려할 필요 없이 다음과 같이 헤더파일을 포함시키는 것만으로 충분하다

#include <cstdio>
#include <string> // string 클래스 사용 위함. <cstring> 이 아님!!
#include <map>    // STL의 map을 사용하기 위해 포함

using namespace std;

void main()
{
	// 맵에서는 기본적으로 키(key)와 값(value)이 정의되어야 한다
	// STL의 맵에서는 마찬가지로, 키를 위한 자료형과 값을 위한 자료형을 정해야 한다
	// 우리는 영어 단어장을 만들 것이므로 다음과 같이 자료형을 정한다
	/*
		1. 키(key)   : 영어 단어 -> string 객체
		2. 값(value) : 영어 단어에 대한 나만의 의미 -> string 객체
	*/
	// 문자열 저장을 위해 string 클래스를 사용한 것에 유의하라
	// string 클래스는 문자열을 낰타내기 위해 제공하는 클래스로 문자열의 저장과 처리에 필요한 속성과 연산들을 가지고 있는데
	// 문자열을 char 형 배열을 사용할 때 발생하는 여러 가지 문제를 해결하기 위해 제공한다
	// string 클래스를 사용하기 위해서는 <string> 을 포함하여야 한다

	// key와 value가 모두 string 객체인 map 객체 선언
	// 맵이 템플릿으로 제공되고 두 개의 자료형을 제공한다,
	// 첫 번째 자료형은 키(key)를 위한 것이고, 두 번째 값(value)을 위한 것이다
	map<string, string> myDic;

	// map 에 대한 반복자 선언
	// 맵에 들어있는 자료들을 순회하기 위해 STL의 반복자를 사용한다
	// STL에서는 컨테이너의 종류에 관계없이 요소들을 방문하게 하기 위하여 반복자라는 방식을 제공하는데
	// 반복자는 맵과 같은 컨테이너의 멤버를 가리키는 객체로 기존의 포인터와 비슷한 개념이지만
	// 흔히 일반화된 포인터라고 한다, 다음은 단어장의 레코드에 대한 반복자 객체 p를 선언하는 문장이다
	map<string, string>::iterator dp;

	// 8개의 단어, 숙어와 의미를 map 에 추가
	// 맵에 자료를 추가하기 위해 insert() 연산을 사용할 수도 있지만
	// 가장 간단한 방법은 인덱스 연산자[] 를 사용하는 것이다,
	// 이 방법이 더 간단하고 직관적인데, 다음과 같은 문장을 사용하여 단어-의미 쌍을 맵에 추가할 수 있다
	myDic["hello"]                  = "안녕하세요?";
	myDic["world"]                  = "아름다운 세상";
	myDic["data"]                   = "데이터";
	myDic["structure"]              = "구조, 구조체";
	myDic["list"]                   = "리스트";
	myDic["Pain past is pleasure"]  = "지나간 고통은 즐거움이다";
	myDic["Habit is second nature"] = "습관은 제 2의 천성이다";
	myDic["No pain no gain"]        = "고통 없이는 얻는 것도 없다";

	// 맵의 모든 항목을 출력함, 반복자를 이용할 것에 유의할 것,
	// 반복은 맵의 첫 번째 항목부터 마지막 항목까지 진행,
	// dp->first와 dp->second는 모두 string 객체임, 따라서 string 클래스의 c_str() 멤버 함수를 통해 char* 형을 반환받아 printf() 에서 출력함

	// 반복자를 사용하여 맵의 첫 번째 요소를 가리킨(begin() 함수 사용) 후에 관련 처리를 하고
	// 작업이 끝나면 반복자가 다음 요소를 가리키도록 증가시킨다(++p)
	// 반복자가 마지막 요소를 벗어나게 되면(end() 함수 사용) 작업을 끝내면 된다
	// 다음은 반복자를 이용해 맵에 들어있는 모든 레코드의 위치를 순회하고, 각 단어와 의미를 출력하는 코드이다

	// first와 second 란 멤버를 제공하는데, first 는 key 객체이며, second 는 value 객체이다
	// 우리가 만든 단어장 맵에서 이들은 모두 string 객체이다, 만약 printf()를 이용해 string 객체를 출력하기 위해서는
	// string 객체에서 char* 형의 포인터를 꺼내야 한다, 이것은 string 클래스의 c_str() 함수가 제공한다
	// 따라서 위의 코드는 맵의 모든 단어들을 보기 좋게 화면에 출력한다, cout을 이용하여 출력하려면 << 연산자로 string 객체를 따로 출력할 수도 있다
	// 그러나 이 경우에도 출력을 일정한 형식(줄 맞추기 등)으로 하려면 꽤 번거로운 코드가 필요하다
	for (dp = myDic.begin(); dp != myDic.end(); ++dp)
	{
		printf("%20s = %s\n", dp->first.c_str(), dp->second.c_str());
	}

	// 탐색 결과를 출력
	// 만약 탐색이 실패하면 앞의 반복문의 종료조건과 같이 p == myDic.end() 가 될 것이다
	// 그렇지 않으면 탐색을 성공한 것이다, 탐색 후 반복자 객체에서 값을 추출하는 부분은 앞의 반복문에서와 같다
	dp = myDic.find("structure");
	if (dp == myDic.end())
		printf(" 검색 실패 : 찾는 단어가 없습니다\n");
	else
		printf(" 검색 성공 : %s ---> %s\n", dp->first.c_str(), dp->second.c_str());

	dp = myDic.find("algorithm");
	if (dp == myDic.end())
		printf(" 검색 실패 : 찾는 단어가 없습니다\n");
	
	// 단어를 삭제한다, 삭제는 다음과 같이 두 가지 방법으로 할 수 있다
	/*
		myDic.erase("list")     - 방법 1. 키값으로 직접 삭제

		dp = myDic.find("list") - 방법 2. 검색 후 
		myDic.erase(dp)         - 검색된 해당 위치의 레코드 삭제
	*/
	// 맵에서 "list" 항목을 찾아 삭제
	myDic.erase("list");
	// 맵에서 "structure" 의 위치를 찾고, 이를 이용해 이 항목 삭제
	dp = myDic.find("structure");
	myDic.erase(dp);

	// 맵의 모든 항목을 출력함, 반복자를 이용할 것에 유의할 것,
	// 반복은 맵의 첫 번째 항목부터 마지막 항목까지 진행,
	// dp->first와 dp->second는 모두 string 객체임, 따라서 string 클래스의 c_str() 멤버 함수를 통해 char* 형을 반환받아 printf() 에서 출력함
	for (dp = myDic.begin(); dp != myDic.end(); ++dp)
	{
		printf("%20s = %s\n", dp->first.c_str(), dp->second.c_str());
	}
}

