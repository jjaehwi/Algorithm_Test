// 합 분해 G5
// dp
#include <iostream>
using namespace std;

int dp[201][201];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= k; i++)
        dp[1][i] = i;

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= k; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;

    cout << dp[n][k] << endl;

    return 0;
}

/*   k=1    k=2     k=3     k=4

n=1   1     2       3       4
n=2   1     3       6       10
n=3   1     4       10      20
n=4   1     5       15      35
n=5   1     6       21      56
n=6   1     7       28      84

n과 k는 (n-1, k)일 때의 방법과 (n, k-1)일 때의 방법의 합
*/
