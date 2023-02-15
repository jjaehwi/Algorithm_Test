/*
LtoR 배열은 [i]번째 자리에 a[0] ~ a[i]까지의 최대공약수가 들어가고,
RtoL 배열은 [i]번째 자리에 a[i] ~ a[n-1]까지의 최대공약수가 들어간다.

ⓐ a[0]을 제외했을 때 RtoL[0+1] 값이 최대 공약수이고,

ⓑ a[n-1]을 제외했을 때 LtoR[(n-1)-1]의 값이 최대공약수가 된다.

ⓒ [0]과 [n-1]사이의 i번째인 a[i]를 제외했을 때의 최대공약수는
   LtoR[i-1]과 RtoL[i+1]의 최대공약수가 된다.
   ex) a[2]인 24를 제외했을 때 최대공약수는 LtoR[2-1]과 RtoL[2+1] (4와 12)의 최대공약수인 4가 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

int N;

using namespace std;

int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}

int main()
{
    fastio;
    cin >> N;
    vector<int> a(N), LtoR(N), RtoL(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a.begin(), a.end()); // 오름차순 정렬
    LtoR[0] = a[0];
    RtoL[N - 1] = a[N - 1];

    // LtoR 채우기
    for (int i = 1; i < N; i++)
        LtoR[i] = gcd(a[i], LtoR[i - 1]);
    // RtoL 채우기
    for (int i = N - 2; i >= 0; i--)
        RtoL[i] = gcd(a[i], RtoL[i + 1]);

    // 제거한 후 최대공약수, 제거되는 숫자 선언
    int maxGcd = 0, exceptNum = 0;

    // 제거한 후 최대공약수 계산하기
    for (int i = 0; i < N; i++)
    {
        // a[0]이 제거되는 경우
        if (i == 0)
        {
            maxGcd = RtoL[1];
            exceptNum = a[i];
        }
        // a[N-1]이 제거되는 경우

        // exceptNum = a[N - 1];
        // maxGcd = LtoR[N - 1 - 1];
        // 가 안되는 이유..
        else if (i == N - 1)
        {
            if (maxGcd < LtoR[N - 2])
            {
                exceptNum = a[N - 1];
                maxGcd = LtoR[N - 1 - 1];
            }
        }
        else
        {
            if (maxGcd < gcd(LtoR[i - 1], RtoL[i + 1]))
            {
                maxGcd = gcd(LtoR[i - 1], RtoL[i + 1]);
                exceptNum = a[i];
            }
        }
    }
    // 정답을 구할 수 없는 경우
    if (exceptNum % maxGcd == 0)
        cout << "-1";
    else
        cout << maxGcd << " " << exceptNum;
}