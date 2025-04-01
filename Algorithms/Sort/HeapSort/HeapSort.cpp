/*
 * 힙 정렬(Heap Sort)
 *
 * 이진 힙(binary heap)을 기반으로 한 정렬 알고리즘입니다. 힙은 
 * 완전 이진 트리 형태로 구성되며, 각 부모 노드가 자식 노드보다 크거나 작은
 * 값을 가지는 특성을 가집니다.
 * 
 * 힙 정렬은 먼저 주어진 리스트를 힙 구조로 변환한 후, 최대 
 * 힙(또는 최소 힙)을 이용해 가장 큰(또는 작은) 값을 리스트의 끝으로 
 * 보내고, 그 뒤로 힙 속성을 유지하며 정렬을 반복합니다. 이 과정은 리스트의
 * 크기가 1이 될 때까지 계속됩니다. 
 * 
 * 힙 정렬은 시간 복잡도가 O(N log N)으로, 최악의 경우에도 안정적인 성능을 
 * 보이며, 추가적인 메모리 공간을 거의 사용하지 않아 공간 복잡도가 
 * O(1)입니다. 
 * 
 * 하지만 캐시 친화적이지 않아 실질적인 성능이 저하될 수 있습니다.
 * 
 */

#include <iostream>

using namespace std;

/**
 * 최대 힙화 함수
 * @param arr 정렬할 배열
 * @param heapSize 현재 힙 크기
 * @param index 최대 힙을 유지할 인덱스
 */
void max_heapify(int arr[], int heapSize, int index) 
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int largest = index;

    // 왼쪽 자식 노드
	if (left < heapSize && arr[left] > arr[largest])
	{
		largest = left;
	}

    // 오른쪽 자식 노드드
	if (right < heapSize && arr[right] > arr[largest]) 
	{
		largest = right;
	}

	if (largest != index) 
	{
		swap(arr[index], arr[largest]);
		max_heapify(arr, heapSize, largest);
	}
}

/**
 * 오름차순 힙 정렬 함수
 * @param arr 정렬할 배열
 * @param size 배열 크기
 */
void asc_heap_sort(int arr[], const int size) 
{
	// 배열을 최대 힙으로 변환
	for (int i = size / 2 - 1; i >= 0; i--) 
	{
		max_heapify(arr, size, i);
	}

    // 힙 정렬 수행
	for (int i = size - 1; i > 0; i--) 
	{
		// 현재 값을 루트 노드로 이동
		swap(arr[i], arr[0]);
		max_heapify(arr, i, 0);
	}
}

/**
 * 배열 출력 함수
 */
void print_array(const int arr[], const int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "정렬 전: ";
    print_array(arr, size);

    asc_heap_sort(arr, size);

    cout << "정렬 후: ";
    print_array(arr, size);

    return 0;
}
