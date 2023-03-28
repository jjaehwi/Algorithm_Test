// 촌수 계산 S2
// 그래프 탐색, bfs, dfs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_SIZE 101
int N, M, A, B, cnt, chk;
vector<vector<int>> adj;
bool visited[MAX_SIZE];
int length[MAX_SIZE];

// bfs 는 노드로 부터 길이 로 계산을 한다.
void bfs(int startNode, int target)
{
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    while (!q.empty())
    {
        int nowNode = q.front();
        q.pop();
        // cout << "첫 nowNode : " << nowNode << "\n";
        for (int i = 0; i < adj[nowNode].size(); i++)
        {
            int nextNode = adj[nowNode][i];
            // cout << "두번째 nowNode : " << nowNode << "\n";
            // cout << "nextNode : " << nextNode << "\n";
            // cout << "length[nowNode] : " << length[nowNode] << "\n";
            if (!visited[nextNode])
            {
                visited[nextNode] = true;
                length[nextNode] = length[nowNode] + 1;
                q.push(nextNode);
            }
            if (nextNode == target)
                chk = length[target];
        }
    }
}

// void dfs(int startNode, int target, int num)
// {
//     visited[startNode] = true;
//     // cout << "첫 부분 startNode : " << startNode << "\n";
//     if (startNode == target)
//         chk = cnt;

//     int adjLength = adj[startNode].size();
//     for (int i = 0; i < adjLength; i++)
//     {

//         int nextNode = adj[startNode][i];
//         // cout << "두번째 부분 startNode : " << startNode << "\n";
//         // cout << "nextNode : " << nextNode << "\n";
//         // if (startNode == A)
//         //     cnt = 0;
//         if (!visited[nextNode])
//         {
//             cnt++;
//             dfs(nextNode, target, num + 1);
//         }
//     }
// }

int main()
{
    cin >> N >> A >> B >> M;
    adj.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(A, B);
    if (chk == 0)
        cout << "-1\n";
    else
        cout << chk;
}

// dfs인 경우 재귀에 들어가면 return 을 줘도 계속 다 돌고나서 반환을 하기 때문에 target을 잡았을 때 그 때의 count를 다른 변수에 저장을 해두어야한다
// 다른 방법으로 인자로 num을 넘겨서 그 때의 count를 기억하게 해서 재귀 끝나고 돌아올 때 같이 num도 기억하게 되는 그런 방법이 더 쉽다.

// bfs의 경우 dfs와 같이 접근하면 너비 탐색을 하고 다음 node로 넘어갈 때 마다 count가 증가하기 때문에 이런 방법은 불가능하고
// node로 부터의 길이를 기억해두었다가 너비 탐색이 끝나고 다음 노드로 넘어갈 때 길이를 +1 시키는 방법으로 풀이가 가능하다.