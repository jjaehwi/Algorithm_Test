// 로봇 청소기 G5
// 시뮬레이션, 구현
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 51
int N, M;    // 세로 크기 N, 가로 크기 M
int r, c, d; // 북쪽으로부터 떨어진 칸의 개수 r, 서쪽으로 부터 떨어진 칸의 개수 c, 바라보는 방향 d
int cnt = 1;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
// 북 = 0, 동 = 1, 남 = 2, 서 = 3
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int bfs(int start_x, int start_y, int start_d)
{
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(start_x, start_y), start_d));
    visited[start_x][start_y] = true;
    while (!q.empty())
    {
        int current_x = q.front().first.first;
        int current_y = q.front().first.second;
        int current_d = q.front().second;
        q.pop();
        bool flag = false;
        // 왼쪽부터 4방향에 대한 탐색
        for (int i = 0; i < 4; i++)
        {
            // 2. 현재 d에 대해 왼쪽부터 탐색
            int next_d = current_d - 1;
            if (current_d == 0)
                next_d = 3;
            int next_x = current_x + dx[next_d];
            int next_y = current_y + dy[next_d];
            // 2-2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
            if (map[next_x][next_y] == 1 || visited[next_x][next_y])
            {
                current_d = next_d;
                continue;
            }
            // 2-1. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진.
            if (!visited[next_x][next_y])
            {
                visited[next_x][next_y] = true;
                q.push(make_pair(make_pair(next_x, next_y), next_d));
                cnt++;
                flag = true;
                break;
            }
        }

        // 2-3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
        if (!flag)
        {
            // 한 칸 후진
            int next_x = current_x - dx[current_d];
            int next_y = current_y - dy[current_d];
            // 뒤 가 벽이라면
            if (map[next_x][next_y] == 1)
                return cnt;
            // 그렇지 않으면 후진한 위치로 이동
            else
                q.push(make_pair(make_pair(next_x, next_y), current_d));
        }
    }
    return cnt;
}
int main()
{
    fastio;
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    cout << bfs(r, c, d);
    return 0;
}