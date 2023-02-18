// 설탕 배달 S4
// dp, 그리디
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int main()
{
    fastio;
    int n, count = 0;
    cin >> n;

    while (n >= 0)
    {
        if (n % 5 == 0)
        {
            count += (n / 5);
            cout << count;
            return 0;
        }
        n -= 3;
        count++;
    }
    cout << -1;
}