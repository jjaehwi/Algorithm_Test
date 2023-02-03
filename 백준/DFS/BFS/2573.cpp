// 빙산 G4
// 그래프 탐색, bfs
#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>
using namespace std;
#define MAX_SIZE 300
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int map[MAX_SIZE][MAX_SIZE];
int updateMap[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int N, M, year, zone;
queue<pair<int, int>> q;
queue<pair<int, int>> q2;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs()
{

    while (!q.empty())
    {
        int current_x = q.front().first;
        int current_y = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            if (map[next_x][next_y] == 0)
            {
                updateMap[current_x][current_y]--;
                // 0 보다 작아질 순 없으므로
                if (updateMap[current_x][current_y] < 0)
                    updateMap[current_x][current_y] = 0;
            }
        }
    }
}
void bfs2()
{ // bfs 들어갈 때마다 덩이 증가
    zone++;
    // cout << "\nbfs2 진입\n";
    while (!q2.empty())
    {
        int current_x = q2.front().first;
        int current_y = q2.front().second;
        // cout << current_x << " " << current_y << " , ";
        q2.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            if (map[next_x][next_y] != 0 && !visited[next_x][next_y])
            {
                visited[next_x][next_y] = true;
                q2.push(make_pair(next_x, next_y));
            }
        }
    }
}
bool check()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (map[i][j] != 0)
                return false;
    // 전부 0 이면 다 녹은 것
    return true;
}
int main()
{
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            updateMap[i][j] = map[i][j];
        }

    // year를 늘려가면서,, 빙하를 지워야한다. 0 과 맞닿은 면의 수 만큼

    while (1)
    {
        year++;
        zone = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {

                if (map[i][j] != 0)
                {
                    q.push(make_pair(i, j));
                    bfs();
                }
            }
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                map[i][j] = updateMap[i][j];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (map[i][j] != 0 && !visited[i][j])
                {
                    visited[i][j] = true;
                    q2.push(make_pair(i, j));
                    bfs2();
                }
            }
        }
        // cout << "현재 map 상황\n";
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < M; j++)
        //     {
        //         cout << map[i][j];
        //     }
        //     cout << "\n";
        // }
        memset(visited, false, sizeof(visited));
        // 덩이가 2개 이상이면 반복문 탈출
        if (zone >= 2)
            break;
        // 만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.
        if (check())
        {
            year = 0;
            break;
        }
    }
    cout << year;
}