// N과 M (1) S3
// 백트래킹
// 중복 순열, next_permutation..?
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int n, m;
int v[10];
bool visited[10];
int result[10];

void permutation(int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
            cout << result[i] << " ";
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
        if (!visited[i])
        {
            visited[i] = 1;
            result[depth] = v[i];
            permutation(depth + 1);
            visited[i] = 0;
        }
}
int main()
{
    fastio;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        v[i] = i + 1;

    permutation(0);
}