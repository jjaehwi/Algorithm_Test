// 소인수분해 B1
// 수학, 소수 판정
#include <iostream>

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

using namespace std;

int N;

int main()
{
    fastio;
    cin >> N;
    if (N == 1)
        return 0;
    for (int i = 2; i <= N; i++)
        while (N % i == 0)
        {
            cout << i << "\n";
            N /= i;
        }
}