// 주식 S2
// 그리디
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int t;
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int maxVal = -1;
        long long result = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            maxVal = max(maxVal, v[i]);
            result += maxVal - v[i];
        }
        cout << result << "\n";
    }
}