// 쉬운 계단 수 S1
// dp
#include <iostream>
using namespace std;
#define MAX_SIZE_1 101
#define MAX_SIZE_2 10
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
long long dp[MAX_SIZE_1][MAX_SIZE_2];
int main()
{
    fastio;
    long long N, sum = 0;
    cin >> N;
    for (int i = 1; i < MAX_SIZE_2; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for (int j = 1; j < MAX_SIZE_2 - 1; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] % 1000000000) + (dp[i - 1][j + 1] % 1000000000);
        }
    }
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 0; j < MAX_SIZE_2; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 0; i < MAX_SIZE_2; i++)
        sum += dp[N][i] % 1000000000;
    cout << sum % 1000000000;
}