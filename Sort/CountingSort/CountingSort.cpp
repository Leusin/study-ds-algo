/*
 * 계수 정렬(Counting Sort)
 *
 * 정수 또는 범위가 제한된 값들에 대해 효율적으로 동작하는 비교 기반의 정렬
 * 알고리즘입니다.
 *
 * 각 값이 나타나는 빈도를 세기 위해 각 값의 등장 횟수를 기록하는 카운팅
 * 배열을 사용하고, 그 배열을 이용해 각 값이 정렬된 순서대로 출력됩니다.
 *
 * 계수 정렬은 시간 복잡도가 O(N + K)로, 여기서 N은 리스트의 크기,
 * K는 값의 범위입니다. 따라서 값의 범위가 작은 경우 매우 효율적이지만,
 * 범위가 매우 클 경우 메모리 사용이 많아지는 단점이 있습니다.
 *
 */

#include <iostream>

using namespace std;

/**
 * 오름차순 계수 정렬 함수
 * @param arr 정렬할 배열
 * @param size 배열 크기
 */
void asc_counting_sort(int arr[], int size)
{
    if (size <= 0)
    {
        return;
    }

    // 최소값과 최대값 그리고 값의 범위 구하기
    int min_value = arr[0];
    int max_value = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min_value)
        {
            min_value = arr[i];
        }
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }

    int range = max_value - min_value + 1;

    // 각 숫자의 등장 횟수 세기
    int *counts = new int[range]{0};

    for (int i = 0; i < size; i++)
    {
        counts[arr[i] - min_value]++;
    }

    // 누적 합 계산 (각 숫자의 시작 위치)
    // 만일 내림 차순 정렬을 하고 싶으면 거꾸로 배치
    for (int i = 1; i < range; i++)
    {
        counts[i] += counts[i - 1];
    }

    // 카운트 배열을 이용해 원소를 올바른 위치에 배치
    // (안정 정렬을 위해 뒤에서부터 처리)
    int *sorted = new int[size];

    for (int i = size - 1; i >= 0; i--)
    {
        sorted[counts[arr[i] - min_value] - 1] = arr[i];
        counts[arr[i] - min_value]--;
    }

    // 정렬된 결과를 원본 배열로 복사
    for (int i = 0; i < size; i++)
    {
        arr[i] = sorted[i];
    }

    delete[] sorted;
    delete[] counts;
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

    asc_counting_sort(arr, size);

    cout << "정렬 후: ";
    print_array(arr, size);

    return 0;
}
