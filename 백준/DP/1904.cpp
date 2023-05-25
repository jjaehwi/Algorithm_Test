// 01타일 S3
// DP

// 00, 1 로 이뤄진 타일
// 1 --> 1      (1)
// 2 --> 00, 11 (2)
// 3 --> 001, 100, 111 (3)
// 4 --> 0000, 0011, 1100, 1111, 1001 (5)
// 5 --> 00001, 00100, 10000, 00111, 10011, 11001, 11100, 11111 (8)
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1000001
int N;
long long dp[MAX_SIZE];
int main()
{
    fastio;
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
    }

    cout << dp[N] % 15746;
}
