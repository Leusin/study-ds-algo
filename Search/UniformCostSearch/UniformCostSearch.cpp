/*
 * 균일 비용 탐색(Uniform Cost Search)
 *
 * 가중치가 있는 그래프에서 최단 경로를 찾는 알고리즘으로, 다익스트라와
 * 유사하지만 목표 노드에 도달하면 즉시 종료하여 불필요한 탐색을 줄일 수
 * 있습니다.
 *
 * 우선순위 큐를 사용해 현재까지의 최저 비용 경로를 유지하며, 가중치가
 * 균등한 경우 BFS와 동일하게 동작합니다.
 *
 * 최적 해를 보장하며 목표 노드가 가까운 경우 다익스트라보다 효율적일 수
 * 있지만, 상태 공간이 많아지면 우선순위 큐의 크기가 커져 성능이 저하될 수
 * 있습니다.
 *
 */

#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

struct second_comparion
{
    constexpr bool operator()(
        pair<int, int> const &a,
        pair<int, int> const &b)
        const noexcept
    {
        return a.second > b.second;
    }
};

/**
 * 균일 비용 탐색 
 * @param graph 가중치 그래프 (인접 리스트)
 * @param start 시작 노드
 * @param goal 목표 노드
 * @param path 탐색 경로
 * @return 목표 노드를 찾으면 true, 아니면 false
 */
int ucs(vector<vector<pair<int, int>>> &graph, int start,
                        int goal, deque<int> &path)
{
    priority_queue<
        pair<int, int>,         // (현재 노드, 누적 비용)
        vector<pair<int, int>>, // 내부 컨테이너로
        second_comparion>       // 오름차순으로 설정
        pq;

    // 시작점에서 각 노드까지의 최소 비용
    vector<int> cost(graph.size(), INT_MAX);
    // 경로 추적용
    vector<int> parent(graph.size(), -1);

    // 시작 노드 등록
    pq.push({start, 0});
    cost[start] = 0;

    while (!pq.empty())
    {
        auto [node, cur_cost] = pq.top();
        pq.pop();

        // 목표 노드 도착 시 종료
        if (node == goal)
        {
            // 추적한 경로 결과 저장
            path.clear();
            for (int cur = goal; cur != -1; cur = parent[cur])
            {
                path.push_front(cur);
            }

            return cur_cost;
        }

        // 인접 노드 탐색
        for (auto [neighbor, weight] : graph[node])
        {
            int new_cost = cur_cost + weight;

            if (new_cost < cost[neighbor])
            {
                cost[neighbor] = new_cost;
                parent[neighbor] = node;
                pq.push({neighbor, new_cost});
            }
        }
    }

    // 목표 노드에 도달 할 수 없음
    return -1;
}

int main()
{
    //       0
    //     /   \
    //    1      2
    //   / \    / \
    //  3   4  5---6
    vector<vector<pair<int /*이동 가능한 노드*/, int /*비용*/>>> graph =
        {
            {{1, 1}, {2, 2}},          // 0
            {{0, 3}, {3, 4}, {4, 5}},  // 1
            {{0, 6}, {5, 7}, {6, 13}}, // 2
            {{1, 9}},                  // 3
            {{1, 10}},                 // 4
            {{2, 11}, {6, 1}},         // 5
            {{2, 12}}                  // 6
        };
    
    int targets[] = {3, 6, 9};
    for (int target : targets)
    {
        
        cout << "[ucs 목표: " << target << "]\n";
        deque<int> path;
        int cost = ucs(graph, 0, target, path);

        if (cost != -1)
        {
            cout << "최소 비용: " << cost << "\n";
            cout << "경로: ";
            for (int node : path)
            {
                cout << node << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "목표 노드를 찾을 수 없음\n";
        }
        cout << "\n";
    }
    

    return 0;
}