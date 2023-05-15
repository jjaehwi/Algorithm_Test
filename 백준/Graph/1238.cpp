// 파티 G3
// 그래프 이론, 다익스트라

/*
그래프에서 단방향 도로들의 가중치가 양의 정수로만 이루어져 있으므로 다익스트라 알고리즘을 이용해서 접근.
다익스트라 알고리즘을 총 2번을 진행해주었는데,

첫 번째 다익스트라의 경우는 모든 학생들이 'X번 마을로 가는데 걸리는 최단 소요시간' 을 찾기위함,
두 번째 다익스트라의 경우는 'X번 마을에서 다시 자신들의 원래 마을로 가는데 걸리는 최단 소요시간' 을 찾기 위함.

도로가 '단방향' 이기 때문에, A번 마을에 X번 마을로 가는데 'T'만큼의 시간이 걸렸다고 하더라도,
X번 마을에서 A번 마을로 다시 돌아가는데 'T'만큼의 시간이 걸린다는 보장이 없다.
그래서 다익스트라를 총 2번 진행해 주었다.

결과를 저장하고 있는 배열이 있어야한다. result 배열
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321 // 실제 cost 계산 중 값보다는 무조건 더 큰 값으로 설정해주면 된다.
#define MAX_SIZE 1001
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
using namespace std;

int N, M, X, answer;

vector<pair<int, int>> v[MAX_SIZE];
int dist[MAX_SIZE];
int result[MAX_SIZE];

void Dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (pq.empty() == 0)
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int nCost = v[cur][i].second;

            if (dist[next] > cost + nCost)
            {
                dist[next] = cost + nCost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}

int main()
{
    fastio;
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            dist[j] = INF;

        Dijkstra(i);
        result[i] = dist[X];
    }

    for (int j = 1; j <= N; j++)
        dist[j] = INF;

    Dijkstra(X);

    for (int i = 1; i <= N; i++)
        result[i] = result[i] + dist[i];

    sort(result + 1, result + N + 1);

    answer = result[N];

    cout << answer;
}
