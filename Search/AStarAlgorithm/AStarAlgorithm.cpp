/*
 * A* 알고리즘
 *
 * 최단 경로를 찾기 위해 휴리스틱 정보를 활용하는 탐색 기법으로, 실제 이동
 * 비용(g)과 목표까지의 예상 비용(h)을 더한 평가 함수 f(n)=g(n)+h(n)을
 * 사용하여 가장 유망한 경로를 우선적으로 탐색합니다.
 *
 * 너비 우선 탐색(BFS)이나 다익스트라 알고리즘보다 효율적으로 동작할 수
 * 있으며, 게임 AI, 네비게이션 시스템 등에서 널리 사용됩니다. 그러나
 * 휴리스틱 함수의 품질에 따라 탐색 성능과 정확성이 달라질 수 있으며,
 * 최적의 경로를 보장하지 못할 수도 있습니다.
 *
 */

#include <iostream>
#include <float.h> // FLT_MAX
#include <utility>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

const int g_row = 9;
const int g_col = 10;

/**
 * 각 지점의 정보를 저장합니다.
 */
struct cell
{
    int parent_i = -1; // 0 <= i < row
    int parent_j = -1; // 0 <= i < col

    double f = FLT_MAX; // 평가 함수: f = g + h
    double g = FLT_MAX; // 실제 이동 비용
    double h = FLT_MAX; // 목표 예상 비용
};

/// ----- 헬퍼 함수들 -----

/**
 * 유효 범위에 있는지 검사하는 헬퍼 함수
 * @param row 행 인덱스
 * @param col 열 인덱스
 */
bool is_valid(int row, int col)
{
    return (0 <= row) && (row < g_row) && (0 <= col) && (col < g_col);
}

/**
 * 해당 셀이 막혔는지 검사하는 헬퍼 함수
 * @param grid 지도
 * @param row 행 인덱스
 * @param col 열 인덱스
 */
bool is_unblocked(int grid[][g_col], int row, int col)
{
    return grid[row][col] == 1;
}

/**
 * 목표 지점에 도달했는지 검사하는 헬퍼 함수
 * @param row 행 인덱스
 * @param col 열 인덱스
 * @param goal 목표 지점
 */
bool is_destination(int row, int col, pair<int, int> goal)
{
    return row == goal.first && col == goal.second;
}

/**
 * 유클리드 거리 측정법으로 휴리스틱(h)을 검사하는 헬퍼 함수
 * @param row 행 인덱스
 * @param col 열 인덱스
 * @param goal 목표 지점
 */
double calculate_h_value(int row, int col, pair<int, int> goal)
{
    return (double)(sqrt(pow(row - goal.first, 2) +
                         pow(col - goal.second, 2)));
}

/**
 * 경로 추적 헬퍼 함수
 * @param cell_details // 모든 지점에 대한 정보를 저장하는 2차원 배열
 * @param goal 목표 지점
 * @return 목표지점까지의 경로
 */
