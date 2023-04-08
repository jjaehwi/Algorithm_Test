// 홀수만 더하기 D1
// 수학, 구현
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 10
vector<int> v;
int main()
{
    fastio;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        v.clear();
        int sum = 0;
        for (int i = 0; i < MAX_SIZE; i++)
        {
            int num;
            cin >> num;
            if (num % 2 == 0)
                continue;
            else
                v.push_back(num);
        }
        for (int i = 0; i < v.size(); i++)
            sum += v[i];

        cout << "#" << t << " " << sum << "\n";
    }
}
