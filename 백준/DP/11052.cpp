// 카드 구매하기 S1
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1001
vector<int> dp(MAX_SIZE);
int N;
int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> dp[i];
    for (int i = 2; i <= N; i++)
        for (int j = 1; j < i; j++)
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
    cout << dp[N];
}