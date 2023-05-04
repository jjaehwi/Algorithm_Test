// 봄버맨 S1
// 구현, 시뮬레이션, 그래프 탐색
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 201
int R, C, N;
char map[MAX_SIZE][MAX_SIZE];
int timeBomb[MAX_SIZE][MAX_SIZE];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 폭탄 설치
void installBomb(int time)
{
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == 'O')
                continue;
            map[i][j] = 'O';
            timeBomb[i][j] = time + 3;
        }
}

// 폭탄 터짐
void boomBomb(int time)
{
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            if (timeBomb[i][j] == time)
            {
                // 본인 터짐
                map[i][j] = '.';
                timeBomb[i][j] = 0;

                // 주위 터짐
                for (int k = 0; k < 4; k++)
                {
                    int next_x = i + dx[k];
                    int next_y = j + dy[k];

                    if (next_x < 0 || next_y < 0 || next_x >= R || next_y >= C || map[next_x][next_y] == '.')
                        continue;
                    else
                    {
                        map[next_x][next_y] = '.';
                        // 동시에 터지는 것이기 때문에 만약 폭탄이 인접한다면 인접한 폭탄의 time 도 0 으로 만들기 때문에 쓰면 안된다.
                        // timeBomb[next_x][next_y] = 0;
                    }
                }
            }
        }
}
int main()
{
    fastio;
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'O')
                timeBomb[i][j] = 3;
        }

    int current_time = 2;
    while (1)
    {

        if (current_time == N + 1)
            break;

        if (current_time % 2 == 0)
            installBomb(current_time);

        else
            boomBomb(current_time);

        current_time++;
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << map[i][j];
        cout << "\n";
    }
}