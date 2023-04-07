// 등산로 조성 [모의 SW 역량테스트]
// bfs
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 9
int T, N, K, answer;
int map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
vector<pair<int, int>> v;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int max_height, max_length;
struct queueState
{
    int x;
    int y;
    int dist;
};

int bfs(int start_x, int start_y)
{
    memset(visited, -1, sizeof(visited));
    queue<queueState> q;
    q.push({start_x, start_y, 1});
    visited[start_x][start_y] = 1;
    int length = 1;
    while (!q.empty())
    {
        int current_x = q.front().x;
        int current_y = q.front().y;
        int current_dist = q.front().dist;
        q.pop();
        length = max(length, current_dist);
        for (int i = 0; i < 4; i++)
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N &&
                visited[current_x][current_y] + 1 > visited[next_x][next_y] &&
                map[current_x][current_y] > map[next_x][next_y])
            {
                visited[next_x][next_y] = visited[current_x][current_y] + 1;
                q.push({next_x, next_y, current_dist + 1});
            }
        }
    }
    return length;
}

void solve()
{
    for (int i = 0; i < v.size(); i++)
    { // 최대 봉우리 전부 탐색
        int cur_x = v[i].first;
        int cur_y = v[i].second;
        // 봉우리는 깍으면 안되니까
        if (map[cur_x][cur_y] == max_height)
            answer = max(answer, bfs(cur_x, cur_y));
    }
}
int main()
{
    fastio;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        memset(map, 0, sizeof(map));
        max_length = 0;
        answer = 0;
        max_height = 0;
        cin >> N >> K;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                cin >> map[i][j];
                max_height = max(max_height, map[i][j]);
            }

        // 최대 봉우리 저장
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (map[i][j] == max_height)
                    v.push_back({i, j});

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k <= K; k++)
                {                   // 모든 좌표를 0~K만큼 깎아준다
                    map[i][j] -= k; // 깎아주고
                    solve();        // solve함수호출(최대등산로구해주기)
                    map[i][j] += k; // 복원
                }
        cout << "#" << t << " " << answer << "\n";
    }
}