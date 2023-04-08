// 중간값 찾기 D1
// 수학
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
vector<int> v;
int main()
{
    fastio;
    int N, position;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    position = N / 2;
    cout << v[position] << "\n";
}