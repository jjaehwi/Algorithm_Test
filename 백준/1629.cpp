// 곱셈 S1
// 재귀, 분할 정복을 이용한 거듭제곱
// a^b mod m을 계산
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
long long POW(long long a, long long b, long long m)
{
    if (b == 1)
        return a % m;

    long long val = POW(a, b / 2, m);

    val = val * val % m;

    // b 가 짝수 였다면 그대로 반환
    if (b % 2 == 0)
        return val;
    // b 가 홀수 였다면 한번 더 곱해서 반환해야함 (ex) 7/2 = 3
    else
        return val * a % m;
}
int main()
{
    fastio;
    long long a, b, c;
    cin >> a >> b >> c;
    cout << POW(a, b, c);
}