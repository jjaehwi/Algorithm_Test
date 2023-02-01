// 피보나치 수 3
// 수학, 피사노 주기 (백준 9471번)
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
long long n, cnt;
vector<long long> v;
int main()
{
    fastio;
    cin >> n;
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    int cnt = 2;
    while (1)
    {
        v.push_back((v[cnt] + v[cnt - 1]) % 1000000);
        cnt++;
        // 주기를 구한 경우
        if (v[cnt] == 0 && v[cnt - 1] == 1)
            break;
    }
    cout << v[n % cnt];
}