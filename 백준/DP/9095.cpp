// 1, 2, 3 더하기 S3
// dp
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int t;
vector<int> dp(12);
int main()
{
    fastio;
    cin >> t;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    while (t--)
    {
        int num;
        cin >> num;
        for (int i = 4; i <= num; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        cout << dp[num] << "\n";
    }
}

// 1 --> 1
// 2 --> 1+1, 2 --> 2
// 3 --> 1+1+1, 1+2, 2+1, 3 --> 4
// 4 --> 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 1+3, 3+1, 2+2 7
// 5 --> 1+1+1+1+1, 1+1+1+2 * 4 , 1+2+2 * 3, 1+1+3 * 3, 2+3 * 2, 13