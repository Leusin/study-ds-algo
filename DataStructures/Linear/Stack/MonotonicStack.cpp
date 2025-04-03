/*
 * 모노토닉 스택
 *
 * 항상 모노토닉(단조로운, 단조)한 순서를 유지하는 스택이며, 특정 문제를 
 * 효율적으로 해결하는 데 사용됩니다.
 * 
 * 스택의 요소가 아래에서 위로(또는 위에서 아래로) 증가하는 순서로 유지되며
 * 새로운 값이 더 작다면(또는 크면) 기존 요소를 제거하며 정렬 유지합니다.
 * 
 * 다음 큰거나 작은 요소 찾기, 특정 범위 내 최대/최소 값 찾기, 
 * 히스토그램에서 최대 직사각형 넓이 찾기 등의 문제에 해결에 응용할 수 
 * 있습니다.
 * 
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * 모노토닉 증가 스택
 * 주어진 배열에서 단조 증가(오름차순) 순서를 유지하는 요소들을 찾습니다.
 * 현재 요소보다 큰 값이 나오기 전까지의 값을 스택에서 제거합니다.
 *
 * @param nums 입력 벡터
 * @return 모노토닉 증가 순서를 유지한 벡터
 */
vector<int> monotonic_increasing_stack(const vector<int>& nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < n; i++) 
    {
        // 스택이 비어 있지 않고 현재 요소보다 큰 값이 있다면 제거
        while (!st.empty() && st.top() > nums[i]) 
        {
            st.pop();
        }
        
        // 현재 요소를 스택에 추가
        st.push(nums[i]);
    }

    // 스택에 남아 있는 값을 결과 벡터에 저장 (오름차순 정렬 유지)
    while (!st.empty()) 
    {
        result.insert(result.begin(), st.top());
        st.pop();
    }

    return result;
}

/**
 * 모노토닉 감소 스택
 * 주어진 배열에서 모노토닉 감소(내림차순) 순서를 유지하는 요소를 찾습니다.
 * 현재 요소보다 작은 값이 나오기 전까지의 값을 스택에 유지합니다.
 *
 * @param nums 입력 벡터
 * @return 모노토닉 감소 순서를 유지한 벡터
 */
vector<int> monotonic_decreasing_stack(const vector<int>& nums) 
{
    int n = nums.size();
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < n; i++) 
    {
        // 현재 요소보다 작은 값들은 필요 없으므로 제거
        while (!st.empty() && st.top() < nums[i]) 
        {
            st.pop();
        }

        // 현재 요소를 스택에 추가 (나중에 비교를 위해 유지)
        st.push(nums[i]);
    }

    // 스택에 남아 있는 값을 결과 벡터에 저장 (오름차순 정렬 유지)
    while (!st.empty()) 
    {
        result.insert(result.begin(), st.top());
        st.pop();
    }

    return result;
}

int main() 
{
    vector<int> nums = {2, 1, 3, 4, 2, 5, 1, 6};
    cout << "입력 배열 예제: ";
    for (int num : nums) 
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result_increasing = monotonic_increasing_stack(nums);
    // 2 
    // 1
    // 1, 3
    // 1, 3, 4
    // 1, 2
    // 1, 2, 5
    // 1, 1
    // 1, 1, 6
    cout << "모노토닉 증가 스택 실행 결과: ";
    for (int num : result_increasing) 
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result_decreasing = monotonic_decreasing_stack(nums);
    // 2, 1, 3, 4, 2, 5, 1, 6
    // 2
    // 2, 1
    // 3
    // 4
    // 4, 2
    // 5
    // 5, 1
    // 6
    cout << "모노토닉 감소 스택 실행 결과: ";
    for (int num : result_decreasing) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
