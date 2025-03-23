/*
 * 반복 깊이 증가 탐색(Iterative Deepening DFS)
 *
 * DFS를 일정한 깊이 제한을 두고 반복적으로 수행하여 BFS와 유사한 탐색
 * 결과를 얻는 방식입니다.
 *
 * 깊이 제한을 1부터 증가시키며 DFS를 실행하고, 목표 노드가 발견되면
 * 탐색을 종료합니다.
 *
 * 각 단계에서 DFS를 반복 실행하기 때문에 비효율적으로 보일 수 있으나,
 * 대부분의 경우 중복 탐색이 적어 성능 저하가 크지 않습니다. 또한, 메모리
 * 사용이 적고 최단 경로 탐색이 가능하여 게임 AI 등에 자주 활용됩니다.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 깊이 제한 DFS(Depth-Limited Search, DLS)
 * @param graph 인접 리스트 그래프
 * @param current_node 현재 탐색 중인 노드
 * @param target 목표 노드
 * @param depth 현재 탐색 깊이
 * @param max_depth 최대 탐색 가능 깊이
 * @param path 탐색 경로
 * @return 목표 노드를 찾으면 true, 아니면 false
 */
bool dfs_limited(const vector<vector<int>> &graph, int current_node,
                 int target, int depth_limit, vector<int> &path)
{
    path.push_back(current_node);

    if (current_node == target)
    {
        // 목표 노드를 찾음
        return true;
    }

    if (depth_limit <= 0)
    {
        // 깊이 제한을 초과함
        path.pop_back();
        return false;
    }

    for (int neighbor : graph[current_node])
    {
        if (dfs_limited(graph, neighbor, target, depth_limit - 1, path))
        {
            // 목표 노드를 찾았으면 탐색 종료
            return true;
        }
    }

    path.pop_back();
    return false;
}

/**
 * 반복 깊이 증가 탐색(IDDFS)
 * @param graph 탐색할 인접 리스트 그래프
 * @param start_node 시작 노드
 * @param target 목표 노드
 * @param max_depth 최대 탐색 가능 깊이
 * @param path 탐색 경로
 * @return 목표 노드를 찾으면 true, 아니면 false
 */
bool iddfs(const vector<vector<int>> &graph, int start_node, int target,
           int max_depth, vector<int> &path)
{
    for (int depth = 0; depth <= max_depth; depth++)
    {
        // 목표 노드를 찾으면 true 반환
        if (dfs_limited(graph, start_node, target, depth, path))
        {
            return true;
        }
    }

    // 최대 깊이까지 탐색했지만 목표 노드를 찾지 못함
    return false;
}

int main()
{
    vector<vector<int>> graph =
        {
            {1, 2},    // 0
            {0, 3, 4}, // 1
            {0, 5, 6}, // 2
            {1},       // 3
            {1},       // 4
            {2},       // 5
            {2}        // 6
        };

    int max_depth = 3;
    int start = 0;
    vector<int> path;

    int targets[] = {6, 7};
    for (int target : targets)
    {
        if (iddfs(graph, start, target, max_depth, path))
        {
            cout << "목표 노드 " << target << " 의 경로: ";
            for (int node : path)
            {
                cout << node << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "목표 노드 " << target << " 를 찾을 수 없음\n";
        }
    }

    return 0;
}