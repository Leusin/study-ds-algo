/*
 * 삽입 정렬(Insertion Sort)
 *
 * 리스트의 두 번째 요소부터 시작하여, 각 요소를 그 앞의 정렬된 부분과
 * 비교해 적절한 위치에 삽입하는 방식으로 정렬을 수행하는 알고리즘입니다.
 *
 * 처음에는 첫 번째 요소만 정렬된 상태로 간주하고, 두 번째 요소부터 차례대로
 * 앞의 요소들과 비교하여 올바른 자리를 찾은 후 삽입합니다. 이 과정은
 * 리스트의 끝까지 반복되며, 각 단계에서 새로운 요소가 정렬된 부분에
 * 삽입됩니다.
 *
 * 시간 복잡도는 최선의 경우 O(N)이고 최악의 경우 O(N^2)로, 작은
 * 데이터셋에서는 효율적이지만 큰 데이터셋에는 비효율적입니다.
 *
 */

#include <iostream>

using namespace std;

/**
 * 오름차순 삽입 정렬 함수
 * @param arr 정렬할 배열
 * @param size 배열 크기
 */
void asc_insertion_sort(int arr[], const int size)
{
    for (int i = 1; i < size; i++)
    {
        int current_value = arr[i];
        int current_index = i;

        // 순서가 잘못되었다면 보다 큰 요소를 한 칸씩 밀어냅니다.
        while (current_index > 0 && arr[current_index - 1] > current_value)
        {
            arr[current_index] = arr[current_index - 1];
            current_index--;
        }
        arr[current_index] = current_value;
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

    asc_insertion_sort(arr, size);

    cout << "정렬 후: ";
    print_array(arr, size);

    return 0;
}