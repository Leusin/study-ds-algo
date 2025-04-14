/*
 * C++ STL 의 우선순위 큐 (priority_queue)
 *
 * C++ 표준 라이브러리에서 제공하는 최대 힙 기반 우선순위 큐입니다.
 * 기본적으로 가장 큰 값이 top에 위치하며, 내부적으로는 힙(Heap)을
 * 사용합니다.
 *
 * 기본 컨테이너는 vector이며, make_heap, push_heap, pop_heap
 * 등을 통해 관리됩니다.
 *
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	// 구문
	/*
	 * priority_queue<T> pq;
	 * - T: 요소의 타입
	 * - 기본 비교는 less<T>, 즉 큰 값이 우선순위가 높음 (최대 힙)
	 */
	priority_queue<int> pq;

	// 1. 요소 삽입 함수: push()
	/*
	 * 시간 복잡도: O(log n)
	 * 설명: 힙 속성을 유지하며 요소를 추가합니다.
	 */
	pq.push(10);
	pq.push(30);
	pq.push(20);
	pq.push(5);
	pq.push(1);

	// 2. 요소 접근 함수: top()
	/*
	 * 시간 복잡도: O(1)
	 * 설명: 현재 우선순위가 가장 높은(가장 큰) 값을 반환합니다.
	 */
	cout << "현재 top 값: " << pq.top() << endl;

	// 3. 요소 삭제 함수: pop()
	/*
	 * 시간 복잡도: O(log n)
	 * 설명: top 값을 제거하고 힙을 재정렬합니다.
	 */
	pq.pop();
	cout << "pop 후 top 값: " << pq.top() << endl;

	// 4. 요소 출력
	/*
	 * priority_queue는 반복자를 제공하지 않으므로
	 * 값을 출력하려면 복사해서 pop 반복 필요
	 */
	cout << "큐 내용 전체 출력 (복사 사용): ";
	priority_queue<int> temp = pq;
	while (!temp.empty())
	{
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << endl;

	// 5. 기타 -----

	// empty()
	cout << "큐가 비었습니까?: " << (pq.empty() ? "예" : "아니오") << endl;

	// size()
	cout << "큐의 크기: " << pq.size() << endl;

	// 최소 힙 구성 예시
	/*
	 * greater<T> 를 사용하면 최소 힙이 됩니다.
	 */
	priority_queue<int, vector<int>, greater<int>> min_pq;
	min_pq.push(3);
	min_pq.push(1);
	min_pq.push(4);

	cout << "최소 힙 top 값: " << min_pq.top() << endl;

	return 0;
}
