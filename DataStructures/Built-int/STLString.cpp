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
    string str1;                   // 빈 문자열 선언
    string str2 = "Hello, World!"; // 직접 초기화
    string str3(str2);             // 복사 초기화
    string str4(str2, 0, 5);       // 부분 복사 초기화 ("Hello")
    string str5(8, '*');           // 반복된 문자 초기화 ("********")

    /**
     * 문자열 찾기
     */
    size_t pos1 = str2.find("Hello"); // 문자열 찾기 (0)
    size_t pos2 = str2.find('W');     // 문자 찾기 (7)

    size_t pos3 = str2.find("Hello", 2); // 2번째 자리부터 문자열 찾기 (18446744073709551615; string::npos)

    /**
     * 문자열 추가와 수정
     */
    string str6 = "Hi";
    str6 += ", World!"; // 문자열 추가 ("Hi, World!")

    str6[1] = 'e'; // 1번째 문자 수정 'i' → 'e' ("He, World!")
    str6[2] = 'y'; // 2번째 문자 수정',' → 'y' ("Hey World!")
    
    str6.replace(4, 5, "Apple"); // 인덱스 4부터 5글자를 "Apple"로 대체

}