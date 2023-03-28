// 불! G4
// 그래프 이론, bfs
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1002
int R, C;
char miro[MAX_SIZE][MAX_SIZE];
queue<pair<int, int>> jh;
queue<pair<int, int>> fire;
int jh_visited[MAX_SIZE][MAX_SIZE];
int fire_visited[MAX_SIZE][MAX_SIZE];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs()
{
    // fire 에 대한 탐색
    while (!fire.empty())
    {
        int current_x = fire.front().first;
        int current_y = fire.front().second;
        fire.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C)
                continue;
            if (miro[next_x][next_y] == '#' || fire_visited[next_x][next_y] >= 0)
                continue;
            fire_visited[next_x][next_y] = fire_visited[current_x][current_y] + 1;
            fire.push(make_pair(next_x, next_y));
        }
    }
    // jihoon 에 대한 탐색
    while (!jh.empty())
    {
        int current_x = jh.front().first;
        int current_y = jh.front().second;
        jh.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            // 다음 x,y 좌표가 밖으로 벗어나게 된다는 것은 현재 위치가 가장자리 라는 것.
            if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C)
            {
                cout << jh_visited[current_x][current_y] + 1;
                return;
            }
            if (miro[next_x][next_y] == '#' || jh_visited[next_x][next_y] >= 0)
                continue;
            // 지훈이가 가려는 시간에 불이 퍼지면 못간다. = 불의 bfs 단계가 더 커야함.
            if (jh_visited[current_x][current_y] + 1 >= fire_visited[next_x][next_y] && fire_visited[next_x][next_y] != -1)
                continue;

            jh_visited[next_x][next_y] = jh_visited[current_x][current_y] + 1;
            jh.push(make_pair(next_x, next_y));
        }
    }
    cout << "IMPOSSIBLE";
    return;
}
int main()
{
    fastio;
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> miro[i][j];

    for (int i = 0; i < R; i++)
    {
        fill(jh_visited[i], jh_visited[i] + C, -1);
        fill(fire_visited[i], fire_visited[i] + C, -1);
    }

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            if (miro[i][j] == 'J')
            {
                jh.push(make_pair(i, j));
                jh_visited[i][j] = 0;
            }
            else if (miro[i][j] == 'F')
            {
                fire.push(make_pair(i, j));
                fire_visited[i][j] = 0;
            }
        }
    bfs();

    return 0;
}