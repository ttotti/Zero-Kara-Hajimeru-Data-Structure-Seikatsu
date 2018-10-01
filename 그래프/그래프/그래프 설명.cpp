


// 그래프

// 그래프(graph)는 요소들이 서로 복잡하게 연결되어 있는 관계를 표현하는 자료구조이다
// 예를 들어 지하철 노선도는 많은 역들이 어떻게 연결되어 있는지를 알려주며,
// 소셜 네트워크 서비스의 인맥 지도는 사람들의 복잡한 친구 관계를 그래프로 나타낸다
// 또한 전기회로도 그래프로 표현된다, 각 소자들이 어떻게 연결되어 있는지를 파악하고 회로가 제대로 동작하는지를 그래프로 분석할 수 있다
// 운영체제에서는 프로서스와 자원들이 어떻게 연관되어 있는지를 그래프로 나타내고 시스템의 효율이나 교착상태 유뮤 등을 분석한다
// 이와 같은 문제들은 공통적으로 다양한 객체들이 서로 연결되어 있는 구조를 갖는다
// 지금까지 공부했던 선형 자료구조들이나 트리를 그래프의 한 종류로 볼 수 있다
// 그래프와 관련된 다양한 문제를 연구하는 학문 분야를 "그래프 이론"이라 부른다

// 그래프의 역사

// 그래프는 수학의 한 분야로서 "수학자 오일러"에 의해 처음 창안되었다
// 오일러는 "모든 다리를 한번만 건너서 출발했던 장소로 돌아올 수 있는가" 라는 문제가 답이 없다는 것을 그래프 이론을 이용하여 증명하였다
// 오일러는 이 문제에서 핵심적이고 중요한 것은 "A, B, C, D"의 위치가 어떠한 관계로 연결 되었는가?" 라고 생각하고
// "위치" 라는 객체는 정점(vertex)으로, 위치간의 관계인 "다리"는 간선(edge) 으로 표현하여 그래프 문제로 변환하였다
// 오일러는 이러한 그래프에 존재하는 모든 간선을 한번만 통과하면서 처음 정점으로 되돌아오는 경로를 "오일러 경로" 라 정의하고
// 그래프의 모든 정점에 연결된 간선의 개수가 짝수일 때만 오일러 경로가 존재한다는 오일러의 정리를 증명하였다 (한붓그리기 참고)

// 그래프는 정점(vertex), 간선(edge) 들의 집합으로 구성된다
// 수학적으로는 G = (V, E) 와 같이 표시하며
// 여기서 V(G)는 그래프 G의 정점들의 집합, E(G)는 그래프 G의 간선들의 집합을 의미한다





// 그래프의 종류

// 그래프는 간선의 종류에 따라 몇가지로 구분된다
/*
	1. 무방향 그래프
		- 간선에 방향이 표시되지 않은 그래프를 무방향 그래프라 한다
		  하나의 간선은 양방향으로 갈수 있는 길을 의미하고 (A, B)와 (B, A)는 동일한 간선이 된다

	2. 방향 그래프
		- 간선에 방향성이 존재하는 그래프를 방향 그래프라 한다
		  간선은 보통 화살표로 표시되는데 일방통행 도로와 마찬가지로 한쪽 방향으로만 갈 수 있음을 의미한다
		  정점 A에서 정점 B로만 갈 수 있는 간선은 <A, B>로 표시한다, 방향 그래프에서 <A, B>와 <B, A>는 서로 다른 간선이다

	3. 가중치 그래프
		- 간선의 비용이나 가중치가 할당된 그래프를 "가중치 그래프" 또는 "네트워크" 라 한다
		  이제 간선은 두 정점간의 연결 유무뿐만 아니라 연결 강도까지 나타낼 수 있어 보다 복잡한 관계를 표현할 수 있다

	4. 부분 그래프
		- 그래프 G를 구성하는 정점의 집합 V(G)와 간선의 집합 E(G)의 부분 집합으로 이루어진 그래프를 "부분 그래프"라 한다
*/





// 그래프 용어

