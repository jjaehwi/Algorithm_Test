// 바이러스 S3
// 그래프 탐색, bfs, dfs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 101
int N, M, cnt; // 노드 수, 간선 수, 감염되는 수
vector<vector<int>> adj;
bool visited[MAX_SIZE];

void bfs(int startNode)
{
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);
    while (!q.empty())
    {
        int nowNode = q.front();
        q.pop();
        for (int i = 0; i < adj[nowNode].size(); i++)
        {
            int nextNode = adj[nowNode][i];
            if (!visited[nextNode])
            {
                cnt++;
                visited[nextNode] = true;
                q.push(nextNode);
            }
        }
    }
}

int main()
{
    fastio;
    int virus = 0;
    cin >> N >> M;
    adj.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    // visited를 세는 풀이
    for (int i = 1; i <= MAX_SIZE; i++)
    {
        if (visited[i])
            virus++;
    }
    cout << virus - 1; // 1 제외

    // 탐색 할 때 마다 cnt 를 증가시켜서 찾는 풀이
    // cout<<cnt;
}

/*
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<int> a[101];
bool check[101];
int cnt = 0;

void dfs(int x)
{
    check[x] = true;
    for (int i = 0; i < a[x].size(); i++)
    {
        int y = a[x][i];
        if (!check[y])
        {
            dfs(y);
            cnt++;
        }
    }
}

int main()
{
    int n, m; // n : 노드 개수, m : 엣지 개수
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    } // edge 연결
    dfs(1);
    cout << cnt << "\n";
}
*/