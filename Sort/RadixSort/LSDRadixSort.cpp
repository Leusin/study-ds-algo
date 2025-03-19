/*
 * 기수 정렬(Radix Sort) - LSD 방식
 *
 * 숫자의 자릿수를 기준으로 정렬하는 비교 기반이 아닌 정렬 알고리즘입니다.
 * 가장 낮은 자릿수부터 시작하는 LSD(Lower Significant Digit) 
 * 방식과 가장 높은 자릿수부터 정렬하는 MSD(Most Significant Digit)
 * 방식이 존재합니다.
 * 
 * - LSD 방식은 구현이 간단하고, 정렬이 안정적이며, 고정된 자릿수를
 * 가진 데이터에서 효과적입니다.
 * 
 * - MSD 방식은 긴 숫자에서 효율적일 수 있지만, 재귀적으로 그룹을 
 * 나누며 정렬해야 하므로 구현이 복잡합니다.
 * 
 * 기수 정렬의 두 가지 방식 중에서는 LSD 기수 정렬이 가장 널리 
 * 사용됩니다. 각 자릿수별로 정렬을 반복하며, 가장 낮은 자릿수부터 시작해 
 * 차례대로 높은 자릿수까지 정렬을 진행합니다. 각 자릿수는 주로 계수 정렬을
 * 사용하여 처리하며, 자릿수를 기준으로 데이터를 그룹화하고 이를 반복하여 
 * 정렬합니다.
 *
 * 기수 정렬은 시간 복잡도는 O(NK)로, N은 리스트의 크기, K는 자릿수의
 * 개수입니다. 자릿수 K가 상대적으로 작을 경우 매우 효율적이며, 숫자나
 * 문자열처럼 자릿수가 정해져 있는 경우에 적합합니다.
 *
 */

#include <iostream>

using namespace std;

/**
 * 특정 자리수를 기준으로 정렬하는 계수 정렬
 * @param arr 정렬할 배열
 * @param size 배열 크기
 * @param base 기수(10 진법을 사용한다면 10)
 * @param place 정렬할 자리수
 */
void asc_count_sort(int arr[], int size, int base, int place)
{
    // 해당 자릿수 기준으로 숫자 세기
    int *counts = new int[base]{0};

    for (int i = 0; i < size; i++)
    {
        int digit = (arr[i] / place) % base;
        counts[digit]++;
    }

    // 누적 합 계산 (각 숫자의 정렬 위치 결정)
    for (int i = 1; i < base; i++)
    {
        counts[i] += counts[i - 1];
    }

    // 현재 자릿수를 기준으로 정렬된 결과 저장(뒤에서부터 채우기)
    int *sorted = new int[size];

    for (int i = size - 1; i >= 0; i--)
    {
        int digit = (arr[i] / place) % base;
        sorted[counts[digit] - 1] = arr[i];
        counts[digit]--;
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
 * 최하위 숫자(Least Significant Digit) 기수 정렬 함수
 * @param arr 정렬할 배열
 * @param size 배열 크기
 * @param base 기수(10 진법을 사용한다면 10)
 */
void lsd_radix_sort(int arr[], int size, int base = 10)
{
    if (size <= 0)
    {
        return;
    }

    int max_value = arr[0];

    // 최소값 구하기
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }

    // 1의 자리부터 정렬 반복
    for (int place = 1; max_value / place > 0; place *= base)
    {
        asc_count_sort(arr, size, base, place);
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

    lsd_radix_sort(arr, size);

    cout << "정렬 후: ";
    print_array(arr, size);

    return 0;
}