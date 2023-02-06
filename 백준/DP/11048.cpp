// 이동하기 S2
// dp
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 1001
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int map[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
int N, M;
int main()
{
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> map[i][j];

    dp[1][1] = map[1][1];

    for (int i = 2; i <= M; i++)
        dp[1][i] = dp[1][i - 1] + map[1][i];

    for (int i = 2; i <= N; i++)
        dp[i][1] = dp[i - 1][1] + map[i][1];

    for (int i = 2; i <= N; i++)
        for (int j = 2; j <= M; j++)
            dp[i][j] = map[i][j] + max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));
    // cout << "\n";
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= M; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    cout << dp[N][M];
}