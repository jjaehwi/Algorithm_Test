// 카드 합체 놀이 S1
// 그리디, 자료구조, 우선 순위 큐
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int n, m;
long long sum;
int main()
{
    fastio;
    cin >> n >> m;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    while (m--)
    {
        sort(v.begin(), v.end());
        long long newNum = v[0] + v[1];
        v[0] = newNum;
        v[1] = newNum;
    }
    for (int i = 0; i < n; i++)
        sum += v[i];
    cout << sum << "\n";
}
