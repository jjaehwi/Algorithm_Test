// 케빈 베이컨의 6단계 법칙 S1
// 플로이드워셜
#include <iostream>

using namespace std;

const int MAX = 101;

int n, m;
int net[MAX][MAX];

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        net[a][b] = 1;
        net[b][a] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && net[i][j] != 1)
            {
                net[i][j] = 10000000;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (net[j][i] + net[i][k] < net[j][k])
                {
                    net[j][k] = net[j][i] + net[i][k];
                }
            }
        }
    }

    int val = 10000000;
    int res;
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= n; j++)
        {
            tmp += net[i][j];
        }
        if (tmp < val)
        {
            val = tmp;
            res = i;
        }
    }

    cout << res;

    return 0;
}