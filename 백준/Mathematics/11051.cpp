// 이항 계수 2 S2
// 수학, dp, 조합론
#include <iostream>

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

using namespace std;

int comb[1001][1001];

int N, K;

int main()
{

    cin >> N >> K;

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 || j == 0)
                comb[i][j] = 1;
            else
                comb[i][j] = (comb[i - 1][j - 1] % 10007 + comb[i - 1][j] % 10007) % 10007;
            // (a + b) % p = ((a % p) + (b % p)) % p인걸 사용해서 모듈러 처리를 계산할때마다 계속해줘야한다.
            // 아주 큰 숫자가 들어가면 오버플로우가 날 수 있기 때문에.
        }
    }

    cout << comb[N][K];
}