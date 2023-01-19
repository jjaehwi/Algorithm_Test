// 구간합 구하기 4 dp
#include <iostream>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

int M, N;
vector<int> v;
vector<long long> s;

void dp(int start, int end)
{
    for (int i = 2; i <= end; i++)
        s[i] = s[i - 1] + v[i];
}

int main()
{
    fastio;
    cin >> M >> N;
    v.resize(M + 1);
    s.resize(M + 1);
    for (int i = 1; i <= M; i++)
        cin >> v[i];
    s[1] = v[1];
    dp(1, M);
    for (int i = 0; i < N; i++)
    {
        int I, J;
        cin >> I >> J;
        cout << s[J] - s[I - 1] << "\n";
    }
}