/*
 * 버킷 정렬(Bucket Sort)
 *
 * 데이터를 일정한 범위로 나누어 각각의 범위에 해당하는 값을
 * 버킷(bucket)에 저장한 후, 각 버킷을 개별적으로 정렬하고 마지막으로
 * 버킷들을 합쳐서 최종적으로 정렬된 리스트를 생성하는 알고리즘입니다.
 *
 * 주로 입력 데이터가 균등하게 분포되어 있을 때 효율적입니다. 버킷 정렬은
 * 각 버킷 내에서 정렬을 수행할 때 일반적으로 다른 정렬 알고리즘을 사용하며
 * 그 후 모든 버킷을 합쳐 결과를 얻습니다.
 *
 * 시간 복잡도는 평균적으로 O(N + K)이며, N은 입력 데이터의 크기,
 * K는 버킷의 개수입니다. 입력 데이터의 분포에 따라 성능이 달라질 수
 * 있으며, 데이터가 불균형하게 분포되면 성능이 저하될 수 있습니다.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

/**
 * 버킷 정렬
 * @param arr 정렬할 배열
 * @param size 배열 크기
 * @param k 버킷 개수
 */
void asc_bucket_sort(int arr[], int size, int k)
{
    if (size <= 0)
    {
        return;
    }

    // 최소값과 최대값 구하기
    int max_value = arr[0];
    int min_value = arr[0];

    for (int i = 1; i < size; i++)
    {
        min_value = min(min_value, arr[i]);
        max_value = max(max_value, arr[i]);
    }

    // 버킷 크기 계산
    double bucket_size = (static_cast<double>(max_value - min_value) / k) + 1;

    // 데이터를 버킷에 삽입
    vector<vector<int>> buckets(k);

    for (int i = 0; i < size; i++)
    {
        int index = static_cast<int>((arr[i] - min_value) / bucket_size);
        buckets[index].push_back(arr[i]);
    }

    // 각 버킷을 정렬 후 원본 배열에 복사
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
        for (int num : buckets[i])
        {
            arr[index++] = num;
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

    asc_bucket_sort(arr, size, 4);

    cout << "정렬 후: ";
    print_array(arr, size);

    return 0;
}