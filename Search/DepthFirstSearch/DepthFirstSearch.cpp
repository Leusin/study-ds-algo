/*
 * 깊이 우선 탐색(Depth First Search)
 *
 * 그래프를 탐색할 때 가능한 한 깊게 들어가며 탐색하는 방식으로, 시작
 * 정점에서 인접한 정점으로 이동하고 더 이상 갈 곳이 없으면 돌아가 다른
 * 인접 정점을 탐색합니다.
 *
 * 이 과정은 스택을 사용하거나 재귀 호출을 통해 구현할 수 있으며, 그래프의
 * 연결 요소 찾기, 사이클 검출, 위상 정렬, 경로 탐색 등 다양한 그래프
 * 문제 해결에 활용됩니다.
 *
 * 그래프의 경우 트리리와 달리 노드가 순환하기 때문에 같은 노드를 방문하지
 * 않도록 불 배열을 사용합니다.
 *
 * 시간 복잡도는 O(V+E), 공간 복잡도는 O(V)입니다. DFS는 구현이
 * 간단하지만, 경로가 길어지거나 깊이가 깊어지면 스택 오버플로우나 메모리
 * 사용량 증가 등의 문제가 발생할 수 있습니다.
 *
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * 재귀 DFS
 * @param graph 탐색할 인접 리스트 그래프
 * @param visited 방문한 노드
 * @param start_node 현재 탐색 중인 노드
 * @param path 탐색 경로
 */
void dfs_rec(const vector<vector<int>> &graph, vector<bool> &visited,
             int current_node, vector<int> &path)
{
    visited[current_node] = true;

    path.push_back(current_node);

    for (int neighbor : graph[current_node])
    {
        if (visited[neighbor] == false)
        {
            dfs_rec(graph, visited, neighbor, path);
        }
    }
}

/**
 * DFS (재귀)
 * @param graph 탐색할 인접 리스트 그래프
 * @param start_node 탐색 시작 노드
 * @return 탐색 경로
 */
vector<int> dfs_recursive(const vector<vector<int>> &graph, int start_node)
{
    // 방문한 노드들을 저장할 벡터
    vector<int> path;

    // 방문한 노드
    vector<bool> visited(graph.size(), false);
    dfs_rec(graph, visited, start_node, path);

    return path;
}

/**
 * 비연결 그래프의 DFS (재귀)
 * @param graph 탐색할 인접 리스트 그래프
 * @param start_node 탐색 시작 노드
 * @return 탐색 경로
 */
void dfs_rec_disconnected(vector<vector<int>> &graph, vector<bool> &visited,
                          int current_node, vector<int> &path)
{
    visited[current_node] = true;

    path.push_back(current_node);

    for (int neighbor : graph[current_node])
    {
        if (!visited[neighbor])
        {
            dfs_rec_disconnected(graph, visited, neighbor, path);
        }
    }
}

/**
 * 비연결 무방향 그래프의 DFS
 * @param graph 탐색할 인접 리스트 그래프
 * @param start_node 탐색 시작 노드
 * @return 탐색 경로
 */
vector<int> dfs_disconnected(vector<vector<int>> &graph)
{
    vector<int> path;
    vector<bool> visited(graph.size(), false);

    for (int node = 0; node < graph.size(); node++)
    {
        if (!visited[node])
        {
            dfs_rec_disconnected(graph, visited, node, path);
        }
    }

    return path;
}

/**
 * DFS (스택 기반 반복)
 * @param graph 탐색할 인접 리스트 그래프
 * @param start_node 탐색 시작 노드
 * @return 탐색 경로
 */
vector<int> dfs_iterative(const vector<vector<int>> &graph, int start_node)
{
    vector<int> path;
    vector<bool> visited(graph.size(), false);
    stack<int> s;

    s.push(start_node);
    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        if (!visited[current])
        {
            visited[current] = true;
            path.push_back(current);

            // 스택이므로 뒤에서부터 방문하도록 역순 삽입
            for (auto it = graph[current].rbegin(); it != graph[current].rend(); it++)
            {
                if (!visited[*it])
                {
                    s.push(*it);
                }
            }
        }
    }

    return path;
}

/**
 * 벡터 출력 함수
 */
void print_vector(const vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> graph_connected =
        {
            {1, 2},    // 0
            {0, 3, 4}, // 1
            {0, 5, 6}, // 2
            {1},       // 3
            {1},       // 4
            {2},       // 5
            {2}        // 6
        };

    cout << "- 재귀 DFS 탐색 순서: ";
    print_vector(dfs_recursive(graph_connected, 0));

    cout << "- 반복(스택 사용) DFS 탐색 순서: ";
    print_vector(dfs_iterative(graph_connected, 0));

    vector<vector<int>> graph_disconnected =
        {
            {1, 2},    // 0
            {0, 3, 4}, // 1
            {0, 5, 6}, // 2
            {1},       // 3
            {1},       // 4
            {2},       // 5
            {2},       // 6
            {8},       // 7
            {7},       // 8
            {9},       // 9
            {8}        // 10
        };

    cout << "- 비연결 그래프의 재귀 DFS 탐색: ";
    print_vector(dfs_disconnected(graph_disconnected));

    return 0;
}