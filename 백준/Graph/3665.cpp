// 최종 순위 G1
// 그래프 이론, 위상 정렬

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
#define MAX_SIZE 501

int t, n, m, a, b;
int ranking[MAX_SIZE];        // 순위를 저장하는 배열
int indegree[MAX_SIZE];       // 진입 차수를 저장하는 배열
bool adj[MAX_SIZE][MAX_SIZE]; // 상대적 등수를 나타내는 배열

int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n;
        // 현재 순위 저장
        for (int i = 1; i <= n; i++)
            cin >> ranking[i];
        // 상대적 등수 와 진입 차수를 저장
        // ex) adj[5][4] --> 5 가 4 보다 높은 등수
        // 예를 들어 순위가 5->4->3 인 경우 5->4 4->3 뿐 아니라 5->3도 연결시킨다.

        // for (int i = 1; i <= n; i++)
        //     for (int j = 1; j < i; j++)
        //     {
        //         adj[ranking[j]][ranking[i]] = 1;
        //         indegree[ranking[i]]++;
        //     }

        for (int i = 1; i <= n; i++)
            for (int j = n; j > i; j--)
            {
                adj[ranking[i]][ranking[j]] = 1;
                indegree[ranking[j]]++;
            }

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            // 각각의 경우에 대해 서로 간선의 방향을 바꿔주고, 진입 차수의 개수도 증가, 감소 해준다.
            // a 가 b 보다 높은 등수 adj[a][b] == 1
            if (adj[a][b])
            {
                indegree[a]++;
                indegree[b]--;
                adj[a][b] = 0;
                adj[b][a] = 1;
            } // b 가 a 보다 높은 등수
            else
            {
                indegree[a]--;
                indegree[b]++;
                adj[a][b] = 1;
                adj[b][a] = 0;
            }
        }
        queue<int> q;
        // 진입 차수가 0 인.. 즉, 1등을 큐에 집어 넣는다.
        for (int i = 1; i <= n; i++)
            if (indegree[i] == 0)
                q.push(i);
        // 예외가 발생했을 때, 예외에 대한 값을 저장할 변수
        int exceptCase = 0;
        // n 번에 정점에 대해 위상정렬
        for (int i = 1; i <= n; i++)
        {
            // queue 가 비어버리면 사이클 존재하는 것
            if (q.empty())
            {
                exceptCase = 1;
                break;
            }
            // queue 에 한번에 두 개 이상이 들어가면,, 답이 여러개가 되는 것.. indegree 가 0 인 것이 여러개 존재하는 것
            else if (q.size() >= 2)
            {
                exceptCase = 2;
                break;
            }

            int current = q.front();
            q.pop();
            ranking[i] = current;
            for (int j = 1; j <= n; j++)
            {
                // current 가 j 보다 앞서면 current 는 제거 되었기 때문에 current 에서 j 로 가는 간선을 지운다.
                // 즉, j 의 indegree 를 -1 하는 것
                if (adj[current][j])
                {
                    indegree[j]--;
                    // indegree 가 0 이 되면 다음 큐에 들어갈 것이 된다.
                    if (indegree[j] == 0)
                        q.push(j);
                }
            }
        }
        // 결과 출력
        if (exceptCase == 1)
            cout << "IMPOSSIBLE\n";
        else if (exceptCase == 2)
            cout << "?\n";
        else
        {
            for (int i = 1; i <= n; i++)
                cout << ranking[i] << " ";
            cout << "\n";
        }
        // 다음을 테스트를 위해 초기화
        memset(ranking, 0, sizeof(ranking));
        memset(indegree, 0, sizeof(indegree));
        memset(adj, 0, sizeof(adj));
    }
}