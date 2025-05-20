//
// unordered_set
//
// 내부 구조가 해시 기반이기 때문에 데이터를 정렬하지 않으며며
// 삽입, 삭제, 탐색의 시간 복잡도가 O(1)입니다. 
//

#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> us;

    /**
     * 셋의 삽입과 삭제, 검색
     */
    us.insert(1);
    us.insert(2);
    us.insert(3);
    us.insert(4);
    
    // 정렬되지 않게 출력 (4 3 2 1)
    for(int e: us) 
    {
        cout << e << " "; 
    } 

    return 0;
}