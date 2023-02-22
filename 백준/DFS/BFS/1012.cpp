// 유기농 배추 S2
// 그래프 탐색, dfs, bfs
#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>
using namespace std;
#define MAX_SIZE 51
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int t, m, n, k;
int cnt;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
queue<pair<int, int>> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs()
{
    while (!q.empty())
    {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && map[next_x][next_y] == 1 && !visited[next_x][next_y])
            {
                visited[next_x][next_y] = true;
                q.push(make_pair(next_x, next_y));
            }
        }
    }
}
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 1 && !visited[i][j])
                {
                    cnt++;
                    visited[i][j] = true;
                    q.push(make_pair(i, j));
                }
                bfs();
            }
        cout << cnt << "\n";
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        cnt = 0;
    }
}