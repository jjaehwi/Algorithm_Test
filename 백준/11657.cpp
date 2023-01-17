#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
#define MAX_SIZE 501
const int INF = 1e9;

struct edge
{
    int end;
    int cost;
};

// vector<edge> adj[MAX_SIZE];
vector<edge> adj[MAX_SIZE];
long long dist[MAX_SIZE];

// 음의 사이클이 존재하면 false 반환
bool belman(int n)
{
    // 첫 시작점의 최단거리 값을 0으로 만든다.
    dist[1] = 0;

    // 3. N-1번 루프하면서 전체에 대한 최단거리를 찾는다. (핵심)
    for (int i = 0; i < n - 1; i++)
    {
        // 2. 현재 정점의 인덱스를 now로 하여, 정점 전체를 순회한다. (핵심) 전체 정점에 대해서 1~n 까지
        // 숫자의 시작을 1로 하고 있음. 주의할 것
        for (int now = 1; now <= n; now++)
        {
            // 1. 현재 인덱스의 인접리스트에 대해 순회 시작
            int len = adj[now].size();
            for (int adjIdx = 0; adjIdx < len; adjIdx++)
            {
                int nextNode = adj[now][adjIdx].end;
                int nextCost = adj[now][adjIdx].cost;

                // 현재 값이 INF가 아니면서(최소 한번 최단거리 갱신된 적이 있음)
                // 최단거리가 갱신되는 경우(현재 최단거리 + cost가 기존 최단거리보다 작음)
                if (dist[now] != INF && dist[nextNode] > dist[now] + nextCost)
                {
                    dist[nextNode] = dist[now] + nextCost;
                    // N 번째 루프에서 최단거리가 갱신되었음 음의 사이클이 존재한다는 것
                    // if(i==n-1){
                    //    return false;
                    // }
                }
            }
        }
    }

    // 4. n-1 루프가 끝나면, 마지막으로 한번 더 순회하여 음수 사이클을 찾는다.
    for (int now = 1; now <= n; now++)
    {
        // 1. 현재 인덱스의 인접리스트에 대해 순회 시작
        int len = adj[now].size();
        for (int adjIdx = 0; adjIdx < len; adjIdx++)
        {
            int nextNode = adj[now][adjIdx].end;
            int nextCost = adj[now][adjIdx].cost;

            // N번째 루프에서 최단거리가 갱신되었음! 음의 사이클 존재
            if (dist[now] != INF && dist[nextNode] > dist[now] + nextCost)
                return false;
        }
    }
    return true;
}

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // fill(dist, dist + n, INF);
    // dist 전체를 INF로 채운다. 이거 왜 안되지..
    for (int i = 1; i <= n; i++)
        dist[i] = INF; // 모든 노드를 INF로 세팅

    bool result = belman(n);
    if (result)
        for (int i = 2; i <= n; i++)
            dist[i] != INF ? cout << dist[i] << "\n" : cout << "-1\n";
    else
        cout << "-1\n";
}