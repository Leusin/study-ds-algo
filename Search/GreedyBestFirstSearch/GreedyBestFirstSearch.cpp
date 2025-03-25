/*
 * 탐욕적 최적 우선 탐색(Greedy Best First Search)

 * 휴리스틱 값을 사용하여 목표까지의 추정 비용이 가장 낮은 노드를 우선 
 * 탐색하는 방법입니다.
 * 
 * 구현이 간단하고 빠르지만 최적해를 보장하지 않으며 지역
 * 최적해에 빠질 가능성이 있습니다.
 *
 */

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <unordered_map>

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
 * 탐욕적 최적 우선 탐색
 * @param graph 가중치 그래프 (인접 리스트)
 * @param start 시작 노드
 * @param goal 목표 노드
 * @param heuristic 추정치
 * @return 탐색 경로
 */
deque<int> gbfs(const vector<vector<int>> &graph, const int start,
                const int goal, vector<int> heuristic)
{

    priority_queue<
        pair<int, int>,         // (현재 노드, 누적 비용)
        vector<pair<int, int>>, // 내부 컨테이너로
        second_comparion>       // 오름차순으로 설정
        pq;

    // 경로 추적을 위한 부모 맵
    unordered_map<int, int> parent;
    deque<int> path;
    vector<bool> visited(graph.size(), false);

    // 시작 노드 등록
    pq.push({start, heuristic[start]});
    parent[start] = -1;

    while (!pq.empty())
    {
        auto [node, cost] = pq.top();
        pq.pop();

        if (visited[node])
        {
            continue;
        }
        visited[node] = true;

        // 목표 노드 도착 시 종료
        if (node == goal)
        {
            // 추적한 경로 결과 저장
            while (node != -1)
            {
                path.push_front(node);
                node = parent[node];
            }

            return path;
        }

        // 인접 노드 탐색
        for (auto neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                pq.push({neighbor, heuristic[neighbor]});
                if (!parent.count(neighbor))
                {
                    parent[neighbor] = node;
                }
            }
        }
    }

    return path;
}

int main()
{
    //       0
    //     /   \
    //    1      2
    //   / \    / \
    //  3   4  5---6
    vector<vector<int>> graph =
        {
            {1, 2},          // 0
            {0, 3, 4},       // 1
            {0, 5, 6},       // 2
            {1},             // 3
            {1},             // 4
            {2, 6},          // 5
            {2}              // 6
        };

    // 목표 노드까지의 예상 비용을 나타내는 휴리스틱 값
    vector<int> heuristic = {5, 3, 4, 2, 6, 1, 0};  // 목표 노드는 6번

    int targets[] = {3, 6, 9};
    for (int target : targets)
    {

        cout << "[gbfs 목표: " << target << "]\n";
        auto path = gbfs(graph, 0, target, heuristic);

        if (path.empty())
        {
            cout << "목표 노드를 찾을 수 없음";
        }
        else
        {
            cout << "경로: ";
            for (int node : path)
            {
                cout << node << " ";
            }
        }

        cout << "\n\n";
    }

    return 0;
}