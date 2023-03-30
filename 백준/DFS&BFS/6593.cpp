// 상범 빌딩 G5
// 그래프 이론, bfs, 3차원
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