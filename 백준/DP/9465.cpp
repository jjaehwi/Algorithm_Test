// 스티커 S1
// DP
#include <iostream>
#include <algorithm>

using namespace std;

int st[2][100001] = {0};
int dp[2][100001] = {0};

int main()
{
    int t;
    int n;
    int max = 0;

    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> st[0][i];

        for (int i = 0; i < n; i++)
            cin >> st[1][i];

        dp[0][0] = st[0][0];
        dp[1][0] = st[1][0];
        dp[0][1] = st[0][1] + dp[1][0];
        dp[1][1] = st[1][1] + dp[0][0];

        for (int i = 2; i < n; i++)
        {
            dp[0][i] = st[0][i] + std::max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] = st[1][i] + std::max(dp[0][i - 1], dp[0][i - 2]);
        }

        cout << std::max(dp[0][n - 1], dp[1][n - 1]) << endl;
    }
}