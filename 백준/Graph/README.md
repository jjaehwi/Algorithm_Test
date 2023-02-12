# 그래프 이론

`그래프 (Graph)`의 정의

- 현실 세계의 `사물`이나 `개념` 간의 `연결 관계`를 수학적 모델로 단순화 하여 표현한 것

- 수학적 정의 : 정점(Vertex, Node) 집합 V = {v1, v2, v3 ,,, vn}이고, 정점간의 연결 관계들을 나타내는 간선(Edge, Link, Arc) 집합 E = {(vi, vj) / vi ∈ V, vj ∈ V} ⊆ V x V 일 때, 그래프 G = (V,E) 이다.

## 그래프 용어

**무향 간선 (Undirected Edge)**

- 정점을 연결하는 `간선에 방향이 존재하지 않는다.`

- 임의의 간선 (vi, vj)에 대해서 (vi, vj) = (vj, vi) 이다.

**유향 간선 (Directed Edge)**

- 정점을 연결하는 `간선에 방향이 존재한다.`

- 임의의 간선 (vi, vj)에 대해서 (vi, vj) != (vj, vi) 이다.

**인접 (Adjacent)**

- 정점 vi, vj 에 대해서 간선 e = (vi, vj)가 존재한다.

- 정점 vi 와 vj 는 인접(adjacent)한다.

**부속 (Incident)**

- 정점 vi, vj 에 대해서 간선 e = (vi, vj)가 존재한다.

- 간선 e는 정점 vi 와 vj 에 부속(incident)한다.

**차수 (Degree)**

- 정점(vertex)에 부속(incident)된 간선(edge)의 수

- in-degree : 방향 그래프에서 정점에 `들어오는` 간선의 수

- out-degree : 방향 그래프에서 정점에서 `나가는` 간선의 수

**경로 (Path)**

- 정점과 간선이 `교대로 구성`된 sequence

- 단순 경로 (Simple Path) : 정점과 간선이 `중복되지 않은` 경로

**회로 (Cycle)**

- `시작 정점과 끝 정점이 같은 경로`

- 단순 회로 (Simple Cycle) : 정점과 간선이 `중복되지 않은` 회로

**연결됨 (Connected)**

- 정점 vi 에서 정점 vj 로의 `경로가 존재`하면, 정점 vi 와 정점 vj 는 연결되어 있다고 한다.

## 그래프 종류

**무향 그래프 (Undirected Graph)**

- `무향 간선`으로 이루어진 그래프

**유향 그래프 (Directed Graph)**

- `유향 간선`으로 이루어진 그래프

**가중치 그래프 (Weighted Graph)**

- `가중치 or 비용` 을 가지는 간선으로 이루어진 그래프

**정규 그래프 (Regular Graph)**

- 모든 정점이 `동일한 차수`를 가지는 그래프

**완전 그래프 (Complete Graph)**

- `모든 정점에서 모든 정점으로 갈 수 있다.`

- 임의의 두 정점 vi, vj 에 대해서 vi, vj 를 잇는 간선 Edge(vi, vj)이 존재하는 그래프

- 완전 그래프는 정규 그래프이다.

- N개의 정점을 가지는 `무향 그래프`의 경우 : 간선의 개수 = `1/2 N(N-1)`

- N개의 정점을 가지는 `유향 그래프`의 경우 : 간선의 개수 = `N(N-1)`

**연결 그래프 (Connected Graph)**

- 임의의 두 정점 vi, vj 에 대해서 경로 Path(vi, vj)가 존재하는 그래프

**부분 그래프**

- 어떤 그래프의 정점 집합의 부분 집합과 그에 속한 간선들로 이루어진 그래프

- 어떤 그래프의 간선 집합의 부분 집합과 그에 속한 정점들로 이루어진 그래프

**트리 그래프**

- `순환을 갖지 않는 연결 그래프`

- 임의의 두 정점에 대해서 경로가 정확히 1개 존재한다.

- 하나 이상의 정점을 가지며, 임의의 간선 e 를 제거한 그래프는 연결 그래프가 아니다.

## 최단 경로(shortest path) 알고리즘

### 1. 다익스트라 (Dijkstra)

### 2. 플로이드-워셜 (Floyd-Warshall)

