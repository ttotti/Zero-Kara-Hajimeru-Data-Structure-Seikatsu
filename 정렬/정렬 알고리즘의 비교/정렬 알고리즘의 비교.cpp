




// 정렬 알고리즘의 비교
// 최적 정렬 방법은 정렬해야할 레코드의 수, 크기, 타입 등에 따라 달라지므로
// 각 정렬 장단점을 잘 이해하여 적합한 정렬 방법을 사용할 수 있어야 한다
// 다음은 정수 60,000 개에 대한 각 알고리즘 별 실행 시간 측정 결과를 보여준다

// 정렬 방법의 성능 비교
/*
	알고리즘       최선          평균           최선
	
	삽입 정렬      O(n)          O(n^2)        O(n^2)
	선택 정렬      O(n^2)        O(n^2)        O(n^2)
	버블 정렬      O(n^2)        O(n^2)        O(n^2)
	셸 정렬        O(n)          O(n^1.5)      O(n^1.5)
	퀵 정렬        O(n log2 n)   O(n log2 n)   O(n^2)
	힙 정렬        O(n log2 n)   O(n log2 n)   O(n log2 n)
	합병 정렬      O(n log2 n)   O(n log2 n)   O(n log2 n)
	기수 정렬      O(dn)         O(dn)         O(dn)
*/

// 정렬 알고리즘별 실험 결과(정수 60,000 개)
/*
	알고리즘    실행 시간(단위 : sec)

	삽입 정렬     7.438
	선택 정렬     10.842
	버블 정렬     22.894
	셸 정렬       0.056
	힙 정렬       0.034
	합병 정렬     0.026
	퀵 정렬       0.014
*/