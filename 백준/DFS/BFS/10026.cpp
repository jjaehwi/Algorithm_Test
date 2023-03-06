// 적록색약 G5
// 그래프 탐색, bfs
#include <iostream>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 101
int n;
char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int result, result2;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    while (!q.empty())
    {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < n)
            {
                if (!visited[next_x][next_y])
                {
                    if (map[next_x][next_y] == map[current_x][current_y])
                    {
                        visited[next_x][next_y] = true;
                        q.push(make_pair(next_x, next_y));
                    }
                }
            }
        }
    }
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    // bfs();
    // bfs2();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j])
            {
                bfs(i, j);
                result++;
            }

    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (map[i][j] == 'G')
                map[i][j] = 'R';

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j])
            {
                bfs(i, j);
                result2++;
            }

    cout << result << " " << result2 << "\n";
}