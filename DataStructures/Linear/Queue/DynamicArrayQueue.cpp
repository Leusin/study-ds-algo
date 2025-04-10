/*
 * 동적 배열 기반 큐
 *
 * 동적 배열(std::vector)을 감싸 간단하게 큐를 구현합니다.
 * 학습용 예제이기 때문에 실전에서는 성능상 제한이 있습니다.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Queue
{
    vector<int> q;

public:
    void enqueue(int new_data)
    {
        q.push_back(new_data);
    }

    /*
     * vector의 앞부분을 지우면 내부 요소들이 한 칸씩 이동하므로
     * 시간 복잡도가 O(n)입니다. 아래와 같은 구현에서 잦은 dequeue
     * 호출은 비효율적이기 때문에 실전에서 사용하기엔 무리가 있습니다.
     */
    void dequeue()
    {
        if (!is_empty())
        {
            q.erase(q.begin());
        }
    }

    int peek()
    {
        if (is_empty())
        {
            throw runtime_error("Queue is empty");
        }

        return q.front();
    }

    bool is_empty()
    {
        return q.empty();
    }
};

int main()
{
    Queue q;

    cout << "큐에 값을 추가합니다: 10, 20, 30" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "현재 큐의 가장 앞의 값: " << q.peek() << endl;

    cout << "\n큐에서 두 개의 값을 제거합니다." << endl;
    q.dequeue();
    q.dequeue();

    cout << "현재 큐의 앞의 값: " << q.peek() << endl;

    cout << "\n큐에서 남은 값들을 모두 제거합니다..." << endl;
    q.dequeue();

    cout << "큐가 비어있습니까?: " << (q.is_empty() ? "네" : "아니오") << endl;

    cout << "\n비어있는 큐에서 peek() 호출 시도..." << endl;
    try
    {
        cout << "현재 큐의 최상단 값: " << q.peek() << endl;
    }
    catch (const exception &e)
    {
        cout << "(오류 발생) " << e.what() << endl;
    }

    return 0;
}
