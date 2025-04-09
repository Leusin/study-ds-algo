/*
 * C++ STL 의 덱(deque)
 *
 * C++ 표준 라이브러리에서 제공하는 덱 자료구조입니다.
 * 내부적으로는 동적 배열의 블록들을 연결한 형태로 구현되어 있어
 * 양 끝에서 O(1) 시간 복잡도로 작업이 가능합니다.
 */

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // 구문
    /*
     * deque<T> dq;
     * - T: 요소의 타입
     */
    deque<int> dq;

    // 1. 요소 삽입 함수: push_front(), push_back()
    /*
     * 시간 복잡도: O(1)
     * 설명: 앞쪽 또는 뒤쪽에 요소를 추가할 수 있습니다.
     */
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(0);
    dq.push_back(3);
    dq.push_front(-1);

    // 2. 요소 접근 함수: front(), back(), [], at()
    /*
     * 시간 복잡도: O(1)
     * 설명: 덱의 양 끝 또는 특정 위치의 요소에 접근할 수 있습니다.
     */
    cout << "덱 앞: " << dq.front() << ", 덱 뒤: " << dq.back() << endl;
    cout << "덱[2]: " << dq[2] << ", at(2): " << dq.at(2) << endl;

    // 3. 요소 삭제 함수: pop_front(), pop_back()
    /*
     * 시간 복잡도: O(1)
     * 설명: 앞이나 뒤에서 요소를 제거할 수 있습니다.
     */
    dq.pop_front();
    dq.pop_back();

    // 4. 요소 순회
    /*
     * 시간 복잡도: O(n)
     */
    cout << "덱의 순회: ";
    for (int val : dq)
    {
        cout << val << " ";
    }
    cout << endl;

    // 5. 기타 -----

    // empty()
    cout << "덱이 비었습니까?: " << (dq.empty() ? "예" : "아니오") << endl;

    // size()
    cout << "덱의 크기: " << dq.size() << endl;

    // clear()
    dq.clear();
    cout << "덱을 비운 후 size(): " << dq.size() << endl;

    // insert(), erase()
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    auto it = dq.begin() + 1;
    dq.insert(it, 15); // 10, 15, 20, 30

    dq.erase(dq.begin() + 2); // 10, 15, 30

    cout << "덱 수정 결과: ";
    for (int val : dq)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
