// 오르막 수 S1
// dp

#include <iostream>
using namespace std;
#define MAX_SIZE_1 1001
#define MAX_SIZE_2 11
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
long long dp[MAX_SIZE_1][MAX_SIZE_2];
int main()
{
    fastio;
    long long N, sum = 0;
    cin >> N;
    for (int i = 1; i <= MAX_SIZE_2; i++)
        dp[1][i] = 1;

    for (int i = 1; i <= MAX_SIZE_1; i++)
        dp[i][0] = 0;

    for (int i = 2; i <= N; i++)
        for (int j = 1; j < MAX_SIZE_2; j++)
            dp[i][j] = ((dp[i][j - 1] % 10007) + (dp[i - 1][j]) % 10007);

    for (int i = 1; i < MAX_SIZE_2; i++)
        sum += dp[N][i] % 10007;
    cout << sum % 10007;
}
/* 중복조합을 이용한 코드 --> 12부터 팩토리얼 계산 범위 초과
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
long long fact(long long n)
{
    if (n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}

long long main()
{
    fastio;
    long long N;
    cin >> N;
    // (10+N-1)! / N!(10-1)!
    cout << ((fact(10 + N - 1)) / (fact(N) * fact(10 - 1)));
}
*/