// 계단오르기 S3
// DP
#include <iostream>
#include <algorithm>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 301

int n;
int stair[MAX_SIZE];
int dp[MAX_SIZE];

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> stair[i];

    /*
    1. 한번에 한 계단 또는 두 계단을 오를 수 있음
        --> 즉 i - 1, i - 2 번째 값을 사용할 수 있다는 뜻

    2. 연속된 세 개의 계단을 모두 밟아서는 안됨
        --> 즉, i - 1이 세번 이상 반복되면 안됨 --> 이 문제의 가장 난점!

    3. 마지막 도착 계단은 반드시 밟아야 함.

    -> 2의 조건을 생각하며 점화식을 구해야한다.
    -> i - 2 번째를 가지고 와서 계산하는 것은 간단하다. 하지만 i - 1 번째를 가지고 와야하는 경우, 방금 전에도 i - 1을 밟고 왔는지 판단이 되지 않는다.
    -> 그렇기 때문에, 아예 i - 1번째를 계산할 때는, i - 2번째를 밟지 않고 가는 방법을 쓸 것이다.
    -> 하지만, 그러면 i - 1은 dp 값을 쓰면 안되지 않나.. 기존의 값이 어떻게 된지 모르니까
    -> 그래서 i - 1은 dp의 값이 아닌 stair의 값을 더한다.
    -> 그러면 i - 3에서의 최대 값이랑 i - 1의 현재값을 더하는 셈으로, 문제가 해결된다.
    -> 즉 (i - 1) + (i - 3) or (i - 2)
    */
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(dp[1] + stair[3], stair[2] + stair[3]);
    for (int i = 4; i <= n; i++)
        dp[i] = max(stair[i - 1] + dp[i - 3], dp[i - 2]) + stair[i];
    cout << dp[n];
}