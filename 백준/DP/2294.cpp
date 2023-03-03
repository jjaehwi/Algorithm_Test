// 동전 2 G5
// dp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 101
#define MAX_SIZE2 100001
int n, k;
vector<int> v(MAX_SIZE);
vector<int> dp(MAX_SIZE2);
int main()
{
    fastio;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 0; i <= k; i++)
        dp[i] = MAX_SIZE2;
    dp[0] = 0; // 아무 동전도 선택하지 않은 경우
    for (int i = 1; i <= n; i++)
        // 각 동전에 대해
        for (int j = v[i]; j <= k; j++)
            dp[j] = min(dp[j], dp[j - v[i]] + 1);
    if (dp[k] == 100001)
        cout << -1;
    else
        cout << dp[k] << "\n";
}