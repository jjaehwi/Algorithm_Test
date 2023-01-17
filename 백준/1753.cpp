#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321 // 실제 cost 계산 중 값보다는 무조건 더 큰 값으로 설정해주면 된다.
// long long INF2 = 1e18 --> long 형에서 나올 수 있는 매우 큰 값
#define MAX_SIZE 20001
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
using namespace std;

int V, E, K;

struct edge
{
    int end; // dest로 표현하기도 함
    int cost;

    // 최소 힙
    bool operator<(const edge &b) const
    {
        return cost > b.cost;
    }
};

// cost가 포함된 인접 리스트(pair를 써도됨)
// pair를 쓰면 위처럼 연산자 오버로딩이 필요없다.
vector<vector<edge>> adj;
int dist[MAX_SIZE];

void dijk(int V, int startNode)
{
    // priorty_queue<pair<int,int>, vector<pari<int,int>>, greater<pair<int,int>>
    priority_queue<edge> pq;

    // 초기화
    // 우선 모든 정점의 최단거리를 무한대로 숫자를 정해둔다.
    for (int i = 0; i <= V; i++)
        dist[i] = INF;

    // 시작점을 큐에 넣고, dist를 0으로 설정한다.
    pq.push({startNode, 0});
    dist[startNode] = 0;

    // 우선순위 큐에서 값을 꺼내온다.
    while (!pq.empty())
    {
        edge top = pq.top();
        pq.pop();

        int nowVertex = top.end; // 현재의 정점
        int nowCost = top.cost;

        // 안써도 무관한데,, 시간 좀 줄어듬
        if (dist[nowVertex] < nowCost)
            continue;

        // 해당 정점에서 나가는 간선들을 순회하여, 다음 갈 수 있는 정점들에 대해 가중치(최단거리)를 계산한다.
        int len = adj[nowVertex].size();
        for (int i = 0; i < len; i++)
        {
            edge next = adj[nowVertex][i];

            // 다음에 갈 점의 최단거리보다, 지금 점 + 다음 점으로의 가중치가 더 작다면
            // 최단거리를 갱신하고, 큐에 해당 지점을 넣는다.
            if (dist[next.end] > dist[nowVertex] + next.cost)
            {
                dist[next.end] = dist[nowVertex] + next.cost;
                pq.push({next.end, dist[next.end]}); // 다음에 갈 지점을 큐에 넣어야한다! 최단거리는 방금 계산한 그 값으로 넣어야한다. (현재의 최단거리)
                // 갱신이 되는 것들에 대해서만 큐에 넣어서 확인한다.
            }
        }
    }
}

int main()
{
    fastio;
    cin >> V >> E >> K;
    adj.resize(V + 1);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijk(V, K);

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
            cout << "INF"
                 << "\n";
        else
            cout << dist[i] << "\n";
    }
}