// 큰 수의 법칙
// 그리디

#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
using namespace std;
// N 개의 숫자 입력을 받고, M 번 더하고, 최대 K번 중복으로 더할 수 있음
int N, M, K;

int main()
{
    fastio;
    cin >> N >> M >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), greater<>()); // 내림차순 정렬
    int first = v[0];
    int second = v[1];

    // 가장 큰 수가 더해지는 횟수 계산
    int cnt = (M / (K + 1)) * K;
    cnt += M % (K + 1);

    int result = 0;
    result += cnt * first;
    result += (M - cnt) * second;

    cout << result;
}
