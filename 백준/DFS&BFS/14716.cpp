// 현수막 S1
// 그래프 탐색, bfs, dfs
#include <iostream>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 251
int M, N, cnt;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
// 상 하 좌 우 왼위, 오른위, 왼아래, 오른아래
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (map[next_x][next_y] == 1 && !visited[next_x][next_y])
            {
                q.push({next_x, next_y});
                visited[next_x][next_y] = true;
            }
        }
    }
}
int main()
{
    fastio;
    cin >> M >> N;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                cnt++;
                bfs(i, j);
            }
        }

    cout << cnt;
}