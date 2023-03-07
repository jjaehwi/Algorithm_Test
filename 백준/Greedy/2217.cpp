// 로프 S4
// 그리디, 수학, 정렬
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int n;
int main()
{
    fastio;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int maxVal = v[0] * n;
    while (n > 0)
    {
        n--;
        v.erase(v.begin());
        int temp = v[0] * n;
        maxVal = max(maxVal, temp);
        // cout << "temp: " << temp << ", maxVAl: " << maxVal << "\n";
    }
    cout << maxVal;
}