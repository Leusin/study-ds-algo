/**
 * 체이닝과 리해싱을 사용한 해시 테이블
 *
 * 체이닝은 동일한 해시 인덱스에 여러 키가 충돌할 수 있도록 각 버킷을
 * 리스트(벡터)로 구성하여 충돌을 효과적으로 처리합니다. 
 * 
 * 리해싱은 테이블의 성능 저하를 방지하기 위해 필요 시 수행되며, 모든 
 * 데이터를 새로운 테이블로 재분배합니다.
 *
 * 리해싱 시 전체 데이터를 재처리해야 하므로 일시적인 성능 저하가 발생할 수
 * 있습니다.
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

    int numOfElements;

    static constexpr float MAX_LOAD_FACTOR = 0.5f;

public:
    Hash(int bucketCount) : bucketCount(bucketCount),
                            table(bucketCount),
                            numOfElements(0) {}

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
     * 이 때 부하율을 검사하고 리해싱을 진행합니다.
     * 시간 복잡도: 평균 O(1), 최악 O(n)
     */
    void insert_item(int key)
    {
        while (get_load_factor() > MAX_LOAD_FACTOR)
        {
            rehashing();
        }

        int index = Hashing(key);
        table[index].push_back(key);
        numOfElements++;
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
            numOfElements--;
        }
    }

    // 리해싱
    /*
     * 부하율이 높아졌을 때 성능 유지를 위해 수행합니다.
     * 기존 테이블의 크기를 2배로 늘리고, 새로운 테이블에 재삽입한 뒤
     * 모든 키에 대해 새로운 인덱스를 부여합니다.
     * 시간 복잡도: O(n)
     */
    void rehashing()
    {
        bucketCount *= 2;
        vector<vector<int>> oldTable = table;

        table.clear();
        table.resize(bucketCount);
        numOfElements = 0;

        for (const auto &table : oldTable)
        {
            for (int key : table)
            {
                insert_item(key);
            }
        }
    }

    // 부하율 계산
    float get_load_factor()
    {
        return (float)numOfElements / bucketCount;
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

    hash.insert_item(33);
    hash.insert_item(45);
    hash.insert_item(19);

    cout << "\n리해싱 이후:\n";
    hash.display_hash();

    return 0;
}