// 숫자판 점프 S2
// 그래프 탐색, dfs, bfs
#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 5

int map[MAX_SIZE][MAX_SIZE], answer;
bool visited[1000000];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int sum, int cnt)
{
    if (cnt == 5)
    {
        if (visited[sum] == false)
        {
            visited[sum] = true;
            answer++;
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
            dfs(nx, ny, sum * 10 + map[nx][ny], cnt + 1);
    }
}
int main(void)
{
    fastio;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> map[i][j];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            dfs(i, j, map[i][j], 0);

    cout << answer << "\n";

    return 0;
}
