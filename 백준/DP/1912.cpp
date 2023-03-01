// 연속합 S2
// dp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 100001
int n;
vector<int> v(MAX_SIZE);
vector<int> dp(MAX_SIZE);
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        dp[i] = v[i];
    }
    int maxSum = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1] + v[i]);
        if (maxSum < dp[i])
            maxSum = dp[i];
    }
    cout << maxSum << "\n";
}