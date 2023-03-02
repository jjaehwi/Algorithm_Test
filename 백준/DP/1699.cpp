// 제곱수의 합 S2
// 수학, dp
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 100001
vector<int> dp(MAX_SIZE);
int N;
int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++)
            if (dp[i] > dp[i - j * j] + 1)
                dp[i] = dp[i - j * j] + 1;
    }
    // for (int i = 1; i <= N; i++)
    //     cout << dp[i] << " ";
    cout << dp[N] << "\n";
}

// 1 = 1^2 --> 1
// 2 = 1^2 + 1^2 --> 2
// 3 = 1^2 + 1^2 + 1^2 --> 3
// 4 = 2^2 --> 1
// 5 = 2^2 + 1^2 --> 2
// 6 = 2^2 + 1^2 + 1^2 --> 3
// 7 = 2^2 + 1^2 + 1^2 + 1^2 --> 4
// 8 = 2^2 + 2^2 --> 2
// 9 = 3^2 --> 1