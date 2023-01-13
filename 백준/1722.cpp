#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

using namespace std;

int N, P, k, num;
long long fac[21];
bool check[21];

int main()
{
    cin >> N >> P;
    vector<int> v(N);
    fac[0] = 1;
    // 팩토리얼을 담는 배열을 만듬
    for (int i = 1; i < 21; i++)
        fac[i] = i * fac[i - 1];

    // 1이면 k를 입력받아 k번째 수열 출력
    if (P == 1)
    {
        long long k;
        cin >> k;

        // i = 몇 번째 자리인지 vector 기준
        for (int i = 0; i < N; i++)
        {
            // j = 1~N 까지의 숫자 중 뭐가 적합한지 찾고 v에 푸시
            for (int j = 1; j <= N; j++)
            {
                if (check[j])
                {
                    continue;
                }
                if (k > fac[N - i - 1])
                {
                    k -= fac[N - i - 1];
                }
                // i번째 자리에 적합한 숫자인 j를 넣고 그 숫자는 사용 되었으니 check[j]도 true로 바꿔준다.
                else
                {
                    v[i] = j;
                    check[j] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < N; i++)
            cout << v[i] << " ";
    }
    // 2이면 수열을 입력받아 몇 번째 있는 수열인지 출력
    else
    {
        for (int i = 0; i < N; i++)
            cin >> v[i];

        long long result = 0;

        for (int i = 0; i < N; i++)
        {
            // i 위치의 숫자를 확인하고 몇번째인지 확인하기 위해, 적합한지 알아보는 숫자는 당연히 1부터 시작
            for (int j = 1; j < v[i]; j++)
            {
                // j 숫자가 이미 사용되었다면
                if (check[j])
                    continue;
                result += fac[N - 1 - i];
            }
            check[v[i]] = true;
        }
        cout << result + 1;
    }
}