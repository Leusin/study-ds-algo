/*
 * 원형 큐 (Circular Queue)
 *
 * 정적 배열 기반 큐에서는 삭제된 앞쪽 공간을 재사용하지 못해 공간 활용이
 * 비효율적입니다. 
 * 
 * 원형 큐는 이러한 비효율을 개선한 구조로 배열의 끝에서 다시 처음으로 
 * 돌아가며 빈 공간을 활용할 수 있습니다.
 * 
 */

#include <iostream>

using namespace std;

class Queue
{
    int *arr;
    int front;
    int size;
    int capacity;

public:
    Queue(int c)
    {
        arr = new int[c];
        front = 0;
        size = 0;
        capacity = c;
    }

    void enqueue(int new_data)
    {
        if(size == capacity)
        {
            throw runtime_error("Queue Overflow");
        }
        else
        {
            int rear = (front + size) % capacity;
            arr[rear] = new_data;
            size++;
        }
    }

    void dequeue()
    {
        if (is_empty())
        {
            throw runtime_error("Queue Underflow");
        }
        else
        {
            front = (front + 1) % capacity;
            size--;
        }
    }

    int get_front()
    {
        if (is_empty())
        {
            throw runtime_error("Queue is empty");
        }

        return arr[front];
    }

    int get_rear()
    {
        if (is_empty())
        {
            throw runtime_error("Queue is empty");
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
    Queue q(4);

    cout << "큐에 값을 추가합니다: 10, 20, 30" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "현재 큐의 가장 앞의 값: " << q.get_front() << endl;

    cout << "\n큐에서 두 개의 값을 제거합니다." << endl;
    q.dequeue();
    q.dequeue();

    cout << "현재 큐의 앞의 값: " << q.get_front() << endl;

    cout << "\n큐에서 남은 값들을 모두 제거합니다..." << endl;
    q.dequeue();

    cout << "큐가 비어있습니까?: " << (q.is_empty() ? "네" : "아니오") << endl;

    cout << "\n비어있는 큐에서 peek() 호출 시도..." << endl;
    try
    {
        cout << "현재 큐의 가장 앞부분의 값: " << q.get_front() << endl;
    }
    catch (const exception &e)
    {
        cout << "(오류 발생) " << e.what() << endl;
    }

    return 0;
}
