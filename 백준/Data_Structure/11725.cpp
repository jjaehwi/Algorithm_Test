// 트리의 부모 찾기 S2
// 트리, 그래프 탐색, dfs, bfs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 100001
int N;
vector<int> graph[MAX_SIZE];
bool visited[MAX_SIZE];
int ans[MAX_SIZE];

void bfs()
{
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int i = 0; i < graph[parent].size(); i++)
        {
            int child = graph[parent][i];
            if (!visited[child])
            {
                ans[child] = parent;
                visited[child] = true;
                q.push(child);
            }
        }
    }
}

int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs();

    for (int i = 2; i <= N; i++)
        cout << ans[i] << "\n";
}