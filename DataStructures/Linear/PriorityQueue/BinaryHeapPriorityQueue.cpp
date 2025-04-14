/*
 * 이진 힙 기반 우선순위 큐 (Max-Heap)
 *
 * 이진 최대 힙은 값이 클수록 우선순위가 높다고 가정합니다. 가장 우선순위가
 * 높은 값이 루트에 위치하며, 삽입 시에는 위로 올라가며 재정렬(shift_up),
 * 삭제 시에는 아래로 내려가며 재정렬(shift_down) 됩니다.
 *
 * 삽입(enqueue)과 삭제(dequeue)의 시간 복잡도는 O(log n)
 * 탐색(peek)은 O(1)으며, 데이터를 연속적인 공간에 보관해 대용량 데이터를
 * 효율적으로 처리합니다. 배열이나 연결 리스트 보다 더 나은 성능을 제공하는
 * 것으로 평가됩니다.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue
{
	vector<int> pq;

public:
	void enqueue(int p)
	{
		pq.push_back(p);
		shift_up(pq.size() - 1);
	}

	void dequeue()
	{
		if (is_empty())
		{
			throw runtime_error("Queue Underflow");
		}
		else
		{

			pq[0] = pq.back();
			pq.pop_back();
			shift_down(pq.size() - 1);
		}
	}

	int peek()
	{
		if (is_empty())
		{
			throw runtime_error("Queue is empty");
		}
		return pq[0];
	}

	bool is_empty()
	{
		return pq.empty();
	}

	// 특정 인덱스의 값을 새 우선순위로 변경합니다.
	void change_priority(int index, int new_priority)
	{
		int old_priority = pq[index];
		pq[index] = new_priority;

		if (new_priority > old_priority)
		{
			shift_up(index);
		}
		else
		{
			shift_down(index);
		}
	}

	// 특정 인덱스 값을 제거합니다.
	void remove(int index)
	{
		pq[index] = peek() + 1;
		shift_up(index);
		dequeue();
	}

	// 현재 노드의 부모 노드를 계산합니다.
	int parent(int index)
	{
		return (index - 1) / 2;
	}

	// 현재 노드의 왼쪽 자식 노드를 계산합니다.
	int left_child(int index)
	{
		return (2 * index) + 1;
	}

	// 현재 노드의 오른쪽 자식 노드를 계산합니다.
	int right_child(int index)
	{
		return (2 * index) + 2;
	}

	// 인덱스에 있는 값과 부모의 우선순위를 비교하여
	// 우선 순위가 더 높은 경우 부모와 위치를 바꿉니다.
	void shift_up(int index)
	{
		while (index > 0 && pq[parent(index)] < pq[index])
		{
			swap(pq[parent(index)], pq[index]);
			index = parent(index);
		}
	}

	// 인덱스에 있는 값과 부모의 우선순위를 비교하여
	// 우선 순위가 더 낮은 경우 부모와 위치를 바꿉니다.
	void shift_down(int index)
	{
		int max_index = index;
		int left = left_child(index);

		if (left < pq.size() && pq[left] > pq[max_index])
		{
			max_index = left;
		}

		int right = right_child(index);

		if (right < pq.size() && pq[right] > pq[max_index])
		{
			max_index = right;
		}

		if (index != max_index)
		{
			swap(pq[index], pq[max_index]);
			shift_down(max_index);
		}
	}
};

int main()
{

	/*        40
			/   \
		   30    20
		  /
		10
	*/
	PriorityQueue pq;

	cout << "큐에 값을 추가합니다: 10, 20, 30, 40" << endl;
	pq.enqueue(10); // → [10]
	pq.enqueue(20); // → [20, 10]
	pq.enqueue(30); // → [30, 10, 20]
	pq.enqueue(40); // → [40, 30, 20, 10]

	cout << "현재 큐의 가장 앞의 값: " << pq.peek() << endl;

	cout << "\n큐에서 두 개의 값을 제거합니다." << endl;
	pq.dequeue();
	pq.dequeue();

	cout << "현재 큐의 앞의 값: " << pq.peek() << endl;

	cout << "\n큐에서 남은 값들을 모두 제거합니다..." << endl;
	pq.dequeue();
	pq.dequeue();

	cout << "큐가 비어있습니까?: " << (pq.is_empty() ? "네" : "아니오") << endl;

	cout << "\n비어있는 큐에서 peek() 호출 시도..." << endl;
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
