// 정확한 순위
// 그래프 이론, 플로이드-워셜

// 자기 자신을 제외하고 모든 정점과 연결 되어 있으면 정확한 순서를 알 수 있다.
// 모든 정점에 대한 것이므로 플로이드-워셜 알고리즘을 사용한다.

#include <iostream>
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
#define INF 987654321
#define MAX_SIZE 501
using namespace std;
int n, m, a, b;
int dist[MAX_SIZE][MAX_SIZE];

int main()
{
    fastio;
    cin >> n >> m;
    // 초기화
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = i == j ? 0 : INF;
    // a 와 b 사이의 순위는 알 수 있게 된 것.
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        dist[a][b] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                // 경로를 거쳐서 와도 순위는 알 수 있는 것
                if (dist[i][k] == 1 && dist[k][j] == 1)
                    dist[i][j] = 1;
            }
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = 1; j <= n; j++)
        {
            // 본인 제외
            if (i == j)
                continue;
            if (dist[i][j] == INF && dist[j][i] == INF)
                count++;
        }
        // count 가 올라가면 연결 되지 않은 점이 존재하는 것
        // count 가 그대로 0 이라면 모두 연결되어 있는 것이므로 순위를 알 수 있고 결과값을 +1
        if (count == 0)
            result++;
    }
    cout << result;
}
