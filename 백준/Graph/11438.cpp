// LCA 2 P5
// 트리, LCA (최소 공통 조상), 희소 배열
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

// MAX_SIZE < 2^k 가 될 수 있는 적당한 값을 넣으면 된다.
// (1000이니까 1024가 되는 2^10을 입력)
#define MAX_K 17
#define MAX_SIZE 100001
#define INF -1
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

int depth[MAX_SIZE];
int parent[MAX_K + 1][MAX_SIZE]; // dp를 위한 조상의 값

vector<vector<int>> adj;

// 조상 (parent, 부모노드의 값)과 depth 구하기
// 사실상 DP를 동작하기 전 트리의 값을 초기화 하는 역할에 가까움
void BFS(int nodeNum)
{
    queue<int> q;
    q.push(1);

    // 현재 depth와 조상의 root를 초기화한다.
    depth[1] = 0;
    parent[0][1] = 1;

    // 2^0 = 1
    // 즉, 그냥 1개의 depth씩 내려가면서, 부모/자식 노드 인덱스를 작성해둔다
    // 2^0을 이용하여, 그 뒤 2^1 ~ 2^k 까지 DP를 돌면서 해당 값을 저장해두는 것
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // 노드의 자식들을 큐에 삽입한다..
        int adjLength = adj[front].size();
        for (int i = 0; i < adjLength; i++)
        {
            int front_child = adj[front][i]; // front의 자식

            // depth가 계산된 적이 없다면
            if (depth[front_child] == INF)
            {
                parent[0][front_child] = front;        // 자식 노드 인덱스에 부모노드 인덱스 값을 넣어, 부모를 찾아갈 수 있게 함.
                depth[front_child] = depth[front] + 1; // depth 갱신(자식의 depth는 부모의 depth + 1 이다.
                q.push(front_child);                   // 자식을 큐에 삽입해, 자식의 자식(손자 노드)에 대해 부모값과 depth를 계산할 수 있게 한다.
            }
        }
    }
}

// dp! 점화식을 돌린다.
// 2^k 에서의 부모 값 = 2^k-1 일 때 값의 부모의 값(parent[k-1][n])
// 반을 나눠서 올라가는 것
// 2^1 부모 값 = 2^0 부모값 -> 2^0 부모 값
// 2^k의 부모 값 = 2^k-1 부모 값 -> 2^k-1 부모 값
void DP(int nodeNum)
{
    for (int k = 1; k < MAX_K + 1; k++)
        for (int n = 1; n <= nodeNum; n++)
            parent[k][n] = parent[k - 1][parent[k - 1][n]];
}

int LCA(int a, int b)
{
    // 예외 처리 해줘야 한다.
    if (depth[a] != depth[b])
        if (depth[a] > depth[b])
            swap(a, b);
    // 1. a의 높이를 b와 맞춘다.
    // b가 더 큼
    if (depth[a] < depth[b])
    {
        for (int k = MAX_K; k >= 0; k--)
            if (a != b && depth[parent[k][b]] >= depth[a])
                b = parent[k][b];
    }

    // a가 더 큼
    if (depth[a] > depth[b])
    {
        for (int k = MAX_K; k >= 0; k--)
            if (a != b && depth[parent[k][a] >= depth[b]])
                a = parent[k][a];
    }

    // 2. 높이가 같아지면 위로 2^k 씩 올라가면서 공통 조상을 찾는다.
    for (int k = MAX_K; k >= 0; k--)
    {
        if (a != b && parent[k][a] != parent[k][b])
        {
            a = parent[k][a];
            b = parent[k][b];
        }
    }
    // 두 노드가 같다면 a는 b의 조상
    return (a == b) ? a : parent[0][a];
}
int main()
{
    fastio;
    int n;
    cin >> n;
    adj.resize(n + 1);
    // depth 초기화
    //  fill(depth,depth+n;INF)
    for (int i = 0; i <= n; i++)
        depth[i] = INF;

    // 인접 리스트
    for (int i = 1; i < n; i++)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    // BFS로 구조 만듬
    BFS(n);

    // DP로 점화실 돌려 parent를 채운다.
    DP(n);

    // 최소 공통 조상 출력
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
}

// 예외 처리 없을 때 반례
/*
22
1 2
1 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16
16 17
17 18
18 19
19 20
20 21
21 22
2
22 21
21
21 22
21

출력
1
21

정답
21
21
*/