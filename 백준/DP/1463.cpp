// 1로 만들기
// DP, bottom up 방식
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int N;
vector<int> v;
int main()
{
    fastio;
    cin >> N;
    v.resize(N + 1);
    v[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        v[i] = v[i - 1] + 1;
        if (i % 3 == 0)
            v[i] = min(v[i], v[i / 3] + 1);
        if (i % 2 == 0)
            v[i] = min(v[i], v[i / 2] + 1);
    }
    cout << v[N];
}
