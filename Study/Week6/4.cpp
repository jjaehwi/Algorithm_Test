// 숨바꼭질
// 그래프 이론, 너비 우선 탐색, 다익스트라

#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 20001
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
using namespace std;
int n, m, a, b;
vector<int> adj[MAX_SIZE];
int visited[MAX_SIZE];
int maxNum, maxDist, maxCnt;

void bfs()
{
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int i = 0; i < adj[current].size(); i++)
        {
            int next = adj[current][i];
            if (!visited[next])
            {
                visited[next] = visited[current] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        // 인접 연결
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs();
    // for (int i = 1; i <= n; i++)
    //     cout << visited[i] << " ";

    for (int i = 2; i <= n; i++)
    {
        if (visited[i] > maxDist)
        {
            maxDist = visited[i];
            maxNum = i;
            maxCnt = 1;
        }
        else if (visited[i] == maxDist)
            maxCnt++;
    }
    cout << maxNum << " " << maxDist - 1 << " " << maxCnt;
}