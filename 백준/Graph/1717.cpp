// 집합의 표현 G4
// 분리 집합, 유니온 파인드
#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

using namespace std;

int n, m, p, a, b;
int parent[1000001];

void initParent(int n)
{
    for (int i = 0; i <= n; i++)
        parent[i] = i;
}

int find(int n)
{
    if (n == parent[n])
        return n;

    int result = find(parent[n]);
    parent[n] = result;
    return result;
    // return parent[n] = find(parent[n]);
}

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

int main()
{
    fastio;
    cin >> n >> m;
    initParent(n);
    for (int i = 0; i < m; i++)
    {
        cin >> p >> a >> b;
        if (p == 0)
            merge(a, b);
        if (p == 1)
        {
            if (find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}