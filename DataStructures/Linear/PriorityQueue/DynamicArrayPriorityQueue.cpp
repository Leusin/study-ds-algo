/*
 * 동적 배열 기반 우선순위 큐
 *
 * 동적 배열(std::vector)을 감싸 간단하게 큐를 구현합니다.
 * enqueue의 시간 복잡도는 O(1), dequeue 와 peek는 O(n)으로
 * 상대적으로 비효율적인 편입니다.
 *
 * 이 구현은 학습 목적이거나, 데이터 수가 적고 간단한 경우에 적합합니다.
 * 성능이 중요한 상황에서는 heap 기반(priority_queue 등) 구조를 사용해야 합니다.
 */

#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue
{
    struct Element
    {
        int value;
        int priority;
    };

    vector<Element> pq;

public:
    void enqueue(int value, int priority)
    {
        pq.push_back({value, priority});
    }

    void dequeue()
    {
        int index = peek_index();
        
        if (index == -1)
        {
            throw runtime_error("Queue is Underflow");
        }

        pq.erase(pq.begin() + index);
    }

    int peek_index()
    {
        int index = -1;
        int maxPriority = INT_MIN;

        for (int i = 0; i < pq.size(); i++)
        {
            if (pq[i].priority > maxPriority ||
                (pq[i].priority == maxPriority && (index == -1 || pq[i].value > pq[index].value)))
            {
                maxPriority = pq[i].priority;
                index = i;
            }
        }

        return index;
    }

    int peek_value()
    {
        int index = peek_index();

        if (index == -1)
        {
            throw runtime_error("Queue is empty");
        }

        return pq[index].value;
    }

    bool is_empty()
    {
        return pq.empty();
    }
};

int main()
{
    PriorityQueue pq;

    cout << "큐에 값을 추가합니다: 10(2), 20(4), 30(4), 40(3)" << endl;
    pq.enqueue(10, 2);
    pq.enqueue(20, 4);
    pq.enqueue(30, 4);
    pq.enqueue(40, 3);

    cout << "현재 큐의 가장 앞의 값: " << pq.peek_value() << endl;

    cout << "\n큐에서 두 개의 값을 제거합니다." << endl;
    pq.dequeue();
    pq.dequeue();

    cout << "현재 큐의 앞의 값: " << pq.peek_value() << endl;

    cout << "\n큐에서 남은 값들을 모두 제거합니다..." << endl;
    pq.dequeue();
    pq.dequeue();

    cout << "큐가 비어있습니까?: " << (pq.is_empty() ? "네" : "아니오") << endl;

    cout << "\n비어있는 큐에서 peek_value() 호출 시도..." << endl;
    try
    {
        cout << "현재 스택의 최상단 값: " << pq.peek_value() << endl;
    }
    catch (const exception &e)
    {
        cout << "(오류 발생) " << e.what() << endl;
    }

    return 0;
}
