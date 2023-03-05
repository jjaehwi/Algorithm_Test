// 타일 채우기 G4
// dp
#include <iostream>
using namespace std;

int main()
{

    int N;
    int dp[31];
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    cin >> N;

    if (N % 2 == 0)
        for (int i = 4; i <= N; i += 2)
        {
            dp[i] = dp[i - 2] * 3;

            for (int j = 4; i - j >= 0; j += 2)
                dp[i] += dp[i - j] * 2;
        }

    cout << dp[N] << endl;

    return 0;
}

/*
홀수 개 일때는 타일을 만들 수 가 없다.

다음으로 2개씩 타일이 늘어날 때마다 이전 타일에서 규칙적으로 늘어나는 타일이 있다.

길이가 2씩 늘어날때마다 2가지 경우가 계속 추가되는 것을 반영해야한다.
*/