// 그래프에서 자주 사용되는 용어들을 살펴보자
/*
	1. 인접 정점
		- 간선에 의해 직접 연결된 정점을 말한다

	    - 그래프 G -
		   a - b
		   l   l  일경우 정점 a의 인접 정점은 정점 b와 정점 c 이다
		   c - d

	2. 정점의 차수
		- 그 정점에 연결된 간선의 수를 말한다
		  무방향 그래프에서는 정점에 인접한 정점의 수를 말하는데, 위의 (그래프 G)에서 정점 a는 차수가 2 이다
		  무방향 그래프에서는 모든 정점의 차수를 합하면 간선 수의 2배가 된다
		  이것은 하나의 간선이 두개의 정점에 인접하기 때문이다,

		  방향 그래프에서는 외부에서 오는 간선의 수를 "진입 차수"라 하고 외부로 향하는 간선의 수를 "진출 차수"라 한다

		- 그래프 H -
		  a <- b
		  l ->    일때 정점 a의 진입 차수가 1 진출 차수가 2 이다
		  V     
		  c

		  방향 그래프에 있는 정점의 진입 차수 또는 진출 차수의 합은 방향 그래프의 간선의 수가 된다

	3. 경로
		- 간선을 따라 갈 수 있는 길을 말하며, 정점의 나열로 표시된다
		  무방향 그래프에서 정점 s 로 부터 정점 e 까지의 경로는 정점의 나열 s, v1, v2, ... vk, e 로서 
		  나열된 정점들 간에는 반드시 간선 (s, v1), (v1, v2), ... ,(vk, e)가 존재해야 한다
		  위의 (그래프 G) 에서 a, b, d, c 는 경로지만 a, c, b, d 는 경로가 아니다 왜냐하면 (c, b)가 존재하지 않기 때문이다

	4. 경로의 길이
		- 경로를 구성하는데 사용된 간선의 수를 말한다

	5. 단순 경로와 사이클
		- 경로 중에서 반복되는 간선이 없는 경로를 "단순 경로"라 한다
		  그리고 단순 경로의 시작 정점과 종료 정점이 같다면 이러한 경로를 "사이클"이라 한다
		  위의 (그래프 G) 에서 경로 b, a, c, d 는 단순 경로고 경로 b, a, b 는 단순 경로가 아니다
		  그리고 (그래프 I)의 경로 a, c, d, a 는 사이클이 된다 또한 (그래프 H) 의 a, b, a 도 사이클이 된다

		- 그래프 I -
		  a  -  b
		  l *   l
		  l  *  l
		  c  -  d

	6. 연결 그래프
		- (그래프 G)의 모든 정점들 사이에 경로가 존재하면 G를 "연결 그래프"라 부른다, 이 그래프에는 떨어진 정점이 없다
		  그렇지 않은 (그래프 I) 는 비연결 그래프라고 한다

	    - 그래프 J -
		  a - b
		  l
		  c   d

	7. 트리
		- 그래프의 특수한 형태로서 사이클을 가지지 않는 연결 그래프를 트리라 한다
		  (그래프 K), (그래프 L), (그래프 M)은 모두 연결되어 있을 뿐만 아니라 사이클이 없으므로 트리이다

		- 그래프 K -  - 그래프 L -  - 그래프 M -
		  a - b         a            a - b
		  l             l *
		  c - d         c   d

	8. 완전 그래프
		- 모든 정점 간에 간선이 존재하는 그래프를 "완전 그래프" 라고 한다
		  (그래프 N)은 완전 그래프 이다
		  무방향 완전 그래프의 정점 수를 n이라고 하면, 하나의 정점은 n - 1 개의 다른 정점으로 연결되므로 간선의 수는 n * (n - 1) / 2 가 된다
		  만약 완전 그래프에서 n = 4 라면 간선의 수는 ( 4 * 3 ) / 2 = 6 이다

		 - 그래프 N -
		  a  ---  b
		  l *   * l
		  l   *   l
		  l *   * l
		  c  -- - d
*/