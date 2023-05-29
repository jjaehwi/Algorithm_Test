// 별 찍기 - 10 G5
// 재귀, 분할 정복
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int N;
void star(int i, int j, int N)
{
    if ((i / N) % 3 == 1 && (j / N) % 3 == 1)
    {
        cout << ' ';
    }
    else
    {
        if (N / 3 == 0)
            cout << "*";
        else
            star(i, j, N / 3);
    }
}
int main()
{
    fastio;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            star(i, j, N);
        }
        cout << "\n";
    }
}