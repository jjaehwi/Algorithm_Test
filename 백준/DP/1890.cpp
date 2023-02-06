// 점프 S1
// dp

#include <iostream>
using namespace std;
#define MAX_SIZE 101
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int map[MAX_SIZE][MAX_SIZE];
long long dp[MAX_SIZE][MAX_SIZE]; // DP[a][b] = c 의 의미 --> (a, b)까지 올 수 있는 경로의 수는 c개
int N;
int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];
    dp[1][1] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (dp[i][j] == 0)
                continue;
            if (i == N && j == N)
                break;
            int value = map[i][j];
            int down = value + i;
            int right = value + j;

            if (down <= N)
                dp[down][j] = dp[down][j] + dp[i][j];
            if (right <= N)
                dp[i][right] = dp[i][right] + dp[i][j];
        }
    }
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= N; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    cout << dp[N][N];
}

/* bfs로 풀면 메모리 초과 발생. 너비가 너무 넓어지기 때문 100 1 ..... 1 인 경우
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define MAX_SIZE 101
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int map[MAX_SIZE * 4][MAX_SIZE * 4];
int N, cnt;
int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(1, 1), map[1][1]));
    while (!q.empty())
    {
        int current_x = q.front().first.first;
        int current_y = q.front().first.second;
        int current_value = q.front().second;
        q.pop();

        int next_x = current_x + current_value;
        int next_y = current_y + current_value;

        if ((next_x == N && current_y == N) || (current_x == N && next_y == N))
            cnt++;

        if (next_x <= N && map[next_x][current_y] != 0)
            q.push(make_pair(make_pair(next_x, current_y), map[next_x][current_y]));
        if (next_y <= N && map[current_x][next_y] != 0)
            q.push(make_pair(make_pair(current_x, next_y), map[current_x][next_y]));
    }
    cout << cnt;
}
*/