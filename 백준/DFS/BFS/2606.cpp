#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<int> a[101];
bool check[101];
int cnt = 0;

void dfs(int x)
{
    check[x] = true;
    for (int i = 0; i < a[x].size(); i++)
    {
        int y = a[x][i];
        if (!check[y])
        {
            dfs(y);
            cnt++;
        }
    }
}

int main()
{
    int n, m; // n : 노드 개수, m : 엣지 개수
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    } // edge 연결
    dfs(1);
    cout << cnt << "\n";
}