### 3. 벨만-포드 (Bellman-Ford)

## 서로소 집합 (Disjoint Set, Union-Find)

- 교집합이 공집합인 `집합(서로소 집합) 들의 정보를 확인(Find)하고 조작(Union)`할 수 있는 자료구조

**Union 연산**

- 어떤 두 원소 a, b 에 대해서 union(a, b) 는 `각 원소가 속한 집합을 하나로 합치는 연산`

- a ∈ A, b ∈ B 에 대해서, union(a, b) 는 A U B 이다.

**Find 연산**

- 어떤 원소 a 에 대해서 a 가 속한 `집합(집합의 대표 번호)을 반환`

- a ∈ A 에 대해서, find(a) 는 집합 A (집합 A의 대표 번호)를 반환

**서로소 집합의 구현 및 최적화**

`초기화` : parent 배열에 i 원소에 대한 부모 노드 번호를 저장, 루트 노드인 경우 자기 자신의 번호를 저장

```
void initParent(int n)
{
    for (int i = 0; i <= n; i++)
        parent[i] = i;
}
```

`Union 연산` : 하나의 루트 노드를 다른 하나의 루트 노드의 자식 노드로 넣어 두 트리를 합친다.

```
void merge(int a, int b)
{
    // 1. 두 개의 루트를 각각 찾는다.
    a = find(a);
    b = find(b);

    // 2. 루트가 같다면 두 개는 이미 union 되어 있으므로 종료한다. (이미 merge 되어있다는 의미로 true 반환)
    if (a == b)
        return;

    // 루트가 다르다면 a의 루트를 b로 설정 (거꾸로 해도 상관 x)
    parent[a] = b;
}
```

`Find 연산` : 주어진 원소의 루트 노드 번호를 반환한다.

```
int find(int n)
{
    if (n == parent[n])
        return n;

    int result = find(parent[n]);
    parent[n] = result;
    return result;
    // 중간에 부모값을 계속 갱신해주는 것
    // return parent[n] = find(parent[n]);
}
```

