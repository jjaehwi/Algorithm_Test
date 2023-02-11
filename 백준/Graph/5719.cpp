// 거의 최단 경로 P5
// 그래프 이론, 다익스트라, bfs

// 다익스트라
// 핵심 : 거의 최단 경로 - 최단 경로에 포함되지 않는 도로로만 이루어진 경로 중 가장 짧은 것
// 장소는 몇 개 안되는데 도로의 수가 많고, P의 숫자가 크다. P는 음수가 들어가지 않는다 --> 다익스트라일 것이다.
// 최단경로를 찾고 그 최단 경로에 포함되는 경로를 제외하고 다시 최단경로를 돌려야한다. --> 다익스트라를 두 번 돌려야한다.
// 최단경로를 어떻게 제외해야할 것인가... --> 최단경로인 도로를 삭제하는 알고리즘이 필요 --> bfs 간선에 접근하지 못하도록 값을 바꿔버린다
// 함정
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_SIZE 2001
#define INF 987654321
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

const long long DELETED = -1; // 매직넘버 사용 권장
int N, M, S, D;
int U, V, P;
struct edge
{
    int end;
    long long cost;
    // 최소 힙
    bool operator<(const edge &b) const
    {
        return cost > b.cost;
    }
};
vector<vector<edge>> adj;
vector<vector<int>> path;
long long dist[MAX_SIZE];

int dijk()
{
    priority_queue<edge> pq;
    int resultCost = 0;

    for (int i = 0; i <= N; i++)
        dist[i] = INF;

    pq.push({S, 0});
    dist[S] = 0;

    // 우선순위 큐에서 값을 꺼내온다.
    while (!pq.empty())
    {
        edge top = pq.top();
        pq.pop();

        int nowNode = top.end; // 현재의 정점
        long long nowCost = top.cost;

        if (dist[nowNode] < nowCost)
            continue;

        int len = adj[nowNode].size();
        for (int i = 0; i < len; i++)
        {
            int nextNode = adj[nowNode][i].end;
            long long nextCost = adj[nowNode][i].cost;

            // 다음 가려는 정점이 삭제된 정점이라면 패스
            if (nextCost == DELETED)
                continue;

            if (dist[nextNode] != DELETED && dist[nextNode] > dist[nowNode] + nextCost)
            {
                dist[nextNode] = dist[nowNode] + nextCost;

                // 최단거리 갱신되었으므로 기존 최단거리 루트 삭제
                // 그리고 최단거리 작성
                // 역으로 타고 올라올 수 있게 now와 next를 거꾸로 작성합니다.
                path[nextNode].clear();
                path[nextNode].push_back(nowNode);

                resultCost += dist[nextNode];
                pq.push({nextNode, dist[nextNode]});
            }
            // 동일한 최단거리 값을 가지므로, path에 같이 추가한다.
            // 최단거리는 이미 갱신되었으므로 clear는 하지 않음
            if (dist[nextNode] != DELETED && dist[nextNode] == dist[nowNode] + nextCost)
                path[nextNode].push_back(nowNode);
        }
    }
    return resultCost;
}

// 끝 점부터 시작점으로 가도록 순회한다.
// 역방향으로 넣어서 bfs를 순회해야한다.
// 처음부터 시작하면 전체 최단거리가 아니고 중간에 최단거리로 가다가 말아도 포함되어버리기 때문이다.
// bfs를 통해 간선 삭제
void BFS()
{
    queue<int> q;
    q.push(D);
    bool visited[MAX_SIZE] = {
        false,
    };
    visited[D] = true;

    while (!q.empty())
    {
        int nowNode = q.front();
        q.pop();

        int pathLen = path[nowNode].size();
        for (int i = 0; i < pathLen; i++)
        {
            int start = path[nowNode][i];

            // 주의, 이 녀석은 역방향으로 들어온다.
            // 그러니까 지금 점에서 나가는 간선이, 실제로 인접리스트에서는 들어오는 간선인것
            // 그러므로 adj에서는 순방향에 맞게 변수 위치를 거꾸로 써야한다.
            int adjLen = adj[start].size();
            for (int j = 0; j < adjLen; j++)
            {
                if (adj[start][j].end == nowNode)
                {
                    adj[start][j].cost = DELETED;

                    if (!visited[start])
                    {
                        visited[start] = true;
                        q.push(start);
                    }
                }
            }
        }
    }
}

int main()
{
    fastio;
    while (1)
    {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;
        adj.resize(N + 1);
        path.resize(N + 1);

        // 사용값 삭제
        for (int i = 0; i <= N; i++)
        {
            adj[i].clear();
            path[i].clear();
        }

        cin >> S >> D;

        for (int i = 0; i < M; i++)
        {
            cin >> U >> V >> P;
            adj[U].push_back({V, P});
        }

        // 1. 최단 경로 찾기
        dijk();
        // 2. 최단 경로 간선 제거
        BFS();
        // 3. 다시 최단 경로 찾기
        int result = dijk();
        if (dist[D] == INF)
            cout << "-1\n";
        else
            cout << dist[D] << "\n";
    }
}