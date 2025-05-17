#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

bool compare(const Point& a, const Point& b)
{
    if(a.x == b.x)
    {
        return a.y < b.y;
    }

    return a.x < b.x;
}

int main()
{
    vector<int> v1 = {2, 1, 3, 3};
    vector<Point> v2 = {{3, 4}, {1, 2}, {3, 5}};

    /**
     * 일치하는 값 횟수 세기
     */
    int count_result = count(v1.begin(), v1.end(), 3); // 3 값이 컨테이너에 몇 번 나타나는지 세기 (2)

    /**
     * 함수로 정렬하기
     */
    sort(v1.begin(), v1.end()); // 오름차순으로 정렬 (1, 2, 3, 3)
    sort(v1.rbegin(), v1.rend()); // 내림차순으로 정렬 (3, 3, 2, 1)

    sort(v2.begin(), v2.end(), compare); // 사용자 비교 함수를 통해 오름차순으로 정렬 ((1, 2), (3, 4), (3, 5))

    /**
     * 가능한 모든 순열 생성하기
     */
    sort(v1.begin(), v1.end()); // 순열을 생성하기 전에 데이터가 사전 순으로 정렬된 상태여야 함.
    // 중복 값이 포함된 컨테이너라도 next_permutation은 중복되지 않은 순열만 생성 (O(N*N!))
    do
    {
        for(int i: v1)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    while(next_permutation(v1.begin(), v1.end()));
    /*
        출력값:
        1 2 3 3
        1 3 2 3
        1 3 3 2
        2 1 3 3
        2 3 1 3
        2 3 3 1
        3 1 2 3
        3 1 3 2
        3 2 1 3
        3 2 3 1
        3 3 1 2
        3 3 2 1
    */

    /**
     * 중복값 요소 제거
     */
    sort(v1.begin(), v1.end()); // 반드시 정렬되어 있어야 정상 작동

    auto new_end = unique(v1.begin(), v1.end()); // 중복되는 요소를 뒤로 밀어낸 뒤 중복되지 않는 새로운 범위의 끝 반복자를 반환(O(n))

    v1.erase(new_end, v1.end());

    /**
     * 이진 탐색하기
     */
    sort(v1.begin(), v1.end()); // 반드시 정렬되어 있어야 정상 작동

    bool contain = binary_search(v1.begin(), v1.end(), 3); // 값이 있다면 1 없다면 0 반환

    /**
     * 최댓값, 최소값 위치 구하기
     */
    auto max_it = max_element(v1.begin(), v1.end()); // 최대값 위치를 가르키는 반복자
    auto min_it = min_element(v1.begin(), v1.end()); // 최소값 위치를 가르키는 반복자

    return 0;
}