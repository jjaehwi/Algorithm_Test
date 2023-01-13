#include <iostream>

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

using namespace std;

int comb[31][31];

int T, N, M;

int main()
{
    cin >> T;

    for (int i = 0; i <= 30; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 || j == 0)
                comb[i][j] = 1;
            else
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]);
        }
    }

    for (int t = 0; t < T; t++)
    {
        cin >> N >> M;
        cout << comb[M][N] << "\n";
    }
}