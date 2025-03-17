/*
 * 거품 정렬(Bubble Sort)
 * 
 * 인접한 두 요소를 비교하여, 잘못된 순서라면 교환하는 방식으로 리스트를 
 * 정렬하는 알고리즘입니다. 
 * 
 * 리스트의 끝까지 반복되며, 한 번의 반복을 마친 후에는 가장 큰(또는 작은) 
 * 요소가 리스트의 끝으로 "거품처럼 떠오른" 상태가 됩니다. 그런 후, 반복을 
 * 계속하면서 점점 정렬되지 않은 부분의 크기가 줄어듭니다. 
 * 
 * 간단하지만 시간 복잡도가 O(N^2)로 큰 데이터셋에 대해서는 
 * 비효율적입니다.
 * 
 */

#include <iostream>

using namespace std;
 
/**
 * 오름차순 거품 정렬 함수
 * @param arr 정렬할 배열
 * @param size 배열 크기
 */
void asc_bubble_sort(int arr[], const int size) 
{
    bool has_swapped = true;

    // 배열이 더는 교환되지 않을 때까지 반복
    while (has_swapped)
    {
        has_swapped = false;

        for(int i = 0; i < size - 1; i++)
        {
            // 순서가 잘못 되었다면 바로 교환 발생
            if(arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                has_swapped = true;
            }
        }
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

    asc_bubble_sort(arr, size);

    cout << "정렬 후: ";
    print_array(arr, size);

    return 0;
}