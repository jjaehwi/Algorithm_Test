// 돌 게임 S5
// dp

/* 홀수개이면 상근이 승, 짝수개이면 창용이 승
#include <iostream>
using namespace std;

int main()
{
    int N; // 돌의 개수
    cin >> N;

    if (N % 2 == 1)
    {
        cout << "SK";
    }

    else
    {
        cout << "CY";
    }

    return 0;
}
*/

// dp 를 이용한 풀이
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;        // 돌의 개수
    int DP[1000]; // 게임과정의 횟수

    cin >> N;

    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;

    for (int i = 3; i <= N; i++)
    {
        DP[i] = min(DP[i - 1] + 1, DP[i - 3] + 1);
    }

    // 게임 과정 횟수의 홀짝에 따라 승패 결정
    if (DP[N] % 2 == 1)
    {
        cout << "SK";
    }
    else
    {
        cout << "CY";
    }

    return 0;
}