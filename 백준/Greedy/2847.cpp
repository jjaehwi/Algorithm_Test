// 게임을 만든 동준이 S4
// 그리디
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int n, cnt;
int main()
{
    fastio;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = n - 1; i > 0; i--)
        while (v[i] <= v[i - 1])
        {
            v[i - 1]--;
            cnt++;
        }

    // for (int i = 0; i < n; i++)
    //     cout << v[i] << " ";
    cout << cnt << "\n";
}