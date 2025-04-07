/*
 * 연결 리스트 기반 큐
 * 
 * 연결 리스트 기반 큐는 크기 제한이 없어, 동적으로 요소를 추가하거나 
 * 제거해야 하는 상황에 적합합니다. 
 * 
 * 연결 리스트의 앞과 뒤를 가리키는 포인터만 조작하면 되므로, 요소의 
 * 삽입(enqueue)과 삭제(dequeue)가 O(1)로 매우 빠릅니다.
 * 
 * 하지만 각 노드가 데이터를 저장하는 것 외에도 포인터를 포함해야 하므로 
 * 배열 기반 큐보다 메모리 오버헤드가 크며, 메모리가 연속되지 않기 때문에 
 * 캐시 효율이 떨어질 수 있습니다.
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

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int new_data)
    {
        try
        {
            // 노드 초기화 및 값 업데이트
            Node *new_node = new Node(new_data);

            if(is_empty())
            {
                front = new_node;
                rear = new_node;
                return;
            }

            // 링크 연결하기
            rear->next = new_node;
            rear = new_node;
        }
        /**
         * 일반적으로 연결 리스트 기반 큐에서는 오버플로우가 발생하지 
         * 않습니다. 하지만 극단적으로 메모리가 부족한 상황에서는 
         * new 연산자가 메모리 할당 실패 하면 
         * 예외(std::bad_alloc)를 던지므로 이를 스택 오버
         * 플로우로 판단합니다.
         */
        catch (const bad_alloc &e)
        {
            cout << "\nQueue Overflow: " << e.what();
        }
    }

    void dequeue()
    {
        // 존재하는 요소가 있는지 검사합니다.
        if (is_empty())
        {
            cout << "\nQueue Underflow" << endl;
        }
        else
        {
            // 처리할 노드 포인터를 임시 포인트로 설정
            Node *temp = front;
            // 한 단계 이전에 연결된 노드를 최상위 노드로 변경
            front = front->next;

            if(is_empty())
            {
                rear = nullptr;
            }

            delete temp;
        }
    }

    int peek()
    {
        // 존재하는 요소가 있는지 검사합니다.
        if (is_empty())
        {
            throw runtime_error("Queue is empty");
        }
        // 가장 앞의 노드의 값을 반환합니다.
        return front->data;
    }

    /**
     * 큐가 비어있으면 true 비어있지 않으면 false를 반환합니다.
     */
    bool is_empty()
    {
        return front == nullptr;
    }
};

int main()
{
    Queue st;

    cout << "큐에 값을 추가합니다: 10, 20, 30" << endl;
    st.enqueue(10);
    st.enqueue(20);
    st.enqueue(30);

    cout << "현재 큐의 가장 앞의 값: " << st.peek() << endl;

    cout << "\n큐에서 두 개의 값을 제거합니다." << endl;
    st.dequeue();
    st.dequeue();

    cout << "현재 큐의 앞의 값: " << st.peek() << endl;

    cout << "\n큐에서 남은 값들을 모두 제거합니다..." << endl;
    st.dequeue();

    cout << "큐가 비어있습니까?: " << (st.is_empty() ? "네" : "아니오") << endl;

    cout << "\n비어있는 큐에서 peek() 호출 시도..." << endl;
    try
    {
        cout << "현재 스택의 최상단 값: " << st.peek() << endl;
    }
    catch (const exception &e)
    {
        cout << "(오류 발생) " << e.what() << endl;
    }

    return 0;
}
