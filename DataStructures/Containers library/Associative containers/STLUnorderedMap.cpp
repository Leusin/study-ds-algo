//
// unordered_set
//
// 내부 구조가 해시 기반이기 때문에 데이터를 정렬하지 않으며며
// 삽입, 삭제, 탐색의 시간 복잡도가 O(1)입니다. 
//

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<char, int> um;

    /**
     * 셋의 삽입과 삭제, 검색
     */
    um['a'] = 1;
    um['b'] = 2;
    um['c'] = 3;
    um['d'] = 4;
    
    // 정렬되지 않게 출력 (d:4 c:3 b:2 a:1)
    for(const auto& e: um) 
    {
        cout << e.first << ":" << e.second << " "; 
    }

    return 0;
}