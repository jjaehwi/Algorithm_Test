// N과 M (1) S3
// 백트래킹
// 중복 순열, next_permutation

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

/*
// 중복 순열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int main()
{
    cin >> N >> M;
    vector<int> a;
    for (int i = 1; i <= N; i++)
        a.push_back(i);
    do
    {
        for (int i = 0; i < M; i++)
            cout << a[i] << " ";
        cout << "\n";
        reverse(a.begin() + M, a.end());
    } while (next_permutation(a.begin(), a.end()));
}
// https://dlog0518.tistory.com/54
*/

/*
// 중복 없는 순열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int main()
{
    cin >> N >> M;
    vector<int> a(N, 1);
    for (int i = 0; i < M; i++)
        a[i] = 0;
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << "\n";
    do
    {
        for (int i = 0; i < N; i++)
        {
            if (a[i] == 0)
                cout << i + 1 << " ";
        }
        cout << "\n";
    } while (next_permutation(a.begin(), a.begin() + N));
}

12
13
14
23
24
34
*/