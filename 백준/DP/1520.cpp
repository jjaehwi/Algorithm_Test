// 내리막길 G3
// dp, 그래프 탐색, dfs
#include <iostream>
using namespace std;
#define MAX_SIZE 501
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int map[MAX_SIZE][MAX_SIZE];
// DP[a][b] = c 는 (a, b)에서 (N , M) 까지 c개의 경로로 도달할 수 있다.
int dp[MAX_SIZE][MAX_SIZE];
int N, M;
// int cnt = 1;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dfs(int x, int y)
{

    // cout << "\n"
    //      << cnt << "번째 dp\n ";
    // cnt++;
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= M; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    if (x == N && y == M)
        return 1;
    if (dp[x][y] != -1)
        return dp[x][y];
    dp[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && ny >= 1 && nx <= N && ny <= M)
            if (map[nx][ny] < map[x][y])
                dp[x][y] = dp[x][y] + dfs(nx, ny);
    }
    return dp[x][y];
}
int main()
{
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            cin >> map[i][j];
            dp[i][j] = -1;
        }

    cout << dfs(1, 1);
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= M; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}