// 동전 1 G5
// dp
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 101
#define MAX_SIZE2 10001
int n, k;
vector<int> v(MAX_SIZE);
vector<int> dp(MAX_SIZE2);
int main()
{
    fastio;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    dp[0] = 1; // 아무 동전도 선택하지 않은 경우
    for (int i = 0; i < n; i++)
        // 각 동전에 대해
        for (int j = v[i]; j <= k; j++)
            dp[j] += dp[j - v[i]];
    // for (int i = 0; i <= k; i++)
    //     cout << dp[i] << " ";
    cout << dp[k] << "\n";
}

/*
v0 = 1
v1 = 2
v2 = 5
--> 10원

dp[0] = 1
dp[1] = 1
dp[2] = 1 + 1
dp[3] = 1 + 1
dp[4] = 1 + 2
dp[5] = 1 + 2 + 1
dp[6] = 1 + 3  + 1
dp[7] = 1 + 3 + 2
dp[8] = 1 + 4 + 2
dp[9] = 1 + 4 + 3
dp[10] = 1 + 5 + 4

v[i] 를 순회하면서..
dp[i] -> dp[i]원을 만드는 경우의 수...
k 만큼 채우기.. --> dp[k]
*/