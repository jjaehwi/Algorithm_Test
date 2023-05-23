// 연결 요소의 개수 S2
// 그래프 탐색, bfs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1001

int N, M, cnt;
vector<int> vertex[MAX_SIZE];
bool visited[MAX_SIZE];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < vertex[cur].size(); i++)
        {
            if (!visited[vertex[cur][i]])
            {
                visited[vertex[cur][i]] = true;
                q.push(vertex[cur][i]);
            }
        }
    }
}

int main()
{
    fastio;
    int u, v;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        vertex[u].push_back(v);
        vertex[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        if (!visited[i])
        {
            bfs(i);
            cnt++;
        }

    cout << cnt;
}