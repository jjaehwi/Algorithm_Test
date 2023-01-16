// 크루스칼 알고리즘 (MST) Union-Find 개념이 들어가서 프림 보다 더 쉽다.
// 크루스칼 알고리즘은 간선에 대한 정렬이 필요하다.
// struct 와 class의 차이 --> struct는 디폴트가 public, class는 디폴트가 private
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 10001
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
using namespace std;

int N, M, a, b, c;
int parent[MAX_SIZE];
struct edge
{
    int start;
    int end;
    int weight; // 가중치
};

vector<edge> vecEdge; // Edge를 담는 벡터 선언

// 기존 union - find 내용 시작
void initParent(int N)
{
    for (int i = 0; i <= N; i++)
        parent[i] = i;
}

int find(int N)
{
    if (N == parent[N])
        return N;

    int result = find(parent[N]);
    parent[N] = result;
    return result;
    // return parent[n] = find(parent[n]);
}

bool merge(int a, int b)
{
    // 1. 두 개의 루트를 각각 찾는다.
    a = find(a);
    b = find(b);

    // 2. 루트가 같다면 두 개는 이미 union 되어 있으므로 종료한다. (이미 merge 되어있다는 의미로 true 반환)
    if (a == b)
        return true;

    // 루트가 다르다면 a의 루트를 b로 설정 (거꾸로 해도 상관 x)
    parent[a] = b;
    return false;
}
// 기존 union - find 내용 끝

// 객체를 따로 만들어서 쓰기 때문에 정렬을 할 때 comparator를 사용해야 한다.
// comparator --> 정렬을 할 때 쓰는 기준.
// a<b 는 오름차순, a>b 는 내림차순
// 조건을 줄 수 있기 때문에 유용하다.
// ex) if(a.weight == b.weight){ return a.start> b.start;}
bool compare(edge a, edge b)
{
    return a.weight < b.weight; // 가중치에 대한 오름차순
}

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

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        vecEdge.push_back({a, b, c});
    }
    cout << MST(N);
}