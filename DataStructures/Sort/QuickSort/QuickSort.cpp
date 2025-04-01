/*
 * 퀵 정렬(Quick Sort)
 * 
 * 분할 정복(Divide and Conquer) 알고리즘으로, 리스트에서 하나의 
 * 기준 요소 ‘피벗(Pivot)’를 선택하고, 피벗을 기준으로 작은 값은 왼쪽
 * 큰 값은 오른쪽으로 분할하여 정렬하는 방식입니다. 
 * 
 * 피벗을 기준으로 분할이 완료되면, 각 부분 리스트를 재귀적으로 다시 
 * 정렬하여 최종적으로 정렬된 리스트를 만듭니다. 
 * 
 * 평균 시간 복잡도는 O(N log N)이며 최악의 경우 O(N^2)입니다. 
 * 평균적으로 매우 빠른 알고리즘이지만 최악의 경우 성능이 저하될 수 있어 
 * 적절한 피벗 선택이 중요합니다.
 * 
 */

#include <iostream>

using namespace std;

/**
 * 배열을 분할하여 피벗을 기준으로 정렬하는 함수
 * @param arr 정렬할 배열
 * @param low 시작 인덱스
 * @param high 끝 인덱스
 * @return 피벗의 최종 위치
 */
int partition(int arr[], int low, int high) 
{
    // 피벗 설정
    int pivot = arr[high];  

    // i는 작은 요소들의 마지막 인덱스
    int i = low - 1;

    // 정렬 수행
    // 피벗보다 작은 값이면 작은 값과 현재 위치 교환
    for (int j = low; j < high; j++) 
    {
        
        if (arr[j] <= pivot)  
        {
            i++;
            swap(arr[i], arr[j]);  
        }
    }

    // 피벗을 올바른 위치로 이동
    swap(arr[i + 1], arr[high]);  

    // 피벗의 위치 반환
    return i + 1;  
}

/**
 * 오름차순 퀵 정렬 함수 (재귀 호출)
 * @param arr 정렬할 배열
 * @param low 시작 인덱스
 * @param high 끝 인덱스
 */
void asc_quick_sort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        // 피벗을 기준으로 분할
        int pivot_index = partition(arr, low, high);
        
        // 왼쪽과 오른쪽 부분 배열 분할
        asc_quick_sort(arr, low, pivot_index - 1);
        asc_quick_sort(arr, pivot_index + 1, high);
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

    asc_quick_sort(arr, 0, size - 1);

    cout << "정렬 후: ";
    print_array(arr, size);

    return 0;
}
