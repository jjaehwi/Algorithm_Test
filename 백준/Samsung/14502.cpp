// 연구소 G4
// bfs + 조합, 그래프 복사
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 9
int map[MAX_SIZE][MAX_SIZE];
int temp[MAX_SIZE][MAX_SIZE];
int N, M;
int max_value;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
// temp1 배열에 temp2 배열을 복사
void copy(int temp1[MAX_SIZE][MAX_SIZE], int temp2[MAX_SIZE][MAX_SIZE])
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            temp1[i][j] = temp2[i][j];
}
void bfs()
{
    int after[MAX_SIZE][MAX_SIZE]; // 바이러스가 퍼진 후 맵
    copy(after, temp);             // 벽이 세워진 맵을 가져온다.
    queue<pair<int, int>> q;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (after[i][j] == 2)
                q.push({i, j});

    while (q.size())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > N || ny < 1 || ny > M)
                continue;
            if (after[nx][ny] == 0)
            {
                after[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (after[i][j] == 0)
                cnt++;
    max_value = max(max_value, cnt);
}
void wall(int cur)
{
    // 벽을 3개 다 세우면 bfs
    if (cur == 3)
    {
        bfs();
        return;
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (temp[i][j] == 0)
            {
                temp[i][j] = 1;
                wall(cur + 1);
                temp[i][j] = 0;
            }
}
int main()
{
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> map[i][j];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (map[i][j] == 0)
            {
                copy(temp, map);
                temp[i][j] = 1;
                wall(1);
                temp[i][j] = 0;
            }
    cout << max_value;
}