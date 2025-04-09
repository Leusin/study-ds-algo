/*
 * 원형 덱 (Circular Deque)
 *
 * 덱(Deque)은 Double-Ended Queue의 줄임말로 앞과 뒤
 * 양쪽에서 삽입과 삭제가 가능한 큐의 확장 구조입니다.
 *
 * 이 구현은 고정 크기의 배열을 사용하며, 배열의 양 끝을 연결하여 원형처럼
 * 동작하게 만들어 공간을 보다 효율적으로 활용할 수 있습니다.
 *
 */

#include <iostream>

using namespace std;

class Deque
{
    int *arr;
    int front;
    int size;
    int capacity;

public:
    Deque(int c)
    {
        arr = new int[c];
        front = 0;
        size = 0;
        capacity = c;
    }

    void add_front(int new_data)
    {
        if (size == capacity)
        {
            throw runtime_error("Deque Overflow");
        }
        else
        {
            front = (front - 1 + capacity) % capacity;
            arr[front] = new_data;
            size++;
        }
    }

    void add_rear(int new_data)
    {
        if (size == capacity)
        {
            throw runtime_error("Deque Overflow");
        }
        else
        {
            int rear = (front + size) % capacity;
            arr[rear] = new_data;
            size++;
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
            front = (front + 1) % capacity;
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
            front = (front + size - 1) % capacity;
            size--;
        }
    }

    int get_front()
    {
        if (is_empty())
        {
            throw runtime_error("Deque is empty");
        }

        return arr[front];
    }

    int get_rear()
    {
        if (is_empty())
        {
            throw runtime_error("Deque is empty");
        }

        int rear = (front + size - 1) % capacity;
        return arr[rear];
    }

    bool is_empty()
    {
        return size == 0;
    }
};

int main()
{
    Deque dq(4);

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