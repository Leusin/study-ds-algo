//
// C++에서 std::string은 표준 라이브러리(STL)에서 제공하는 문자열 클래스입니다.
// 문자열을 더 쉽게 다루기 위해 제공되며, 내부적으로 char 배열을 감싸고 여러 편의 기능을 제공합니다.
//
#include <string>

using namespace std;

int main()
{
    /**
     * 문자열 선언 및 초기화
     */
    string str;                    // 빈 문자열 선언
    string str1 = "Hello, World!"; // 직접 초기화
    string str2(str1);             // 복사 초기화
    string str3(str1, 0, 5);       // 부분 복사 초기화 ("Hello")
    string str4(8, '*');           // 반복된 문자 초기화 ("********")

    /**
     * 문자열 찾기
     */
    size_t pos1 = str1.find("Hello"); // 문자열 찾기 (0)
    size_t pos2 = str1.find('W');     // 문자 찾기 (7)

    size_t pos3 = str1.find("Hello", 2); // 2번째 자리부터 문자열 찾기 (18446744073709551615; string::npos)

    /**
     * 문자열 추가와 수정
     */
    string str5 = "Hi";
    str5 += ", World!"; // 문자열 추가 ("Hi, World!")

    str5[1] = 'e'; // 1번째 문자 수정 'i' → 'e' ("He, World!")
    str5[2] = 'y'; // 2번째 문자 수정',' → 'y' ("Hey World!")
    
    str5.replace(4, 5, "Apple"); // 인덱스 4부터 5글자를 "Apple"로 대체

    /* 문자열 자르기 */
    string str6 ="0123456789abcdefghij"; // size 가 21(0 ~ 20) 인 문자열
    string sub1 = str6.substr(0, 4); // 0번째 자리 문자 부터 4개 길이의 문자열 ("0123")
}