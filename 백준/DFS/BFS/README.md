# 백준 DFS/BFS 문제집

- [문제집링크](https://www.acmicpc.net/workbook/view/1983)

# DFS (Depth-First Search)

- DFS는 `깊이 우선 탐색`이라고도 부르며 그래프에서 `깊은 부분을 우선적으로 탐색하는 알고리즘`입니다.

- DFS는 `스택 자료구조(혹은 재귀 함수)`를 이용하며, 구체적인 동작 과정을 다음과 같습니다.

  1. 탐색 시작 노드를 스택에 삽입하고 방문 처리를 합니다.

  2. 스택의 최상단 노드에 방문하지 않은 인접한 노드가 하나라도 있으면 그 노드를 스택에 넣고 방문 처리합니다. 방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼냅니다.

  3. 더 이상 2번의 과정을 수행할 수 없을 때까지 반복합니다.

# BFS (Breadth-First Search)

- BFS는 `너비 우선 탐색`이라고도 부르며, 그래프에서 `가까운 노드부터 우선적으로 탐색하는 알고리즘`입니다.

- BFS는 `큐 자료구조`를 이용하며, 구체적인 동작 과정은 다음과 같습니다.

  1. 탐색 시작 노드를 큐에 삽입하고 방문 처리를 합니다.

  2. 큐에서 노드를 꺼낸 뒤에 해당 노드의 인접 노드 중에서 방문하지 않은 노드를 모두 큐에 삽입하고 방문 처리합니다.

  3. 더 이상 2번의 과정을 수행할 수 없을 때까지 반복합니다.

```
#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 100
using namespace std;

vector<vector<int>> adj;
bool visited[MAX_SIZE];

// dfs _ 깊이 우선
void DFS(int nowNode)
{
    // 방문한 정점이면 제외
    if (visited[nowNode])
        // 가지치기 로직 추가 가능
        return;

    visited[nowNode] = true;
    // 로직 추가 가능

    int adjLength = adj[nowNode].size();
    for (int i = 0; i < adjLength; i++)
    {
        int nextNode = adj[nowNode][i];

        // 재귀는 콜스택을 많이 먹기 때문에 메모리가 초과될 수 있다. 를 조심
        // 조건 로직 추가 가능
        if (!visited[nextNode])
        { // 방문한 정점이면 제외
            DFS(nextNode);
            // 로직 추가 가능
        }
    }
}

// bfs _ 너비 우선
void BFS(int startNode)
{
    queue<int> q;
    q.push(startNode);

    visited[startNode] = true; // 처음 들어가는 것에 대해 방문 표시
    // 로직 추가 가능
    while (!q.empty())
    {
        int nowNode = q.front();
        q.pop();
        // 로직 추가 가능

        int adjLength = adj[nowNode].size();
        for (int i = 0; i < adjLength; i++)
        {
            int nextNode = adj[nowNode][i];

            // 조건 로직 추가 가능
            if (!visited[nextNode])
            { // 방문한 정점이면 제외
                visited[nextNode] = true;
                // 로직 추가 가능
                q.push(nextNode);
            }
        }
    }
}

int main()
{
}
```
