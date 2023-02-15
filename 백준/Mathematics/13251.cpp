// 조약돌 꺼내기 S3
// 수학, 조합론, 확률론
#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

using namespace std;

int M, K;

int main()
{
    fastio;
    int sum = 0;
    cin >> M;
    // 1부터 시작할 것 이기 때문에 M+1을 해줌.. M일 때 <런타임 에러 (InvalidPointer)> 발생
    vector<int> v(M + 1);
    vector<double> p(M + 1);
    // 각 색깔 별 몇개 있는지
    for (int i = 1; i <= M; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    cin >> K;

    for (int i = 1; i <= M; i++)
    {
        if (v[i] < K)
            continue;
        double temp_prob = 1;
        // 핵심
        for (int j = 0; j < K; j++)
            temp_prob *= (v[i] - j) / (double)(sum - j);
        p[i] = temp_prob;
    }

    double total_prob = 0;
    for (int i = 1; i <= M; i++)
        total_prob += p[i];

    cout.precision(16);
    cout << total_prob;
}