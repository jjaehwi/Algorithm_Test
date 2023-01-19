// 정수 삼각형 dp
#include <iostream>
#include <algorithm>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 501

int n;
int tri[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> tri[i][j];

    // 현재 내 위치에서의 최대값
    // 내 위치의 값 + 대각선 위 값 or 바로 위 값 둘 중 더 큰 것
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = tri[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);

    // 위에서부터 아래로 계속 더해져오기 때문에
    // 마지막 줄에 무조건 제일 큰 값이 들어있을 것이다.
    // 마지막 줄을 선회하며 가장 큰 값을 찾는다.
    int result = 0;
    for (int i = 1; i <= n; i++)
        result = max(result, dp[n][i]);
    cout << result;
}