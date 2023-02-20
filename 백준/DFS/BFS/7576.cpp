// 토마토 G5
// 그래프 탐색, bfs
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define MAX_SIZE 1001
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int map[MAX_SIZE][MAX_SIZE];
int n, m, days;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;
void bfs()
{
    while (!q.empty())
    {
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            if (next_x < m && next_y < n && next_x >= 0 && next_y >= 0 && map[next_x][next_y] == 0)
            {
                q.push(make_pair(next_x, next_y));
                map[next_x][next_y] = map[current_x][current_y] + 1;
            }
        }
    }
}
int main()
{
    fastio;
    int exceptCase = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (map[i][j] == 1)
                q.push(make_pair(i, j));

    bfs();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            days = max(days, map[i][j]);
            if (map[i][j] == 0)
                exceptCase = -1;
        }

    if (exceptCase == -1)
        cout << -1;
    else
        cout << days - 1;
}