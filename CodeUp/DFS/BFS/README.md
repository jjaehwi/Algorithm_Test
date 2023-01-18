# 그래프 탐색 알고리즘: DFS / BFS

- 탐색(SEARCH)이란 많은 양의 데이터 중에서 `원하는 데이터를 찾는 과정`을 말합니다.

- 대표적인 그래프 탐색 알고리즘으로는 DFS와 BFS가 있습니다.

- `DFS / BFS는 코딩 테스트에서 매우 자주 등장하는 유형`이므로 반드시 숙지해야 합니다.

## 스택 자료구조

- 먼저 들어 온 데이터가 나중에 나가는 형식(선입후출)의 자료구조입니다.

- `입구와 출구가 동일한 형태`로 스택을 시각화할 수 있습니다.

## 큐 자료구조

- 먼저 들어 온 데이터가 먼저 나가는 형식(선입선출)의 자료구조입니다.

- 큐는 `입구와 출구가 모두 뚫려 있는 터널과 같은 형태`로 시각화 할 수 있습니다.

## 재귀 함수

- 재귀 함수(Recursive Function)란 `자기 자신을 다시 호출하는 함수`를 의미합니다.

- 재귀 함수의 종료 조건

  - 재귀 함수를 문제 풀이에서 사용할 때는 재귀 함수의 종료 조건을 반드시 명시해야 합니다.

  - 종료 조건을 제대로 명시하지 않으면 함수가 무한히 호출될 수 있습니다.

- 재귀 함수 사용의 유의 사항

  - 재귀 함수를 잘 활용하면 복잡한 알고리즘을 간결하게 작성할 수 있습니다.

  - 모든 `재귀 함수는 반복문을 이용하여 동일한 기능을 구현`할 수 있습니다.

  - 재귀 함수가 반복문보다 유리한 경우도 있고 불리한 경우도 있습니다.

  - 컴퓨터가 함수를 연속적으로 호출하면 컴퓨터 메모리 내부의 스택 프레임에 쌓입니다.
  - 그래서 스택을 사용해야 할 때 구현상 `스택 라이브러리 대신에 재귀 함수를 이용`하는 경우가 많습니다.

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
