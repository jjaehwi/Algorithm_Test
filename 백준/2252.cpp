#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
using namespace std;

vector<int> inDegree;            // outdegree는 인접리스트에서 바로 알 수 있는데 indegree에 대해서는 따로 정해줘야한다.
vector<vector<int>> adj(100001); // 인접리스트
vector<int> result;

void topologySort(int n)
{
    queue<int> q;

    // 위상정렬 시작
    // 큐에 in-degree가 0 인 정점
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i); // 넣을 때는 해당 정점의 인덱스를 넣어야한다.
    }

    // 완전한 전체 순회를 위해 n개 노드 반복
    for (int i = 1; i <= n; i++)
    {
        // n개까지 전체 방문하기 전 큐가 비었다면 사이클이 발생했다는 뜻
        if (q.empty())
        {
            return;
        }
        int front = q.front();
        q.pop();

        result.push_back(front);

        // 방문한 정점에서 나가는 간선(out-degree)에 대한 계산
        // 해당 간선들이 들어오는 정점, 즉 도착점에서는 들어오는 간선(in-degree)이 줄어드는 것이기 때문에
        // 간선 수만큼 in-degree를 줄여줘야 한다.
        for (int edge = 0; edge < adj[front].size(); edge++)
        {
            int nowEndV = adj[front][edge];
            inDegree[nowEndV]--; // 도착점의 indegree를 1빼준다.

            // 만약 indegree가 0이라면
            // 다음 위상정렬 계산을 위해 해당 정점을 큐에 삽입한다.
            if (inDegree[nowEndV] == 0)
                q.push(nowEndV);
        }
    }
}
int main()
{
    fastio;
    int n, m, A, B;
    cin >> n >> m;
    // fill 함수를 써도 됨
    for (int i = 1; i <= n; i++)
        inDegree.push_back(0);
    // 2->5
    // adj[2].push_back(5);
    // inDegree[5]++;
    for (int i = 0; i < m; i++)
    {
        cin >> A >> B;
        adj[A].push_back(B);
        inDegree[B]++;
    }
    topologySort(n);

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
}