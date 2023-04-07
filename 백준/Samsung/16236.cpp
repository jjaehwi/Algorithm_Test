// 아기 상어 G3
// bfs, 구현, 시뮬레이션
// 아기 상어의 시작 크기는 2, 크기가 1 커지기 위해서는 자기의 크기 만큼 물고기를 먹어야함.
// 아기 상어가 물고기를 먹을 때, 자기 크기보다 작은 물고기만 먹을 수 있고, 자기랑 크기가 같으면 먹진 못하고 지나갈 순 있음
// 더이상 먹을 수 있는 물고기가 없으면 종료
// 먹을 수 있는 물고기가 1마리면 그 물고기를 먹으러 감.
// 먹을 수 있는 물고기가 1마리보다 많으면 거리가 가장 가까운 물고기를 먹으러 감
// 아기 상어는 공간에 몇 초 동안 있을 수 있나..
#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 21
int N, answer, minDist = 987654321;
int map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
// 상어의 시작 크기
int sharkSize = 2;
// 상어가 현재 몇 마리 먹었는지
int eatCnt;
// 물고기 유무
bool fish;
struct coor
{
    int x;
    int y;
    int dist;
};

void bfs(int start_x, int start_y)
{
    minDist = 987654321;
    queue<coor> q;
    q.push({start_x, start_y, 0});
    while (!q.empty())
    {
        int current_x = q.front().x;
        int current_y = q.front().y;
        int current_dist = q.front().dist;
        visited[current_x][current_y] = current_dist;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            // visited[next_x][next_y] 의 이유 --> 계속 왔다갔다 할 수 있으니까 거리를 갱신할 때 이미 지나온 곳은 0 대신 다른 숫자 일 것이고 이러면 true 이기 때문에 continue
            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N || visited[next_x][next_y] || map[next_x][next_y] > sharkSize)
                continue;
            if (map[next_x][next_y] != 0 && map[next_x][next_y] < sharkSize)
            {
                // 물고기를 먹을 수 있는 곳
                if (map[next_x][next_y] > 0)
                    map[next_x][next_y] *= -1;
                minDist = min(minDist, current_dist + 1);
                fish = true;
                q.push({next_x, next_y, current_dist + 1});
                visited[next_x][next_y] = current_dist + 1;
            }
            if (map[next_x][next_y] == 0 || map[next_x][next_y] == sharkSize)
            {
                // 지나는 갈 수 있는 곳
                q.push({next_x, next_y, current_dist + 1});
                visited[next_x][next_y] = current_dist + 1;
            }
        }
    }
}

int main()
{
    fastio;
    int flag = 0;
    // 상어의 시작 좌표
    int start_x, start_y;
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                start_x = i;
                start_y = j;
                map[i][j] = 0;
            }
        }

    while (1)
    {
        visited[start_x][start_y] = 0;
        bfs(start_x, start_y);
        if (!fish)
            break;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                // 먹을 수 있는 물고기를 전부 음수로 바꿔놨다.
                // 그리고 거리의 최소값을 만들어 놨기 때문에 가장 가까운 위치에 있는 물고기에게 찾아갈 수 있다.
                if (visited[i][j] == minDist && map[i][j] < 0)
                {

                    start_x = i;
                    start_y = j;
                    map[i][j] = 0;
                    answer += minDist;
                    eatCnt++;
                    if (eatCnt == sharkSize)
                    {
                        eatCnt = 0;
                        sharkSize++;
                    }
                    flag = 1; // 물고기를 먹었으니 이제 이 반복문을 탈출하기 위함
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        flag = 0;
        fish = false;
        memset(visited, 0, sizeof(visited));
    }
    cout << answer << "\n";
    return 0;
}