[연습문제 백준 1717번](https://github.com/jjaehwi/Algorithm_Test/blob/main/백준/Graph/1717.cpp)

### 최소 신장 트리 (Minimum Spanning Tree)

**트리와 그래프 관계**

- 트리는 그래프 중에서 특수한 경우에 해당하는 자료구조로, `사이클이 존재하지 않는 방향 그래프`다.

**신장 트리(Spanning Tree)**

- 그래프 상에서 `모든 노드가 사이클 없이 연결된 부분 그래프`를 뜻한다. 이 부분 그래프는 여러개가 존재할 수 있다.

**깊이 우선(DFS) 신장 트리**

- 무향 연결 그래프 G 에서 깊이 우선 탐색 (DFS) 으로 탐색하면서 생성된 신장 트리

**너비 우선(BFS) 신장 트리**

- 무향 연결 그래프 G 에서 너비 우선 탐색 (BFS) 으로 탐색하면서 생성된 신장 트리

**최소 신장 트리**

- 여러 개의 부분 그래프 중 `모든 정점이 최소 간선의 합`으로 연결된 부분 그래프이다.

- 무향 연결 가중 그래프 G 에서 `간선의 가중치의 합이 최소`인 신장 트리

<img width="583" alt="스크린샷 2023-02-11 오후 8 00 26" src="https://user-images.githubusercontent.com/87372606/218254523-b4eef0c5-200d-446b-8516-6daf4940b687.png">

### 1. 크루스칼 (간선이 적은 경우)

- `간선 기준`이고 `union - find` 를 사용한다. 합치고 `유망한지 판단`한다.

- 가장 적은 비용으로 모든 노드를 연결할 수 있다.

- 그리디 알고리즘

- `시간 복잡도`: 알고리즘에서 시간이 가장 오래 걸리는 부분이 간선 정렬이므로, 간선의 개수가 E개일 때 O(ElogE)

**크루스칼 알고리즘 구현**

1. `간선에 대한 정렬`이 필요하다.

2. 간선을 하나씩 확인하며 현재의 `간선이 사이클을 발생시키는지 유망을 판단`한다.

   2.1 사이클이 발생하지 않는 경우 최소 신장 트리에 포함

   2.2 사이클이 발생하는 경우 최소 신장 트리에 포함시키지 않음

3. 모든 간선에 대해 2번 과정을 `반복`한다.

4. `간선의 개수가 N-1 이 될 때 전부 연결`된 것이므로 종료한다.

지금 있는 정점에서 나가는 정점 중 제일 작은 걸 포함시킨다. -> 최소 힙 -> 우선 순위 큐 (priority queue)

```
int MST(int vertex)
{
    int currentWeight = 0;
    int mstEdgeCount = 0;
    // union - find 초기화
    initParent(vertex);
    // 가중치에 대해 오름차순 정렬
    sort(vecEdge.begin(), vecEdge.end(), compare);
    // 간선 순회
    for (int i = 0; i < vecEdge.size(); i++)
    {

        // 두개가 같은 집합이 아니면 (두개가 연결되어있지 않으면) MST에 해당 간선을 포함시켜주고, 그때의 가중치를 더하고, edge의 수를 1개 올린다.
        // merge 되면서 parent들을 전부 갱신시켜 주기 때문에 결과값만 if문으로 확인하면 된다.
        if (merge(vecEdge[i].start, vecEdge[i].end) == false)
        {
            currentWeight += vecEdge[i].weight;
            mstEdgeCount++;
        }
        // 간선이 N-1개가 되면 전부 연결된 것이므로 종료한다.
        if (mstEdgeCount == N - 1)
            break;
    }
    return currentWeight;
}
```

ex) [백준 1922번](https://github.com/jjaehwi/Algorithm_Test/blob/main/백준/Graph/1922.cpp)

### 2. 프림 (간선이 많은 경우)

- `정점 기준` 이다.

## 위상 정렬 (Topological Sort)

- `DAG (비순환 방향 그래프)에서 그래프의 방향성을 거스르지 않고 정점들을 나열하는 것`

- 위상 정렬은 `각 정점을 우선순위에 따라 배치`한 것

- 일반적으로 위상 정렬의 결과는 `유일하지 않다` (Indegree 가 0 인게 여러개일 수 있기 때문)

진입 차수가 없다는 것 -> 돌아올 수 없다 -> 우선 순위가 가장 높은 것 -> 가장 처음에 동작하는 것

`어떤 순서나 선행, 그래프` 에 관한 얘기가 나오면 위상 정렬을 의심해보자.. ex) [백준 1516번](https://github.com/jjaehwi/Algorithm_Test/blob/main/백준/Graph/1516.cpp)

**위상 정렬의 동작**

1. 진입 차수가 0 인 노드를 큐에 넣는다.

2. 큐가 빌 때까지 다음의 과정을 반복한다.

   2.1 큐에서 원소를 꺼내 해당 노드에서 출발하는 간선을 그래프에서 제거한다.

   2.2 새롭게 진입 차수가 0 이 된 노드를 큐에 넣는다.

- 큐가 빌 때까지 원소를 계속 꺼내서 처리하는 과정을 반복하고, 모든 원소를 방문하기 전에 큐가 빈다면 사이클이 존재한다고 판단 가능하다.

- 사이클이 존재하는 경우 사이클에 포함되어 있는 원소 중에서 어떠한 원소도 큐에 들어가지 못하기 때문이다.

### DAG (Directed Acyclic Graph)

- DAG 는 `순환을 가지지 않는 방향그래프`를 말한다.

- 일반적으로 `우선 순위`를 가진 일련의 작업들은 DAG 구조를 가진다.

ex 1) 스타크래프트에서 건물 짓는 순서

ex 2) 대학 과정의 선수 과목

`선행자(predecessor) 와 후행자(successor)`

- DAG 에서 어떤 정점 vi ∈ V, vj ∈ V 에 대해서 vi 에서 vj 로의 `경로`가 존재하면, vi 를 vj 의 선행자, vj 는 vi 의 후행자라 한다.

`즉각 선행자(immediate predecessor) 와 즉각 후행자(immediate successor)`

- DAG 에서 어떤 정점 vi ∈ V, vj ∈ V 에 대해서 vi 에서 vj 로의 `간선`이 존재하면, vi 를 vj 의 즉각 선행자, vj 는 vi 의 즉각 후행자라 한다.

추가해야할 것.
LCA (최소 공통 조상)
단절점과 단절선
