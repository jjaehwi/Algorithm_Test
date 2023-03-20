// 로또 S2
// 백트래킹, 조합, 재귀, 수학
#include <iostream>
#include <memory.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 14

int k;
int lotto[MAX_SIZE];
int res[MAX_SIZE];
bool check[MAX_SIZE];

void func(int startNum, int cur)
{
    if (cur == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << res[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = startNum; i < k; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            res[cur] = lotto[i];
            // i, cur+1 도 되고, i+1, cur+1 도 된다. (어차피 중복으로 주어지지 않기 때문)
            func(i + 1, cur + 1);
            check[i] = false;
        }
    }
}

int main()
{
    fastio;
    while (1)
    {
        cin >> k;
        if (k == 0 || k <= 6 || k >= 13)
            break;
        for (int i = 0; i < k; i++)
            cin >> lotto[i];
        func(0, 0);
        cout << "\n";
        memset(lotto, 0, MAX_SIZE);
        // memset(res, 0, MAX_SIZE);
        // memset(check, false, MAX_SIZE);
    }
}