// 벽 부수고 이동하기 G3
// 그래프 탐색, bfs
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1001
int N, M, ans;
char map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE][2];
struct pos
{
    int x;
    int y;
    int checkWall;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int x, int y)
{
    queue<pos> q;
    q.push({x, y, 0});    // 0 : 벽을 깨지 않은 상태
    visited[x][y][0] = 1; // x, y 에 벽을 깨지 않은 상태에서 방문

    while (!q.empty())
    {
        int current_x = q.front().x;
        int current_y = q.front().y;
        int current_wall = q.front().checkWall;
        q.pop();

        // 최종 위치 도달
        if (current_x == N - 1 && current_y == M - 1)
            return visited[current_x][current_y][current_wall];

        // bfs
        for (int i = 0; i < 4; i++)
        {
            int nx = current_x + dx[i];
            int ny = current_y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            // 벽이 있고 현재 벽을 깬 상태가 아니라면
            if (map[nx][ny] == '1' && current_wall == 0)
            {
                q.push({nx, ny, current_wall + 1});
                visited[nx][ny][current_wall + 1] = visited[current_x][current_y][current_wall] + 1;
            }

            // 벽이 없고 방문하지 않은 곳이라면
            else if (map[nx][ny] == '0' && visited[nx][ny][current_wall] == 0)
            {
                q.push({nx, ny, current_wall});
                visited[nx][ny][current_wall] = visited[current_x][current_y][current_wall] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++)
            map[i][j] = str[j];
    }
    ans = bfs(0, 0);
    cout << ans;
}