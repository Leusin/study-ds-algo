/*
 * 선택 정렬(Selection Sort)
 *
 * 시간 복잡도: O(n^2)
 * 공간 복잡도: O(1)
 * 안정성: X
 * 설명: 목록의 정렬되지 않은 최소값(또는 최대값)을 차례대로 탐색한 뒤 교환하는 과정을 반복합니다. 
 * 평가: 구현이 매우 직관적이고 교환 횟수가 적지만, 안정적이지 않고 성능이 좋지 않습니다. 
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