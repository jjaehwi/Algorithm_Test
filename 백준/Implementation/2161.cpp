// 카드1 S5
// 구현, 큐
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int N;
queue<int> q;
vector<int> res;
int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++)
        q.push(i);

    for (int i = 1; i <= N; i++)
    {
        res.push_back(q.front());
        q.pop();
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < N; i++)
        cout << res[i] << " ";
}