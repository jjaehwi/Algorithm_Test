// 숨바꼭질 3 G5
// 그래프 이론, bfs
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 100001
int N, K, res;
bool visited[MAX_SIZE];

void bfs()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, N});
    visited[N] = true;
    while (!q.empty())
    {
        int time = q.top().first;
        int x = q.top().second;
        // cout << "time: " << time << ", current x: " << x << "\n";
        q.pop();

        if (x == K)
            res = time;

        if (x * 2 < MAX_SIZE && !visited[x * 2])
        {
            q.push({time, x * 2});
            visited[x * 2] = true;
        }

        if (x + 1 < MAX_SIZE && !visited[x + 1])
        {
            q.push({time + 1, x + 1});
            visited[x + 1] = true;
        }

        if (x - 1 >= 0 && !visited[x - 1])
        {
            q.push({time + 1, x - 1});
            visited[x - 1] = true;
        }
    }
}

int main()
{
    fastio;
    cin >> N >> K;
    bfs();
    cout << res << "\n";
    return 0;
}
