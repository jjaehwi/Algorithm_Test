// 동전 0 S4
// 그리디
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int n, k;
vector<int> v;
int main()
{
    fastio;
    int cnt = 0;
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
    {
        if (k == 0)
            break;
        cnt += k / v[n - i - 1];
        k %= v[n - i - 1];
        // cout << "count: " << cnt << ", k : " << k << "\n";
    }
    /*
    for (int i = n - 1; i >= 0; i--)
    {
        if (k == 0)
            break;
        cnt += k / v[i];
        k %= v[i];
        // cout << "count: " << cnt << ", k : " << k << "\n";
    }
    */
    cout << cnt;
}