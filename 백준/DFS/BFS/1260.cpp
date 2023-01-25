// DFS와 BFS S2
// 알고리즘 분류 - 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

// vector 사용 풀이
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_SIZE 1001
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int N, M, V;
vector<vector<int>> adj;
bool visited[MAX_SIZE] = {
    false,
};

void dfs(int startNode)
{
    cout << startNode << " ";
    visited[startNode] = true; // 시작 노드 방문처리
    int adjLengh = adj[startNode].size();
    for (int i = 0; i < adjLengh; i++)
    {
        int nextNode = adj[startNode][i];
        if (!visited[nextNode])
            dfs(nextNode);
    }
}
void bfs(int startNode)
{
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    while (!q.empty())
    {
        int nowNode = q.front();
        q.pop();
        cout << nowNode << " ";
        int adjLength = adj[nowNode].size();
        for (int i = 0; i < adjLength; i++)
        {
            int nextNode = adj[nowNode][i];
            if (!visited[nextNode])
            {
                visited[nextNode] = true;
                q.push(nextNode);
            }
        }
    }
}
int main()
{
    fastio;
    cin >> N >> M >> V;
    adj.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        // 인접 리스트 표시
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= N; i++)
        sort(adj[i].begin(), adj[i].end());
    dfs(V);
    for (int i = 0; i < MAX_SIZE; i++)
        visited[i] = false;
    cout << "\n";
    bfs(V);
}

/* 배열 사용 풀이
#include <iostream>
#include <queue>
using namespace std;

#define MAX_VALUE 1001         //'N이 1~1000 이므로 1000번째 인덱스에 접근 -> 크기 1001까지 선언
int N, M, V;                   // 노드 개수, 간선 개수, 시작할 노드 번호
int mat[MAX_VALUE][MAX_VALUE]; // 인접행렬 배열 선언
int visited[MAX_VALUE];        // visited 배열 default 는 0으로. . .

void dfs(int v)
{

    cout << v << ' ';
    visited[v] = 1; // 방문한 노드를 visited 0에서 1로 변경
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 1 || mat[v][i] == 0)
            continue;
        dfs(i); // dfs에서 재귀를 사용
    }
}

void bfs(int v)
{
    queue<int> q; // bfs에서는 q를사용
    q.push(v);
    visited[v] = 0; // 방문한 노드를 visited 1에서 0으로 변경
    while (!q.empty())
    {
        v = q.front();
        cout << q.front() << ' ';
        q.pop();
        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == 0 || mat[v][i] == 0)
                continue;
            q.push(i);
            visited[i] = 0;
        }
    }
}

int main()
{
    int x, y;
    cin >> N >> M >> V; // N은 노드개수, M은 간선의개수, V는 처음 위치의 기준이 되는 노드
    for (int i = 0; i < M; i++)
    { // 간선의 개수만큼 서로 이어줄 x와 y노드를 입력받습니다.
        cin >> x >> y;
        mat[x][y] = mat[y][x] = 1; // 인접행렬 표시
    }
    dfs(V);
    cout << '\n';
    bfs(V);
    return 0;
}
*/
