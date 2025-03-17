/*
 * 선택 정렬(Selection Sort)
 *
 * 주어진 리스트에서 가장 작은(또는 큰) 요소를 찾아 맨 앞의 요소와 교환하는 
 * 방식으로 정렬을 수행하는 알고리즘입니다. 이 과정은 리스트의 모든 요소가 
 * 정렬될 때까지 반복됩니다. 
 * 
 * 첫 번째 반복에서는 전체 리스트에서 가장 작은 요소를 찾아 첫 번째 위치와 
 * 교환하고, 두 번째 반복에서는 두 번째부터 끝까지에서 가장 작은 요소를 
 * 찾아 두 번째 위치와 교환하는 방식으로 진행됩니다. 
 * 
 * 시간 복잡도는 O(n^2)으로, 작은 데이터셋에서는 효율적으로 작동하지만 
 * 큰 데이터셋에서는 비효율적입니다.
 * 
 */

#include <iostream>

using namespace std;
 
/**
 * 선택 정렬 함수
 * @param arr 정렬할 배열
 * @param size 배열 크기
 */
void selection_sort(int arr[], const int size) 
{
    int min_index;

    // 마지막 요소는 자동으로 정렬되므로 size-1까지 반복
    for (int i = 0; i < size - 1; i++) 
    {
        min_index = i;

        // 최소값 탐색
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[j] < arr[min_index]) 
            {
                min_index = j;
            }
        }

        // 최소값을 현재 위치와 교환
        swap(arr[min_index], arr[i]);
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

    selection_sort(arr, size);

    cout << "정렬 후: ";
    print_array(arr, size);

    return 0;
}