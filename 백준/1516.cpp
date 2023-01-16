#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
#define MAX 501
using namespace std;

int N;
vector<int> edge[MAX]; // 간선 저장(먼저 지어져야 하는 건물)
int inDegree[MAX];
int cost[MAX]; // 비용 저장
int dp[MAX];   // 각 건물까지 드는 비용 저장

void topologySort()
{
    queue<int> q;
    // 위상정렬 시작
    // 큐에 in-degree가 0 인 정점
    for (int i = 1; i <= N; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i); // 넣을 때는 해당 정점의 인덱스를 넣어야한다.
            dp[i] = cost[i];
        }
    }
    // n개까지 전체 방문하기 전 큐가 비었다면 사이클이 발생했다는 뜻
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        // 방문한 정점에서 나가는 간선(out-degree)에 대한 계산
        // 해당 간선들이 들어오는 정점, 즉 도착점에서는 들어오는 간선(in-degree)이 줄어드는 것이기 때문에
        // 간선 수만큼 in-degree를 줄여줘야 한다.
        for (int j = 0; j < edge[front].size(); j++)
        {
            int nowEndV = edge[front][j];
            inDegree[nowEndV]--; // 도착점의 indegree를 1빼준다.
            // 만약 indegree가 0이라면
            // 다음 위상정렬 계산을 위해 해당 정점을 큐에 삽입한다.
            if (inDegree[nowEndV] == 0)
                q.push(nowEndV);
            dp[nowEndV] = max(dp[nowEndV], cost[nowEndV] + dp[front]);
        }
    }
    for (int i = 1; i <= N; i++)
        cout << dp[i] << "\n";
}

int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
        int input;
        cin >> input;
        while (input != -1)
        {
            inDegree[i]++;            // -1이 아닌 뭔가 입력이 있으면 걔는 inDegree가 존재하는 것..
            edge[input].push_back(i); // inDegree가 존재하니까, input index 위치에는 i로 향하는 간선이 있음을 알 수 있다.
            cin >> input;             // input을 계속 입력받는다.
        }
    }
    topologySort();
}