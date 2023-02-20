// 피보나치 함수 S3
// dp
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int t;
vector<int> dp(40);
int main()
{
    fastio;
    cin >> t;
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= 40; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    while (t--)
    {
        int num;
        cin >> num;
        if (num == 0)
            cout << "1 0\n";
        else if (num == 1)
            cout << "0 1\n";
        else
            cout << dp[num - 1] << " " << dp[num] << "\n";
    }
    return 0;
}

// 0 1 1 2 3 5 8