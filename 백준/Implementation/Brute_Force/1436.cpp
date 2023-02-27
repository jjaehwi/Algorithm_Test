// 영화감독 숌 S5
// 브루트 포스
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int main()
{
    fastio;
    int n;
    cin >> n;
    int ans = 0;
    int cnt = 0;
    while (cnt != n)
    {
        // 1부터 탐색
        ans++;
        int temp = ans;
        // / 10 으로 계속 줄일 것이기 때문에..
        while (temp != 0)
        {
            // 종말의 숫자 라면 count 증가
            if (temp % 1000 == 666)
            {
                cnt++;
                break;
            }
            // 일의 자리 제거
            else
                temp /= 10;
        }
    }
    cout << ans;
}