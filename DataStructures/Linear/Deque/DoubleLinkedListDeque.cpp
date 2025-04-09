/*
 * 이중 연결 리스트 기반 덱
 *
 * 연결 리스트 기반 덱은은 크기 제한이 없어, 동적으로 요소를 추가하거나
 * 제거해야 하는 상황에 적합합니다.
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
    Node *prev;
    Node(int new_data)
    {
        this->data = new_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Deque
{
    Node *front;
    Node *rear;
    int size;

public:
    Deque()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    void add_front(int new_data)
    {
        try
        {
            Node *new_node = new Node(new_data);

            if (is_empty())
            {
                front = new_node;
                rear = new_node;
            }
            else
            {
                new_node->next = front;
                front->prev = new_node;
                front = new_node;
            }

            size++;
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
            cout << "Deque Overflow: " << e.what();
        }
    }

    void add_rear(int new_data)
    {
        try
        {
            Node *new_node = new Node(new_data);

            if (is_empty())
            {
                front = new_node;
                rear = new_node;
            }
            else
            {
                new_node->prev = rear;
                rear->next = new_node;
                rear = new_node;
            }

            size++;
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
            cout << "Deque Overflow: " << e.what();
        }
    }

    void remove_front()
    {
        if (is_empty())
        {
            throw runtime_error("Deque Underflow");
        }
        else
        {
            // 처리할 노드 포인터를 임시 포인트로 설정
            Node *temp = front;
            // 한 단계 이전에 연결된 노드를 최상위 노드로 변경
            front = front->next;

            if (front != nullptr)
            {
                front->prev = nullptr;
            }
            else
            {
                rear = nullptr;
            }

            delete temp;
            size--;
        }
    }

    void remove_rear()
    {
        if (is_empty())
        {
            throw runtime_error("Deque Underflow");
        }
        else
        {
            // 처리할 노드 포인터를 임시 포인트로 설정
            Node *temp = rear;
            // 한 단계 이전에 연결된 노드를 최상위 노드로 변경
            rear = rear->prev;

            if (rear != nullptr)
            {
                rear->next = nullptr;
            }
            else
            {
                front = nullptr;
            }

            delete temp;
            size--;
        }
    }

    int get_front()
    {
        if (is_empty())
        {
            throw runtime_error("Deque is empty");
        }
        return front->data;
    }

    int get_rear()
    {
        if (is_empty())
        {
            throw runtime_error("Deque is empty");
        }
        return rear->data;
    }

    int get_size()
    {
        return size;
    }

    bool is_empty()
    {
        return front == nullptr;
    }
};

int main()
{
    Deque dq;

    cout << "앞쪽에 10, 20 추가 / 뒤쪽에 30, 40 추가" << endl;
    dq.add_front(10);
    dq.add_front(20);
    dq.add_rear(30);
    dq.add_rear(40);

    cout << "\n현재 덱 앞: " << dq.get_front() << ", 뒤: " << dq.get_rear() << endl;

    cout << "\n앞쪽에서 하나, 뒤쪽에서 하나 제거" << endl;
    dq.remove_front();
    dq.remove_rear();

    cout << "\n앞쪽에 60, 뒤쪽에 50 추가" << endl;
    dq.add_rear(50);
    dq.add_front(60);

    cout << "\n현재 덱 앞: " << dq.get_front() << ", 뒤: " << dq.get_rear() << endl;

    cout << "\n덱에서 남은 값들을 모두 제거합니다..." << endl;
    while (!dq.is_empty())
    {
        cout << "앞 제거: " << dq.get_front() << endl;
        dq.remove_front();
    }

    cout << "\n덱이 비어있습니까?: " << (dq.is_empty() ? "네" : "아니오") << endl;

    cout << "\n비어있는 덱에서 peek 시도..." << endl;
    try
    {
        cout << "현재 덱의 가장 앞부분의 값: " << dq.get_front() << endl;
        cout << "현재 덱의 가장 뒷부분의 값: " << dq.get_rear() << endl;
    }
    catch (const exception &e)
    {
        cout << "(오류 발생) " << e.what() << endl;
    }

    return 0;
}
