// 부분수열의 합 S2
// 백트래킹, 브루트포스
#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int n, s;
int arr[30];
int cnt = 0;
void func(int cur, int tot)
{
    if (cur == n)
    {
        if (tot == s)
            cnt++;
        return;
    }
    func(cur + 1, tot);
    func(cur + 1, tot + arr[cur]);
}
int main(void)
{
    fastio;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    func(0, 0);
    if (s == 0)
        cnt--;
    cout << cnt;
}