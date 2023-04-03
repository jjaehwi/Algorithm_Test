// 상범 빌딩 G5
// 그래프 이론, bfs, 3차원
#include <iostream>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 32
int L, R, C;
string str;
char map[MAX_SIZE][MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE];
struct building
{
    int x;
    int y;
    int z;
    int time;
};

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int stateVal;

int bfs(int start_x, int start_y, int start_z, int start_time)
{
    queue<building> q;
    q.push({start_x, start_y, start_z, start_time});
    while (!q.empty())
    {
        building current = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            int nz = current.z + dz[i];
            if (nx < 0 || nx > L - 1 || ny < 0 || ny > R - 1 || nz < 0 || nz > C - 1)
                continue;
            if (map[nx][ny][nz] == 'E')
            {
                cout << "Escaped in " << current.time + 1 << " minute(s).\n";
                return 1;
            }
            if (map[nx][ny][nz] == '.' && visited[nx][ny][nz] == false)
            {
                q.push({nx, ny, nz, current.time + 1});
                visited[nx][ny][nz] = true;
            }
        }
    }
    return -1;
}

int main()
{
    fastio;
    while (1)
    {
        int start_x, start_y, start_z;
        stateVal = 0;
        memset(visited, false, sizeof(visited));
        cin >> L >> R >> C;
        if (L == 0 or R == 0 or C == 0)
            break;

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                cin >> str;
                for (int k = 0; k < C; k++)
                {
                    map[i][j][k] = str[k];
                    if (map[i][j][k] == 'S')
                    {
                        start_x = i;
                        start_y = j;
                        start_z = k;
                        visited[i][j][k] = true;
                    }
                }
            }
        }
        stateVal = bfs(start_x, start_y, start_z, 0);
        if (stateVal == -1)
            cout << "Trapped!\n";
    }
}

/*
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Que
{
    int x;
    int y;
    int z;
    int time;
};

char board[32][32][32];
bool vis[32][32][32];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main()
{

    while (1)
    {
        int L, R, C;
        string str;
        queue<Que> Q;
        cin >> L >> R >> C;

        if (L == 0 or R == 0 or C == 0)
            break;

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                cin >> str;
                for (int k = 0; k < C; k++)
                {
                    board[i][j][k] = str[k];
                    if (board[i][j][k] == 'S')
                    {
                        Q.push({i, j, k, 0});
                        vis[i][j][k] = true;
                    }
                }
            }
        }

        while (!Q.empty())
        {
            auto cur = Q.front();
            Q.pop();
            for (int i = 0; i < 6; i++)
            {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                int nz = cur.z + dz[i];
                if (nx < 0 or nx > L - 1 or ny < 0 or ny > R - 1 or nz < 0 or nz > C - 1)
                    continue;
                if (board[nx][ny][nz] == 'E')
                {
                    cout << "Escaped in " << cur.time + 1 << " minute(s)." << endl;
                    goto ijsilver;
                }
                if (board[nx][ny][nz] == '.' and vis[nx][ny][nz] == false)
                {
                    Q.push({nx, ny, nz, cur.time + 1});
                    vis[nx][ny][nz] = true;
                }
            }
        }

        cout << "Trapped!" << endl;

    ijsilver:;

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                {

                    vis[i][j][k] = false;
                }
            }
        }
    }
}
*/