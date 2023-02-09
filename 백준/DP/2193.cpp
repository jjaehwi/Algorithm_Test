// 이친수 S3
// dp
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 91
int N;
long long dp[MAX_SIZE];
int main()
{
    fastio;
    cin >> N;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 2] + dp[i - 1];
    cout << dp[N];
}

// 10

// 100 101

// 1000 1001 1010

// 10000 10001 10010 10100 10101

// 100000 100001 100010 100100 100101 101000 101001 101010