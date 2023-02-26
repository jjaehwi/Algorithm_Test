// 포도주 시식 S1
// dp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 10001
int n;
vector<int> v;
vector<int> dp;
int main()
{
    fastio;
    cin >> n;
    v.resize(n + 1);
    dp.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    dp[0] = 0;
    dp[1] = v[1];
    dp[2] = v[1] + v[2];
    for (int i = 2; i <= n; i++)
    {
        // 1. i 번째를 마시지 않는 경우 i-1 번째가 max
        // 2. i 번째를 마시는 경우
        // 2-1. i-1 번째를 마셨을 경우
        // 2-2. i-1 번째를 마시지 않았을 경우
        dp[i] = max(dp[i - 1], max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]));
    }
    cout << dp[n];
}