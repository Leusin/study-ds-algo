/*
 * 선형 탐색(Linear Search)
 *
 * 리스트에서 각 요소를 처음부터 끝까지 차례대로 비교하여 원하는 값을 찾는
 * 알고리즘입니다.
 *
 * 배열이 정렬되어 있지 않아도 사용할 수 있으며, 시간 복잡도는 O(N)으로
 * 입력 크기에 비례해 탐색 시간이 증가합니다.
 *
 * 공간 복잡도는 O(1)로 추가 메모리가 필요하지 않습니다. 데이터가 커지면
 * 비효율적일 수 있어, 주로 작은 데이터 집합에 사용됩니다.
 * 
 */

#include <iostream>

using namespace std;

/**
 * 선형 탐색 알고리즘 함수
 * @param arr 탐색할 배열
 * @param size 배열 크기
 * @param target 찾고자 하는 값
 * @return 배열에서 target 값의 인덱스, 없으면 -1 반환
 */
int LinearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int arr[] = {3, 5, 7, 9, 2, 8, 10}; // 예시 배열
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    int result = LinearSearch(arr, size, target);

    if (result != -1)
    {
        cout << "값 " << target << "은(는) 배열의 인덱스 " << result << "에 있습니다." << endl;
    }
    else
    {
        cout << "값을 찾을 수 없습니다." << endl;
    }

    return 0;
}
