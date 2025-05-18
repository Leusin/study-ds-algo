//
// set
//
// 중복을 허용하지 않고, 저장된 데이터를 자동으로 정렬하는 컨테이너입니다.
// 원소를 삽입하거나 삭제할 때 내부에서 균형 이진 탐색 트리(RB-Tree)를 이용해 정렬 상태를 유지하며 시간 복잡도는 log(N) 입니다.
//

#include <set>

using namespace std;

int main()
{

    /**
     * 셋의 선언 및 초기화
     */
    set<int> s; // 빈 셋 선언

    set<int> s1 = {1, 2, 3}; // 초기화 리스트 초기화
    set<int> s2(s1);         // 복사 초기화

    /**
     * 셋의 원소 찾기
     */
    int e = -1;

    auto it1 = s1.find(2);
    if (it1 != s1.end())
    {
        e = *it1; // 2를 찾은 경우 e에 대입
    }

    auto it2 = s1.find(6);
    if (it2 != s1.end())
    {
        e = *it2; // 6을 찾은 경우 e에 대입
    }

    /**
     * 셋의 삽입과 삭제, 검색
     */
    s1.insert(4); // 원소 4 삽입 (1, 2, 3, 4)
    s1.erase(2); // 원소 2 삭제 (1, 3, 4)

    // 원소 4가 있는 지 확인 후 삭제
    auto it = s1.find(4);
    if(it != s1.end())
    {
        s1.erase(it);
    }

    return 0;
}