


// 힙 정렬의 개념

// 힙 정렬은 10장의 우선순위 큐에서 힙의 응용으로 간단히 소개하였다
// 힙은 우선순위 큐를 완전 이진 트리로 구현하는 방법으로 최댓값이나 최솟값을 쉽게 추출할 수 있는 자료구조이다
// 힙에는 최대 힙과 최소 힙이 있는데, 최소 힙의 루트는 가장 작은 값을 가진다
// 정렬할 배열을 먼저 최소 힙으로 변환한 다음, 가장 작은 원소부터 차례대로 추출하여 정렬하는 방법을 힙 정렬(heap sort)이라 한다

// 힙은 완전 이진 트리이므로 1차원 배열을 이용하여 완전하게 기술할 수 있음을 유의하라
// 힙은 외관상으로는 그냥 1차원 배열처럼 보인다, 단지 배열의 요소들 간에 크고 작은 관계가 성립하는 것이다 (자세한 내용은 책 10장, 인터넷을 참고)

// 힙 정렬의 복잡도 분석
// 요소의 개수가 n일 때 힙의 삽입과 삭제 연산에 각각 log2 n 에 비례하는 시간이 걸리는 것을 공부했다
// 힙 정렬은 n번의 삽입과 n번의 삭제 연산이 필요하므로 결국 2n log2 n 에 비례하는 연산이 필요하다
// 따라서 힙 정렬의 시간 복잡도는 O(n log2 n) 이다

// 힙 정렬은 전체 리스트 중에서 일부만 정렬할 필요가 있는 경우에 매우 유용하다
// 예를 들어, n개의 레코드 중에서 제일 작은 레코드 k개만 필요한 경우, 다른 정렬 방법들은 리스트에 있는 n개의 레코드를 모두 정렬해야 하지만
// 힙 정렬은 최소 힙에서 k번만 작은 레코드를 추출해냄으로써 간단하게 목적을 달성할 수 있다
// 힙 정렬의 장점은 최악의 경우에도 시간 복잡도가 O(n log2 n) 으로 제한되고, 최소 힙이 배열로 구현되기 때문에 별도의 메모리가 필요 없다는 점이다