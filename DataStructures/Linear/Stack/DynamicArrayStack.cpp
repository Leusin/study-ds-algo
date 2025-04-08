/*
 * 동적 배열 기반 스택
 *
 * 동적 배열(std::vector)을 감싸 간단하게 스택을 구현합니다.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Stack
{
    vector<int> s;

public:
    void push(int new_data)
    {
        s.push_back(new_data);
    }

    void pop()
    {
        if (!is_empty())
        {
            s.pop_back();
        }
    }

    int top()
    {
        if (is_empty())
        {
            throw runtime_error("Stack is empty");
        }

        return s.back();
    }

    bool is_empty()
    {
        return s.empty();
    }
};

int main()
{
    Stack st;

    cout << "스택에 값을 추가합니다: 10, 20, 30" << endl;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "현재 스택의 최상단 값: " << st.top() << endl;

    cout << "\n스택에서 두 개의 값을 제거합니다." << endl;
    st.pop();
    st.pop();

    cout << "현재 스택의 최상단 값: " << st.top() << endl;

    cout << "\n스택에서 남은 값들을 모두 제거합니다..." << endl;
    st.pop();

    cout << "스택이 비어있습니까?: " << (st.is_empty() ? "네" : "아니오") << endl;

    cout << "\n비어있는 스택에서 top() 호출 시도..." << endl;
    try
    {
        cout << "현재 스택의 최상단 값: " << st.top() << endl;
    }
    catch (const exception &e)
    {
        cout << "(오류 발생) " << e.what() << endl;
    }

    return 0;
}