vector<pair<int, int>> trace_path(cell cell_details[][g_col], pair<int, int> goal)
{
    int row = goal.first;
    int col = goal.second;

    vector<pair<int, int>> path;

    // 경로를 추적하여 담기
    while (!(cell_details[row][col].parent_i == row &&
             cell_details[row][col].parent_j == col))
    {
        path.push_back({row, col});
        int temp_row = cell_details[row][col].parent_i;
        int temp_col = cell_details[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }

    path.push_back({row, col});

    return path;
}

/**
 * A* 알고리즘
 * @param grid 지도
 * @param start 시작 지점
 * @param goal 목표 지점
 * @return 탐색 경로
 */
vector<pair<int, int>> astar_search(int grid[][g_col], const pair<int, int> start,
                                    const pair<int, int> goal)
{
    if (!is_valid(start.first, start.second) ||
        !is_valid(goal.first, goal.second) ||
        !is_unblocked(grid, start.first, start.second) ||
        !is_unblocked(grid, goal.first, goal.second))
    {
        return vector<pair<int, int>>();
    }

    if (is_destination(start.first, start.second, goal))
    {
        return vector<pair<int, int>>{start};
    }

    cell cell_details[g_row][g_col];
    int i = start.first;
    int j = start.second;
    cell_details[i][j].parent_i = i;
    cell_details[i][j].parent_j = j;
    cell_details[i][j].f = 0.0;
    cell_details[i][j].g = 0.0;
    cell_details[i][j].h = 0.0;

    // 이미 방문한 지점을 기록하는 배열
    bool closed_list[g_row][g_col] = {false};

    // 앞으로 탐색할 가능성 있는 지점 후보를 저장
    // <f, <i, j>> 형태로 저장되며 우선순위 큐처럼 가장 작은 f 값 부터 꺼냄
    set<pair<double, pair<int, int>>> open_list;
    open_list.insert({0.0, {i, j}}); // 시작 지점의 평가 함수는 0

    while (!open_list.empty())
    {
        pair<double, pair<int, int>> p = *open_list.begin();
        open_list.erase(open_list.begin());
        int i = p.second.first;
        int j = p.second.second;
        closed_list[i][j] = true;

        /*
         All the 8 successor of this cell

               NW   N   NE
                 \  |  /
             W -- Cell -- E
                 /  |  \
               SW   S   SE

         현위치: Cell | ( i, j )
        ----------------------------
         북: N       |  (i-1, j)
         남: S       |  (i+1, j)
         동: E       |  (i, j+1)
         서: W       |  (i, j-1)
         - - - - - - - - - - - - - -

         북서: NW    |  (i-1, j-1)
         남동: SE    |  (i+1, j+1)
         남서: SW    |  (i+1, j-1)

         */

        // 8방향 탐색을 위한 배열: N, S, E, W, NE, NW, SE, SW
        const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
        const int dy[8] = {0, 0, 1, -1, 1, -1, 1, 1};

        // 8방향 탐색
        for (int d = 0; d < 8; d++)
        {
            int ni = i + dx[d];
            int nj = j + dy[d];

            // 유효한 좌표인지 확인
            if (is_valid(ni, nj))
            {
                // 도착 지점인지 확인
                if (is_destination(ni, nj, goal))
                {
                    cell_details[ni][nj].parent_i = i;
                    cell_details[ni][nj].parent_j = j;

                    return trace_path(cell_details, goal);
                }
                // 검사 가능 지점인지 확인
                else if (!closed_list[ni][nj] &&
                         is_unblocked(grid, ni, nj))
                {
                    // 상하좌우 이동 비용: 1, 대각선 이동 비용: 1.414(√2)
                    double new_g = cell_details[i][j].g + ((d < 4) ? 1.0 : 1.414);
                    double new_h = calculate_h_value(ni, nj, goal);
                    double new_f = new_g + new_h;

                    if (cell_details[ni][nj].f == FLT_MAX ||
                        cell_details[ni][nj].f > new_f)
                    {
                        open_list.insert({new_f, {ni, nj}});
                        cell_details[ni][nj].f = new_f;
                        cell_details[ni][nj].g = new_g;
                        cell_details[ni][nj].h = new_h;
                        cell_details[ni][nj].parent_i = i;
                        cell_details[ni][nj].parent_j = j;
                    }
                }
            }
        }
    }

    return vector<pair<int, int>>();
}

int main()
{
    // 0 은 갈 수 있는 경로, 1 은 막혀있는 경로
    int grid[g_row][g_col] = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
                              {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
                              {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
                              {0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
                              {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
                              {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
                              {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                              {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
                              {1, 1, 1, 0, 0, 0, 1, 0, 0, 1}};

    pair<int, int> start = {0, 0};
    pair<int, int> goal = {0, 0};

    auto path = astar_search(grid, start, goal);

    // 출력하기
    cout << "[경로]\n";
    for (auto [i, j] : path)
    {
        cout << "-> (" << i << ", " << j << ") ";
    }

    return 0;
}