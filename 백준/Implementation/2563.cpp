// 색종이 S5
// 구현
// 색종이
// 구현
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 101
int a[MAX_SIZE][MAX_SIZE];
int n, x, y, cnt;
int main()
{
    fastio;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        for (int i = y; i < y + 10; i++)
        {
            for (int j = x; j < x + 10; j++)
            {
                if (!a[i][j])
                {
                    cnt++;
                    a[i][j] = 1;
                }
            }
        }
    }
    cout << cnt;
}
