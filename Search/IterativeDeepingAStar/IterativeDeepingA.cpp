/*
 * 반복 깊이증가 A* (Iterative Deepening A*)
 *
 * A* 알고리즘의 메모리 문제를 해결하기 위해 깊이 우선 탐색(DFS)과
 * A*의 평가 함수 개념을 결합한 알고리즘입니다.
 *
 * 기본적으로 f(n) = g(n) + h(n) 값을 임계값(threshold)으로
 * 설정하고, 이 값을 초과하지 않는 한에서 탐색을 수행한 후, 임계값을
 * 점진적으로 증가시키면서 최적 경로를 찾습니다.
 *
 */

#include <iostream>
#include <float.h> // FLT_MAX
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

const int g_row = 9;
const int g_col = 10;

/**
 * 유효 범위에 있는지 검사하는 헬퍼 함수
 * @param row 행 인덱스
 * @param col 열 인덱스
 * @return 유효한 범위이면 true, 아니면 false
 */
bool is_valid(int row, int col)
{
    return (0 <= row) && (row < g_row) && (0 <= col) && (col < g_col);
}

/**
 * 해당 셀이 막혔는지 검사하는 헬퍼 함수
 * @param grid 지도 (0: 장애물, 1: 통로)
 * @param row 행 인덱스
 * @param col 열 인덱스
 * @return 셀이 통로일 경우 true, 장애물일 경우 false
 */
bool is_unblocked(int grid[][g_col], int row, int col)
{
    return grid[row][col] == 1;
}

/**
 * 목표 지점에 도달했는지 검사하는 헬퍼 함수
 * @param row 현재 행 인덱스
 * @param col 현재 열 인덱스
 * @param goal 목표 지점 좌표
 * @return 목표 지점에 도달했다면 true, 아니면 false
 */
bool is_destination(int row, int col, pair<int, int> goal)
{
    return row == goal.first && col == goal.second;
}

/**
 * 맨해튼 거리 휴리스틱 함수
 * 목표 지점까지의 예상 비용을 계산
 * @param row 현재 행 인덱스
 * @param col 현재 열 인덱스
 * @param goal 목표 지점 좌표
 * @return 휴리스틱 값 (맨해튼 거리)
 */
double heuristic(int row, int col, pair<int, int> goal)
{
    return abs(row - goal.first) + abs(col - goal.second);
}

/**
 * IDA* 탐색 함수 (깊이 우선 탐색 + A* 평가 함수)
 * 주어진 임계값 내에서 깊이 우선 탐색을 수행하고,
 * 목표에 도달하면 -1을 반환, 경로를 찾지 못하면 임계값을 반환
 * @param grid 지도
 * @param x 현재 행 인덱스
 * @param y 현재 열 인덱스
 * @param goal 목표 지점 좌표
 * @param threshold 현재 임계값
 * @param path 현재까지의 경로
 * @return f 값 (임계값을 초과하면 그 값을 반환, 목표에 도달하면 -1 반환)
 */
double ida_star(int grid[][g_col], int x, int y,
                const pair<int, int> goal, double threshold, vector<pair<int, int>> &path)
{
    // f(n) = g(n) + h(n)
    double f = path.size() + heuristic(x, y, goal);

    if (f > threshold)
    {
        return f; // 임계값 초과 시 반환
    }

    // 목표를 찾은 경우
    if (is_destination(x, y, goal))
    {
        return -1; // 목표 도착
    }

    // 임계값을 갱신할 최소값
    double min_threshold = FLT_MAX;

    /*
           N
           |
     W --- + --- E
           |
           S

     현위치      | ( i, j )
     ----------------------------
     북: N       |  (i-1, j)
     남: S       |  (i+1, j)
     동: E       |  (i, j+1)
     서: W       |  (i, j-1)

    */
    // 이동 방향: N, S, E,  W
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    // 4방향 탐색
    for (int d = 0; d < 4; d++)
    {
        int i = x + dx[d];
        int j = y + dy[d];

        // 새 위치가 유효하고 통로인 경우
        if (is_valid(i, j) && is_unblocked(grid, i, j))
        {
            grid[i][j] = 2; // 방문 표시
            path.push_back({i, j});

            // 재귀 호출을 통한 깊이 우선 탐색
            double result = ida_star(grid, i, j, goal, threshold, path);

            // 목표를 찾은 경우
            if (result == -1)
            {
                return -1; // 목표 도착
            }

            // 최소 임계값 갱신
            min_threshold = min(min_threshold, result);

            grid[i][j] = 1; // 방문 해제
            path.pop_back();
        }
    }

    return min_threshold;
}

/**
 * IDA* 알고리즘을 실행하는 함수
 * 임계값을 증가시키며 반복적으로 탐색을 수행하여 경로를 찾는다.
 * @param grid 지도
 * @param x 시작 위치의 행 인덱스
 * @param y 시작 위치의 열 인덱스
 * @param goal 목표 지점 좌표
 * @return 경로 (경로를 찾지 못하면 빈 경로 반환)
 */
vector<pair<int, int>> ida(int grid[][g_col], int x, int y, pair<int, int> goal)
{
    // 초기 임계값 설정(시작점에서 목표까지의 맨해튼 거리)
    double threshold = heuristic(x, y, goal);

    vector<pair<int, int>> path;
    path.push_back({x, y});

    while (true)
    {
        // 임계값을 초과하지 않는 범위 내에서 탐색 수행
        double result = ida_star(grid, x, y, goal, threshold, path);

        // 목표를 찾으면 경로를 반환
        if (result == -1)
        {
            return path;
        }

        // 경로를 찾지 못하고 더 이상 탐색할 수 없으면 빈 경로를 반환
        if (result == FLT_MAX)
        {
            return {}; // 경로 없음
        }

        // 탐색 목표에 도달하지 못할 시 임계값 증가
        threshold = result;
    }
}

int main()
{
    // 1 = 이동 가능, 0 = 장애물
    int grid[g_row][g_col] = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
                              {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
                              {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
                              {0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
                              {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
                              {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
                              {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                              {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
                              {1, 1, 1, 0, 0, 0, 1, 0, 0, 1}};

    int start_x = 0;
    int start_y = 0;
    pair<int, int> goal = {8, 0};

    vector<pair<int, int>> path = ida(grid, start_x, start_y, goal);

    if (!path.empty())
    {
        cout << "[경로]\n";
        for (auto &[x, y] : path)
        {
            cout << "-> (" << x << ", " << y << ")";
        }
        cout << ": 도착\n";
    }
    else
    {
        cout << "경로를 찾지 못했습니다.\n";
    }

    return 0;
}
