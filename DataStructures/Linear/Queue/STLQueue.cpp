/*
 * C++ STL 의 큐
 *
 * C++ 표준 라이브러리에서 제공하는 큐 자료구조입니다. 내부적으로는 다른
 * 컨테이너를 감싸는 container adapter 형태로 구현되어 있습니다.
 *
 */

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // 구문
    /*
     * queue<T> q;
     * - T: 요소의 타입
     */
    queue<int> q;

    // 1. 요소 삽입 함수: push()
    /*
     * 시간 복잡도: O(1)
     * 설명: 선착순으로 요소를 추가합니다. 다른 위치로 삽입이 불가능
     * 합니다.
     */
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // 2. 요소 접근 함수: front(), back()
    /*
     * 시간 복잡도: O(1)
     * 설명: 가장 앞 또는 뒤에 있는 요소를 접근합니다. 중간 요소에
     * 접근할 수 없습니다.
     */
    cout << "큐에 접근 가능한 요소 : " << q.front() << ", " << q.back() << endl;

    // 3. 요소 삭제 함수: pop()
    /*
     * 시간 복잡도: O(1)
     * 설명: 가장 앞(먼저 들어온) 요소부터 제거합니다. dequeue
     * 라고도 부릅니다.
     */
    q.pop();

    // 4. 요소 순회
    /*
     * 시간 복잡도: O(n)
     * 설명: 중간 요소에 접근할 수 없기 때문에 직접 순회가 불가능한
     * 대신 복사본을 생성하면 다음과 같이 동작하게 할 수 있습니다.
     */
    queue<int> temp(q);

    cout << "큐의 순회 : ";
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // 5. 기타 -----

    // 내장 함수 empty()
    cout << "큐가 비었습니까? : " << (q.empty() ? "예" : "아니오") << endl;

    // 내장 함수 size()
    cout << "큐의 크기: " << q.size() << endl;

    // 큐의 복사
    /*
     * queue<int> temp(q); 와 같이 선언과 동시에 복사 가능
     */
    temp = q;

    // 큐의 역 정렬
    queue<int> reversed;
    while (!temp.empty())
    {
        reversed.push(temp.front());
        temp.pop();
    }

    // 내장 함수 swap()
    q.swap(reversed);

    return 0;
}
