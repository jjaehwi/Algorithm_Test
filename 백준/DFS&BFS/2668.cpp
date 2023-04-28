// 숫자고르기 G5
// 그래프 탐색

// 사이클이 존재하면 추가한다.

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 101
int n, maxCnt;
int input[MAX_SIZE];
bool visited[MAX_SIZE];
int answer[MAX_SIZE];

void dfs(int current, int start)
{
    if (visited[current])
    {
        if (current == start)
            answer[maxCnt++] = start;
    }
    else
    {
        visited[current] = true;
        dfs(input[current], start);
    }
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> input[i];

    for (int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof(visited));
        dfs(i, i);
    }

    cout << maxCnt << "\n";
    for (int i = 0; i < maxCnt; i++)
        cout << answer[i] << "\n";
}