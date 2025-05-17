//
// map
//
// 키와 값을 쌍(pair)으로 갖는 연관 컨테이너입니다.
// 원소를 삽입하거나 삭제할 때 내부에서 균형 이진 탐색 트리(RB-Tree)를 이용해 정렬 상태를 유지하며 시간 복잡도는 log(N) 입니다.
//

#include<map>

using namespace std;

int main()
{
    /**
     * 맵의 선언 및 초기화
     */
    map<char, int> m1; // 빈 맵 선언

    // [] 연산자로 키-값 쌍 추가 (없는 키는 새로 추가됨)
    m1['a'] = 1;
    m1['b'] = 2;
    m1['c'] = 3;

    // 초기화 리스트 초기화
    map<char, int> m2 = { 
        {'d', 4},
        {'e', 5}};

    /**
     * 맵의 원소 접근
     */
    // [] 연산자를 사용해 키에 접근
    int e1 = m1['a']; // 키가 있는 경우 (1)
    int e2 = m1['f']; // 키가 없는 경우 (0)

    /**
     * 맵의 원소 변경
     */
    m1['b'] = 4;

    /**
     * 맵의 원소 찾기
     */
    int e3 = -1;

    auto it1 = m1.find('c');
    if(it1 != m1.end())
    {
        e3 = it1->second; // 'c'를 찾은 경우 e에 3 대입
    }

    /**
     * 맵의 삽입과 삭제, 검색
     */
    m1.insert(make_pair('g', 7));
    m1.insert(make_pair('h', 8));
    m1['i'] = 9;

    m1.erase('i');

    auto it2 = m1.find('h');
    if(it2 != m1.end())
    {
        m1.erase(it2);
    }

    return 0;
}