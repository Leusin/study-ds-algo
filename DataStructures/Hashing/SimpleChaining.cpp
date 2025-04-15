/**
 * 간단한 체이닝을 사용한 해시 테이블
 *
 * 체이닝은 하나의 해시 인덱스에 여러 키가 매핑될 수 있습니다.
 * 해시 충돌이 발생할 경우, 해당 버킷의 리스트(벡터)에 값을 추가합니다.
 * 해시 테이블의 성능은 적절한 해시 함수와 적절한 버킷 수에 따라
 * 달라집니다.
 *
 * 모든 요소가 한 체인에 몰리는 최악의 경우 성능 저하가 발생합니다.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Hash
{
    // 해시테이블은 bucketCount개의 버킷을 가지고 있으며,
    // 각 버킷은 정수형 데이터를 저장할 수 있는 벡터입니다.
    int bucketCount;
    vector<vector<int>> table;

public:
    Hash(int bucketCount) : bucketCount(bucketCount),
                            table(bucketCount) {}

    // 해시 함수
    /*
     * 간단한 나머지 연산으로 인덱스를 계산합니다.
     */
    int Hashing(int key) const
    {
        return key % bucketCount;
    }

    // 삽입
    /*
     * 주어진 키를 해시함수로 변환해 해당 버킷 벡터에 삽입합니다.
     * 시간 복잡도: 평균 O(1), 최악 O(n)
     */
    void insert_item(int key)
    {
        int index = Hashing(key);
        table[index].push_back(key);
    }

    // 삭제
    /*
     * 해당 키를 가진 버킷의 우치를 찾고 삭제합니다.
     * 시간 복잡도: 평균 O(1), 최악 O(n)
     */
    void delete_item(int key)
    {
        int index = Hashing(key);
        auto &chain = table[index];
        auto it = find(chain.begin(), chain.end(), key);
        if (it != chain.end())
        {
            chain.erase(it);
        }
    }

    // 출력
    /*
     * 모든 버킷을 순외하며 저장된 값을 출력합니다.
     * 시간 복잡도: 평균 O(n + b) (b: 버킷의 수)
     */
    void display_hash() const
    {
        for (int i = 0; i < bucketCount; ++i)
        {
            cout << i;
            for (int val : table[i])
            {
                cout << " -> " << val;
            }
            cout << '\n';
        }
    }
};

int main()
{
    vector<int> keys = {15, 11, 27, 8, 12};

    Hash hash(7);
    for (int key : keys)
    {
        hash.insert_item(key);
    }

    hash.delete_item(12);
    hash.display_hash();

    return 0;
}