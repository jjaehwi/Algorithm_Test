// 피보나치 수 B2
// 수학, 구현
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int n;
vector<int> v;
int main()
{
    fastio;
    cin >> n;
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);

    for (int i = 2; i < n; i++)
        v.push_back((v[i] + v[i - 1]));
    cout << v[n];
}

/* 메모리 초과
v[0] = 0;
v[1] = 1;
v[2] = 1;
    for (int i = 2; i <= n; i++)
        v[i] = v[i - 2] + v[i - 1];
*/

/* 메모리 초과
v.push_back(0);
v.push_back(1);
    for (int i = 2; i <= n; i++)
        v[i] = v[i - 2] + v[i - 1];
*/