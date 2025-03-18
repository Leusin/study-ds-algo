/*
 * 병합 정렬(Merge Sort)
 *
 * 분할 정복(Divide and Conquer) 알고리즘의 하나로 리스트를 
 * 재귀적으로 반으로 나누어 각 부분을 정렬한 후, 두 정렬된 부분을 합쳐 
 * 최종적으로 정렬된 리스트를 만드는 방식입니다.
 *
 * 1. 더 이상 나눌 수 없을 때까지 두 부분 리스트로 나눕니다.
 * 2. 각 부분 리스트를 재귀적으로 병합 정렬합니다. 
 * 3. 두 정렬된 리스트를 비교하며 하나의 정렬된 리스트로 병합합니다.
 *
 * 시간 복잡도 O(N log N)을 가지며, 안정적인 정렬 알고리즘으로 큰 
 * 데이터셋에서 효율적으로 작동합니다.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 정렬된 두 개의 부분 배열을 병합하는 함수
 * @param arr 정렬할 배열
 * @param left 첫 번째 부분 배열의 시작 인덱스
 * @param mid 첫 번째 부분 배열의 끝(두 번째 부분 배열의 시작 - 1)
 * @param right 두 번째 부분 배열의 끝 인덱스
 */
void asc_merge(int arr[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // 임시 배열 생성
    // (C++ 표준에서는 Variable Length Array(VLA)를 지원하지 않으므로
    // 동적 할당 사용)
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    // 원본 배열에서 임시 배열로 데이터 복사
    for (int i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        rightArr[i] = arr[mid + i + 1];
    }

    // 두 배열을 비교하며 병합
    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    // 남은 요소들 복사
    while (i < leftSize)
    {
        arr[k++] = leftArr[i++];
    }

    while (j < rightSize)
    {
        arr[k++] = rightArr[j++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

/**
 * 오름차순 병합 정렬 함수
 * @param arr 정렬할 배열
 * @param left 왼쪽 인덱스
 * @param right 오른쪽 인덱스
 */
void asc_merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // 왼쪽과 오른쪽 부분으로 분할
        asc_merge_sort(arr, left, mid);
        asc_merge_sort(arr, mid + 1, right);

        // 정렬된 배열을 병합
        asc_merge(arr, left, mid, right);
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

    asc_merge_sort(arr, 0, size - 1);

    cout << "정렬 후: ";
    print_array(arr, size);

    return 0;
}