/*
 * 이진 탐색(BinarySearch Search)
 *
 * 정렬된 배열에서 중간 값을 기준으로 탐색 범위를 절반씩 좁혀가며 값을 찾는
 * 알고리즘으로, 시간 복잡도는 O(logN), 공간 복잡도는 O(1)입니다.
 * 
 * 선형 탐색보다 효율적이며, 특히 데이터 크기가 클 경우 성능 차이가 
 * 두드러지지만, 반드시 정렬된 배열에서만 동작하므로 추가적인 정렬 작업이 
 * 필요하고, 배열의 원소는 비교할 수 있어야 하며 연속된 메모리 공간에 
 * 저장되어야 합니다.
 * 
 */

#include <iostream>

using namespace std;

/**
 * 이진 탐색 알고리즘 함수 (반복문 방식)
 * @param arr 탐색할 배열
 * @param low 탐색 범위의 시작 인덱스
 * @param high 탐색 범위의 끝 인덱스
 * @param target 찾고자 하는 값
 * @return 배열에서 target 값의 인덱스, 없으면 -1 반환
 */
int BinarySearch_Iterative(int arr[], int low, int high, int target)
{
    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }

        // target이 더 크면 오른쪽 반을 탐색
        if(arr[mid] < target)
        {
            low = mid + 1;
        }
        // target이 더 작으면 왼쪽 반을 탐색
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

/**
 * 이진 탐색 알고리즘 (재귀 방식)
 * @param arr 탐색할 배열
 * @param low 탐색 범위의 시작 인덱스
 * @param high 탐색 범위의 끝 인덱스
 * @param target 찾고자 하는 값
 * @return 배열에서 target 값의 인덱스, 없으면 -1 반환
 */
int BinarySearch_Recursive(int arr[], int low, int high, int target)
{
    if(high >= low)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }

        // target이 더 작으면 왼쪽 반을 탐색
        if(arr[mid] > target)
        {
            return BinarySearch_Recursive(arr, low, mid - 1, target);
        }

        // target이 더 크면 오른쪽 반을 탐색
        return BinarySearch_Recursive(arr, mid + 1, high, target);
    }

    return -1;
}

int main(void)
{
    int arr[] = {2, 3, 5, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    int result1 = BinarySearch_Iterative(arr, 0, size - 1, target);
    int result2 = BinarySearch_Recursive(arr, 0, size - 1, target);

    if (result1 != -1 && result1 == result2)
    {
        cout << "값 " << target << "은(는) 배열의 인덱스 " << result1 << "에 있습니다." << endl;
    }
    else if(result1 != -1 && result1 != result2)
    {
        cout << "두 탐색의 결과가 다릅니다." << endl;
    }
    else if(result1 != -1)
    {
        cout << "값을 찾을 수 없습니다." << endl;
    }

    return 0;
}
