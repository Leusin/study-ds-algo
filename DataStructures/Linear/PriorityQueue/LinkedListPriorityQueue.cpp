/*
 * 연결 리스트 기반 우선순위 큐
 *
 * 삽입(enqueue)마다 우선순위가 가장 높은 요소가 항상 목록의 맨 앞에
 * 오도록 만들어야 합니다.
 *
 * 삽입(enqueue)의 시간 복잡도는 O(n), 삭제(dequeue)와
 * 탐색(peek)은 O(1) 입니다.
 *
 */

#include <iostream>

using namespace std;

struct Node
{
	int data;
	int priority;
	Node* next;

	Node(int d, int p) : data(d), priority(p), next(nullptr) {}
};

class PriorityQueue
{
	Node* front;

public:
	PriorityQueue() : front(nullptr)
	{
	}

	void enqueue(int data, int priority)
	{
		Node* new_node = new Node(data, priority);

		/*
		 * 새로운 데이터를 큐에 추가합니다.
		 * 큐가 비어 있거나,우선순위가 가장 높다면 맨 앞에 삽입합니다.
		 * 아니면 적절한 위치를 찾아 삽입합니다.
		 */
		if (is_empty() || priority < front->priority)
		{
			new_node->next = front;
			front = new_node;
		}
		else
		{
			// 우선순위가 낮은 노드들을 건너뛰며 적절한 위치 탐색
			Node* current = front;
			while (current->next != nullptr &&
				current->next->priority < priority)
			{
				current = current->next;
			}

			new_node->next = current->next;
			current->next = new_node;
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
			Node* temp = front;
			front = front->next;
			delete temp;
		}
	}

	int peek()
	{
		if (is_empty())
		{
			throw runtime_error("Queue is empty");
		}
		return front->data;
	}

	bool is_empty()
	{
		return front == nullptr;
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

	cout << "현재 큐의 가장 앞의 값: " << pq.peek() << endl;

	cout << "\n큐에서 두 개의 값을 제거합니다." << endl;
	pq.dequeue();
	pq.dequeue();

	cout << "현재 큐의 앞의 값: " << pq.peek() << endl;

	cout << "\n큐에서 남은 값들을 모두 제거합니다..." << endl;
	pq.dequeue();
	pq.dequeue();

	cout << "큐가 비어있습니까?: " << (pq.is_empty() ? "네" : "아니오") << endl;

	cout << "\n비어있는 큐에서 peek_value() 호출 시도..." << endl;
	try
	{
		cout << "현재 큐의 최상단 값: " << pq.peek() << endl;
	}
	catch (const exception& e)
	{
		cout << "(오류 발생) " << e.what() << endl;
	}

	return 0;
}