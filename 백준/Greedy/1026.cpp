// 보물 S4
// 그리디
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int n, sum;
vector<int> a, b;
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        a.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        b.push_back(num);
    }
    sort(a.begin(), a.end());              // 오름차순
    sort(b.begin(), b.end(), greater<>()); // 내림차순
    for (int i = 0; i < n; i++)
        sum += a[i] * b[i];
    cout << sum;
}