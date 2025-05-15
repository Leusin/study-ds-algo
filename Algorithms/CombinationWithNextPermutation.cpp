//
// # next_permutation으로 조합 생성 예제
//
// 조합(Combination)은 주어진 n개의 원소 중 r개를 순서 없이 선택하는 경우를 의미합니다.
// 이는 순서가 중요한 순열(Permutation)과 다릅니다.
//
// - 조합의 수학적 표현: nCr 또는 C(n, r)
// - 공식: nCr = n! / (r! * (n - r)!)
//
// std::next_permutation은 원래 순열을 생성하는 함수이지만,
// 마스크를 활용해 조합 또한 만들 수 있습니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 예제 원소
    vector<int> elems{7, 9, 1, 1, 4};

    int n = elems.size(); // 전체 원소 수 (5)
    int r = 3;            // 선택할 원소 수

    // 조합 생성을 위한 선택 마스크 생성 (0, 0, 1, 1, 1)
    vector<int> mask(n, 0);
    fill(mask.end() - r, mask.end(), 1);

    cout << "[조합 결과]\n";
    do
    {
        for (int i = 0; i < n; i++)
        {
            if (mask[i])
                cout << elems[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(mask.begin(), mask.end()));

    /*
        출력:
        1 1 4 
        9 1 4
        9 1 4
        9 1 1
        7 1 4
        7 1 4
        7 1 1
        7 9 4
        7 9 1
        7 9 1
    */

    // ---------------------------------------------
    // 마스크 벡터가 어떻게 변화하는지 확인 
    // ---------------------------------------------
    fill(mask.begin(), mask.end(), 0);
    fill(mask.end() - r, mask.end(), 1);

    cout << "\n[마스크 벡터 변화]\n";
    do
    {
        for (int i = 0; i < n; i++)
        {
            cout << mask[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(mask.begin(), mask.end()));

    /*
        출력:
        0 0 1 1 1 
        0 1 0 1 1
        0 1 1 0 1
        0 1 1 1 0
        1 0 0 1 1
        1 0 1 0 1
        1 0 1 1 0
        1 1 0 0 1
        1 1 0 1 0
        1 1 1 0 0
    */

    // 인덱스가 1인 위치의 원소를 출력하면 조합을 얻을 수 있다.
    /*
        elems: 7 9 1 1 4
        ---------------------
        mask: 0 0 1 1 1 -> 1 1 4
        mask: 0 1 0 1 1 -> 9 1 4
        mask: 0 1 1 0 1 -> 9 1 4
        mask: 0 1 1 1 0 -> 9 1 1
        ...
    */

    return 0;
}
