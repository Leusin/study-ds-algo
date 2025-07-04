/*
 * 너비 우선 탐색(Breath First Search)
 *
 * 너비 우선 탐색(BFS)은 그래프를 순회하는 기본적인 알고리즘으로, 시작
 * 정점에서 가까운 정점부터 차례로 탐색합니다.
 * 
 * 큐(Queue)를 활용하여 정점을 방문하고, 방문한 정점의 이웃을 차례로
 * 큐에 넣으며 진행합니다. 그래프의 경우 트리와 달리 노드가 순환하기 때문에
 * 같은 노드를 방문하지 않도록 불 배열을 사용합니다.
 * 
 * 시간 복잡도는 O(V+E), 공간 복잡도는 O(V)입니다. 그래프의 모든
 * 정점을 탐색하는 데 적합하지만, 노드 수가 많을수록 탐색 범위가 선형적으로
 * 증가하여 성능 저하가 발생할 수 있습니다.
 *
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * 시작점이 주어진 BFS
 * @param graph 탐색할 인접 리스트 그래프
 * @param start_node 탐색 시작 노드
 * @return 탐색 경로
 */
vector<int> bfs_from_source(const vector<vector<int>> &graph, int start_node)
{
    // 방문한 노드들을 저장할 벡터
    vector<int> path;

    // 그래프의 정점 수
    int vertex_size = graph.size();

    // 방문한 노드
    vector<bool> visited(vertex_size, false);
    visited[start_node] = true;

    // 탐색 순서를 관리하는 방문 노드 대기열
    queue<int> node_to_visit;
    node_to_visit.push(start_node);

    // BFS 탐색 시작
    while (!node_to_visit.empty())
    {
        // 대기열에서 노드 하나를 꺼내 탐색
        int current_node = node_to_visit.front();
        node_to_visit.pop();

        // 현재 노드를 방문 결과 기록
        path.push_back(current_node);

        // 현재 노드의 이웃 노드 탐색
        for (int neighbor_node : graph[current_node])
        {
            // 아직 방문하지 않은 이웃 노드를 대기열에 추가
            if (!visited[neighbor_node])
            {
                visited[neighbor_node] = true;
                node_to_visit.push(neighbor_node);
            }
        }
    }

    return path;
}

/**
 * 비연결 그래프의 BFS
 * @param graph 탐색할 인접 리스트 그래프
 * @return 탐색 경로
 */
vector<int> bfs_disconnected(vector<vector<int>> &graph)
{
    // 방문한 노드들을 저장할 벡터
    vector<int> path;

    // 그래프의 정점 수
    int vertex_size = graph.size();

    // 방문한 노드
    vector<bool> visited(vertex_size, false);

    for (int i = 0; i < vertex_size; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;

            // 탐색 순서를 관리하는 방문 노드 대기열
            queue<int> node_to_visit;
            node_to_visit.push(i);

            // BFS 탐색 시작
            while (!node_to_visit.empty())
            {
                // 대기열에서 노드 하나를 꺼내 탐색
                int current_node = node_to_visit.front();
                node_to_visit.pop();

                // 현재 노드를 방문 결과 기록
                path.push_back(current_node);

                // 현재 노드의 이웃 노드 탐색
                for (int neighbor_node : graph[current_node])
                {
                    // 아직 방문하지 않은 이웃 노드를 대기열에 추가
                    if (!visited[neighbor_node])
                    {
                        visited[neighbor_node] = true;
                        node_to_visit.push(neighbor_node);
                    }
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

int main(void)
{
    vector<vector<int>> graph_connected =
    {
        {1, 2},     // 0
        {0, 3, 4},  // 1
        {0, 5, 6},  // 2
        {1},        // 3
        {1},        // 4
        {2},        // 5
        {2}         // 6
    };
    
    auto result1 = bfs_from_source(graph_connected, 3);
    
    cout << "연결된 그래프의 탐색: ";
    print_vector(result1);

    vector<vector<int>> graph_disconnected =
    {
        {1, 2},    // 0
        {0, 3, 4}, // 1
        {0, 5, 6}, // 2
        {1},       // 3
        {1},       // 4
        {2},       // 5
        {2},       // 6
        {7},       // 7(단독 연결)
        {8},       // 8(단독 연결)
        {9},       // 9(단독 연결)
        {8}        // 10(단독 연결)
    };
    
    auto result2 = bfs_from_source(graph_disconnected, 0);
    
    cout << "연결되지 않은 그래프의 탐색(bfs_from_source): ";
    print_vector(result2);

    auto result3 = bfs_disconnected(graph_disconnected);
    
    cout << "연결되지 않은 그래프의 탐색(bfs_disconnected): ";
    print_vector(result3);

    return 0;
}
