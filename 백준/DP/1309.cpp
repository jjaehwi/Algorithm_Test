// 동물원 S1
// dp
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 100001
int N;
vector<int> dp(MAX_SIZE);
int main()
{
    fastio;
    cin >> N;
    dp[1] = 3;
    dp[2] = 7;
    for (int i = 3; i <= N; i++)
        dp[i] = (dp[i - 1] * 2) % 9901 + dp[i - 2] % 9901;
    cout << dp[N] % 9901;
}

// 3
// 1+4+2 = 7
// 1+6+8+2 = 17
// 1+8+18+12+2 = 41
// N = (N-1) * 2 + (N-2)