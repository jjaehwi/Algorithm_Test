// 물통 G5
// 그래프 탐색, bfs, dfs
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_SIZE 201
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int A, B, C;
// Visit[a][b][c] = true 는 A물통에 a의 물양이, B물통에 b의 물양이, C물통에 c의 물양이 들어 있을 때는 이미 탐색 했다는 뜻
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE];
vector<int> result;

// 각 물통에 차 있는 물의 양
struct bottle
{
    int a;
    int b;
    int c;
};

void bfs()
{
    queue<bottle> q;
    // 처음 상태: A, B 는 빈 상태, C 는 풀
    q.push({0, 0, C});

    while (!q.empty())
    {
        int nowA = q.front().a;
        int nowB = q.front().b;
        int nowC = q.front().c;
        q.pop();

        if (visited[nowA][nowB][nowC] == true)
            continue;
        visited[nowA][nowB][nowC] = true;

        // 첫 번째 물통(용량이 A인)이 비어 있을 때, 세 번째 물통(용량이 C인)에 담겨있을 수 있는 물의 양을 모두 구해내는 프로그램
        if (nowA == 0)
            result.push_back(nowC);

        // A -> B
        if (nowA + nowB > B)
            q.push({nowA + nowB - B, B, nowC});
        else
            q.push({0, nowA + nowB, nowC});

        // A -> C
        if (nowA + nowC > C)
            q.push({nowA + nowC - C, nowB, C});
        else
            q.push({0, nowB, nowA + nowC});

        // B -> A
        if (nowB + nowA > A)
            q.push({A, nowB + nowA - A, nowC});
        else
            q.push({nowB + nowA, 0, nowC});

        // B -> C
        if (nowB + nowC > C)
            q.push({nowA, nowB + nowC - C, C});
        else
            q.push({nowA, 0, nowB + nowC});

        // C -> A
        if (nowC + nowA > A)
            q.push({A, nowB, nowC + nowA - A});
        else
            q.push({nowC + nowA, nowB, 0});

        // C -> B
        if (nowC + nowB > B)
            q.push({nowA, B, nowC + nowB - B});
        else
            q.push({nowA, nowC + nowB, 0});
    }
}

int main()
{
    fastio;
    cin >> A >> B >> C;
    bfs();
    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}