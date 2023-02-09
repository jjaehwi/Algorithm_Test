// 파이프 옮기기 1 G5
// 그래프 탐색, dp

// 가로는 가로로 한칸 차지
// 대각선은 가로 세로 대각선 3칸 차지
// 세로는 세로로 한칸 차지
// 이 칸에 벽이 있으면 갈 수 없는 것.

#include <iostream>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 17
int N, cnt;
int map[MAX_SIZE][MAX_SIZE];
struct pipe
{
    int x;
    int y;
    int direction; // 0 : 가로, 1 : 대각선, 2 : 세로
};
// 가로, 대각선, 세로
int dx[] = {0, 1, 1};
int dy[] = {1, 1, 0};

queue<pipe> q;

void move(int x, int y, int d, int i)
{
    int next_x = x + dx[i];
    int next_y = y + dy[i];
    int next_dir = i;
    if (map[next_x][next_y] == 0 && next_x > 0 && next_x <= N && next_y > 0 && next_y <= N)
    {
        if (i == 1)
            // 대각선은 추가로 체크
            if (map[next_x - 1][next_y] == 1 || map[next_x][next_y - 1] == 1)
                return;
        q.push({next_x, next_y, next_dir});
    }
}

void bfs(int start_x, int start_y, int dir)
{

    q.push({start_x, start_y, dir});
    while (!q.empty())
    {
        int current_x = q.front().x;
        int current_y = q.front().y;
        int current_dir = q.front().direction;
        q.pop();
        if (current_x == N && current_y == N)
            cnt++;
        // 현재 방향이 가로 인 경우
        if (current_dir == 0)
            // 가로인 경우 가로,대각선만 가능
            for (int i = 0; i < 2; i++)
                move(current_x, current_y, current_dir, i);

        // 현재 방향이 대각선 인 경우
        else if (current_dir == 1)
            // 대각선인 경우는 가로, 대각선, 세로 전부 가능
            for (int i = 0; i < 3; i++)
                move(current_x, current_y, current_dir, i);

        // 현재 방향이 세로 인 경우
        else
            // 세로인 경우 대각선, 세로만 가능
            for (int i = 1; i < 3; i++)
                move(current_x, current_y, current_dir, i);
    }
}
int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];

    bfs(1, 2, 0);

    cout << cnt;
    return 0;
}
