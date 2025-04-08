/*
 * C++ STL 의 스택
 *
 * C++ 표준 라이브러리에서 제공하는 스택 자료구조입니다. 내부적으로는 다른 
 * 컨테이너를 감싸는 container adapter 형태로 구현되어 있습니다.
 *
 */

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // 구문
    /*
     * stack<T> st;
     * - T: 요소의 타입
     */
    stack<int> st;

    // 1. 요소 삽입 함수: push()
    /*
     * 시간 복잡도: O(1)
     * 설명: 가장 위에 요소를 추가합니다. 다른 위치로 삽입이 불가능
     * 합니다.
     */
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // 2. 요소 접근 함수: top()
    /*
     * 시간 복잡도: O(1)
     * 설명: 가장 위의 요소를 접근합니다. 중간 요소에 접근할 수
     * 없습니다.
     */
    cout << "스택의 최상위 요소 : " << st.top() << endl;

    // 3. 요소 삭제 함수: pop()
    /*
     * 시간 복잡도: O(1)
     * 설명: 다른 요소를 삭제하려면 더 위의 요소부터 삭제해야 합니다.
     */
    st.pop();

    // 4. 요소 순회
    /*
     * 시간 복잡도: O(n)
     * 설명: 가장 위의 요소 외에 접근할 수 없기 때문에 직접 순회가
     * 불가능한 대신 복사본을 생성하면 다음과 같이 동작하게 할 수
     * 있습니다.
     */
    stack<int> temp(st);

    cout << "스택의 순회 : ";
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // 5. 기타 -----

    // 내장 함수 empty()
    cout << "스택이 비었습니까? : " << (st.empty() ? "예" : "아니오") << endl;

    // 내장 함수 size()
    cout << "스택의 크기: " << st.size() << endl;

    // 스택의 복사
    temp = st;

    // 스택의 역 정렬
    stack<int> reversed;
    while (!temp.empty())
    {
        reversed.push(temp.top());
        temp.pop();
    }

    // 내장 함수 swap()
    st.swap(reversed);

    return 0;
}
