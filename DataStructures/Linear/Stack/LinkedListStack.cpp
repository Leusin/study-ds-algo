
/*
 * 연결 리스트 기반 스택 
 * 
 * 연결 리스트 기반 스택은 재귀 함수 호출의 함수 호출 스택, 웹 브라우저의
 * 뒤로 가기 기능, 문서 편집기의 실행 취소(Undo) 기능 등에 응용할 수
 * 있습니다. 
 *
 * 동적 할당을 사용해 크기 제한이 없고, 삽입/삭제 연산이 O(1)로 빠르며
 * 메모리 낭비가 적다는 점이 있습니다. 
 *
 * 반면, 배열 기반 스택보다 노드 포인터 저장을 위한 추가 메모리가 필요하고
 * 연속된 메모리 공간을 사용하지 않으므로 캐시 효율이 낮을 수 있습니다.
 * 
 */

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int new_data)
    {
        this->data = new_data;
        this->next = nullptr;
    }
};

class Stack
{
    // 가장 위(top)의 요소
    Node *head;

public:
    Stack()
    {
        head = nullptr;
    }

    void push(int new_data)
    {
        try
        {
            // 노드 초기화 및 값 업데이트
            Node *new_node = new Node(new_data);
            // 링크 연결하기
            new_node->next = head;
            // top 요소 업데이트
            head = new_node;
        }
        /**
         * 일반적으로 연결 리스트 기반의 스택에서는 오버플로우가
         * 발생하지 않습니다. 하지만 극단적으로 메모리가 부족한
         * 상황에서는 new 연산자가 메모리 할당 실패 하면
         * 예외(std::bad_alloc)를 던지므로 이를 스택 오버
         * 플로우로 판단합니다.
         */
        catch (const bad_alloc &e)
        {
            cout << "\nStack Overflow: " << e.what();
        }
    }

    void pop()
    {
        // 존재하는 요소가 있는지 검사합니다.
        if (is_empty())
        {
            cout << "\nStack Underflow" << endl;
        }
        else
        {
            // 최상위 노드 포인터를 임시 포인트로 설정한 뒤
            Node *temp = head;
            // 그 다음 1단계 연결된 노드를 최상위 노드로 변경
            head = head->next;
            delete temp;
        }
    }

    int top()
    {
        // 존재하는 요소가 있는지 검사합니다.
        if (is_empty())
        {
            throw runtime_error("Stack is empty");
        }
        // 최상위 노드의 값을 반환합니다.
        return head->data;
    }

    /**
     * 스택이 비어있으면 true 비어있지 않으면 false를 반환합니다.
     */
    bool is_empty()
    {
        return head == nullptr;
    }
};

int main()
{
    Stack st;

    cout << "스택에 값을 추가합니다: 10, 20, 30" << endl;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "현재 스택의 최상단 값: " << st.top() << endl;

    cout << "\n스택에서 두 개의 값을 제거합니다." << endl;
    st.pop();
    st.pop();

    cout << "현재 스택의 최상단 값: " << st.top() << endl;

    cout << "\n스택에서 남은 값들을 모두 제거합니다..." << endl;
    st.pop();

    cout << "스택이 비어있습니까? " << (st.is_empty() ? "네" : "아니오") << endl;

    cout << "\n비어있는 스택에서 top() 호출 시도.." << endl;
    try
    {
        cout << "현재 스택의 최상단 값: " << st.top() << endl;
    }
    catch (const exception &e)
    {
        cout << "오류 발생: " << e.what() << endl;
    }

    return 0;
}
