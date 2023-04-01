// 초콜릿 식사 S2
// 수학, 그리디
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int K;
int main()
{
    fastio;
    int choco = 1;
    int n = 0;
    cin >> K;
    while (K > choco)
        choco *= 2;
    cout << choco << " ";
    while (1)
    {
        if (K % choco == 0)
        {
            cout << n;
            break;
        }
        else
        {
            choco /= 2;
            n += 1;
        }
    }
    return 0;
}