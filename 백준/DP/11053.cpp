// 가장 긴 증가하는 부분 수열 S2
// dp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1001
int N;
vector<int> v(MAX_SIZE);
// 자기 자신을 포함하는 길이이므로 1 로 채운다. (자기 자신 뿐이라면 길이는 1)
vector<int> dp(MAX_SIZE, 1);
int main()
{
    fastio;
    int result = 1;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            if (v[i] > v[j])
                dp[i] = max(dp[i], dp[j] + 1);

    for (int i = 0; i < N; i++)
        result = max(result, dp[i]);

    cout << result << "\n";
}