// ATM S4
// 그리디, 정렬
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int main()
{
    fastio;
    vector<int> v;
    int n, sum = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int sec;
        cin >> sec;
        v.push_back(sec);
    }
    sort(v.begin(), v.end());
    // for (int i = 0; i < n; i++)
    //     cout << v[i] << " ";
    for (int i = 0; i < n; i++)
    {
        sum = sum + v[i];
        ans += sum;
    }
    cout << ans;
}