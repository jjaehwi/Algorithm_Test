// 알고리즘 수업 - 깊이 우선 탐색 1 S2
// dfs
#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> sequence;
int N, M, R, Seq;

void input();
void dfs(int n);
void sol();

int main()
{
    fastio;
    input();
    sol();
    return 0;
}

void input()
{
    cin >> N >> M >> R;
    graph.resize(N + 1);
    visited.resize(N + 1);
    sequence.resize(N + 1);
    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());
}

void dfs(int n)
{
    sequence[n] = ++Seq;
    visited[n] = 1;
    int graphsize = graph[n].size(), v;
    for (int i = 0; i < graphsize; i++)
    {
        v = graph[n][i];
        if (visited[v] == 0)
            dfs(v);
    }
}

void sol()
{
    dfs(R);
    for (int i = 1; i < N + 1; i++)
        printf("%d\n", sequence[i]);
}