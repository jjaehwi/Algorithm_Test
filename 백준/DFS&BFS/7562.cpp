// 나이트의 이동 S1
// 그래프 탐색, bfs
#include <iostream>
#include <queue>
#include <memory.h>
#include <utility>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 301
int visited[MAX_SIZE][MAX_SIZE];
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int l, start_x, start_y, goal_x, goal_y;
void bfs()
{
    queue<pair<int, int>> q;
    q.push(make_pair(start_x, start_y));
    while (!q.empty())
    {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            if (next_x >= 0 && next_x < l && next_y >= 0 && next_y < l && visited[next_x][next_y] == 0)
            {
                q.push(make_pair(next_x, next_y));
                visited[next_x][next_y] = visited[current_x][current_y] + 1;
            }
        }
    }
}
int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {

        cin >> l >> start_x >> start_y >> goal_x >> goal_y;
        visited[start_x][start_y] = 1;
        bfs();
        cout << visited[goal_x][goal_y] - 1 << "\n";
        memset(visited, 0, sizeof(visited));
    }
}