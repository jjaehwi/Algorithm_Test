// 영역 구하기 S1
// 그래프 이론, DFS, BFS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 101
int M, N, K, cnt;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;
// 각 영역의 넓이를 저장할 벡터
vector<int> area;
void bfs()
{
    int temp = 0;
    while (!q.empty())
    {
        temp++;
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && map[next_x][next_y] == 0 && !visited[next_x][next_y])
            {
                visited[next_x][next_y] = true;
                q.push({next_x, next_y});
            }
        }
    }
    area.push_back(temp);
}
int main()
{
    fastio;
    cin >> M >> N >> K;
    while (K--)
    {
        int x1, y1, x2, y2; // 왼쪽 아래 꼭짓점 좌표 / 오른쪽 위 꼭짓점 좌표
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = M - y2; i < M - y1; i++)
            for (int j = x1; j < x2; j++)
                map[i][j] = 1;
        /*
        for (int i = y1; i < y2; i++)
            for (int j = x1; j < x2; j++)
                map[i][j] = 1;
        가 되어도 뒤집힌 것이기 때문에 넓이에 영향은 없다.
        */
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 0 && !visited[i][j])
            {
                cnt++;
                q.push({i, j});
                visited[i][j] = true;
                bfs();
            }
        }
    }
    sort(area.begin(), area.end());
    cout << cnt << "\n";
    for (int i = 0; i < area.size(); i++)
        cout << area[i] << " ";
}
