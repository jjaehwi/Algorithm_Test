// 그림 S1
// 그래프 이론, bfs, dfs
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 501
int n, m;
int cnt, maxVal, maxCnt;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
queue<pair<int, int>> q;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs()
{
    while (!q.empty())
    {
        maxCnt++;
        // cout << maxCnt << "\n";
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < m && map[next_x][next_y] == 1 && !visited[next_x][next_y])
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
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                maxCnt = 0;
                cnt++;
                visited[i][j] = true;
                q.push(make_pair(i, j));
                bfs();
            }
            maxVal = max(maxVal, maxCnt);
        }
    }
    cout << cnt << "\n"
         << maxVal << "\n";
}
