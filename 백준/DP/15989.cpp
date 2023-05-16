// 1, 2, 3 더하기 4 S1
// dp

// 1 --> 1 (1)
// 2 --> 2 (11, 2)
// 3 --> 3 (111, 12, 3)
// 4 --> 4 (1111, 112, 22, 13)
// 5 --> 5 (11111, 1112, 113, 122, 23)
// 6 --> 7 (111111, 11112, 1113, 1122, 222, 33, 123)

// dp[i][j] = 정수 i 를 만들 때 마지막으로 더한 수가 j 인 경우의 수

/*
기존 값에서 i를 만들기 위해 더할 수 있는 수가 1인 경우
기존 값의 마지막 수가 1이 되어야 한다.
dp[i][1] = dp[i - 1][1];
*/

/*
기존 값에서 i를 만들기 위해 더할 수 있는 수가 2인 경우
기존 값의 마지막 수가 1 또는 2가 되어야 한다.
dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
*/

/*
기존 값에서 i를 만들기 위해 더할 수 있는 수가 3인 경우
기존 값의 마지막 수가 1 또는 2 또는 3이 되어야 한다.
dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
*/

#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 10001
int T, n;
long long dp[MAX_SIZE][4];

int main()
{
    fastio;
    cin >> T;

    dp[1][1] = 1;

    dp[2][1] = 1;
    dp[2][2] = 1;

    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int i = 4; i < MAX_SIZE; i++)
    {
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }

    while (T--)
    {
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }
}
