// 백만 장자 프로젝트 D2
// 그리디
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
vector<long long> v;
int T, N;
int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        long long answer = 0;
        v.clear();
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int num;
            cin >> num;
            v.push_back(num);
        }
        int maxMoney = v[N - 1];
        for (int i = N - 1; i >= 0; i--)
        {
            if (maxMoney >= v[i])
                answer += maxMoney - v[i];
            else
                maxMoney = v[i];
        }
        cout << "#" << t << " " << answer << "\n";
    }
}