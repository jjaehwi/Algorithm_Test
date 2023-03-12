// 상자넣기 S2
// dp , LIS
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(dp[i], ans);
            }
        }
    }
    cout << ans + 1;
}
