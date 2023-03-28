// 숨바꼭질 S1
// 그래프 탐색, bfs

#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 100001
int N, K, cnt, result;
bool visited[MAX_SIZE];

int bfs(int startNode)
{
    queue<pair<int, int>> q;
    q.push(make_pair(startNode, 0));
    visited[startNode] = true;
    while (!q.empty())
    {
        int nowNode = q.front().first;
        int nowDepth = q.front().second;
        q.pop();
        if (nowNode == K)
        {
            return nowDepth;
        }
        int move_Back = nowNode - 1;
        int move_Front = nowNode + 1;
        int move_Jump = nowNode * 2;

        if (!visited[move_Back] && move_Back >= 0 && move_Back <= MAX_SIZE)
            q.push(make_pair(move_Back, nowDepth + 1));
        if (!visited[move_Front] && move_Front >= 0 && move_Front <= MAX_SIZE)
            q.push(make_pair(move_Front, nowDepth + 1));
        if (!visited[move_Jump] && move_Jump >= 0 && move_Jump <= MAX_SIZE)
            q.push(make_pair(move_Jump, nowDepth + 1));
    }
    return 0;
}
int main()
{
    fastio;
    cin >> N >> K;
    cout << bfs(N);
}