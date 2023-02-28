// 시험 감독 B2
// 수학, 사칙연산
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> V(N);

    for (int i = 0; i < N; i++)
        cin >> V[i];

    int B, C;
    cin >> B >> C;

    long long sum = 0;

    for (int i = 0; i < N; i++)
    {
        if (V[i] <= B)
            sum++;
        else
        {
            sum += (V[i] - B) / C + 1;
            if ((V[i] - B) % C != 0)
                sum++;
        }
    }
    cout << sum;
    return 0;
}