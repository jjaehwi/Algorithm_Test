// 안전 영역 S1
// 그래프 탐색, bfs
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <memory.h>
using namespace std;
#define MAX_SIZE 101
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int N, cnt;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int start_x, int start_y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(start_x, start_y));
    while (!q.empty())
    {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= N && !visited[next_x][next_y])
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
    int maxCnt = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];

    for (int h = 0; h <= 100; h++)
    {
        cnt = 0;
        memset(visited, false, sizeof(visited)); // 비가 온 정도가 증가하면 방문 배열을 초기화 시켜준다.
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                if (map[i][j] <= h)
                    visited[i][j] = true;
            }

        for (int ii = 1; ii <= N; ii++)
            for (int jj = 1; jj <= N; jj++)
                if (map[ii][jj] > h && !visited[ii][jj])
                {
                    cnt++;
                    bfs(ii, jj);
                }
        maxCnt = max(cnt, maxCnt);
    }
    cout << maxCnt;
}