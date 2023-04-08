// 달팽이 숫자 D2
// 구현
#include <iostream>
#include <cstring>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 10
int T, N;
int map[MAX_SIZE][MAX_SIZE];
// 0 = 오른쪽, 1 = 아래, 2 = 왼쪽, 3 = 위쪽
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main()
{
    fastio;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        memset(map, 0, sizeof(map));
        cin >> N;
        int current_x = 0;
        int current_y = 0;
        int current_dir = 0;
        map[0][0] = 1;
        int numCnt = 2;
        int size = N * N;
        while (size >= numCnt)
        {
            int next_x = current_x + dx[current_dir];
            int next_y = current_y + dy[current_dir];

            // 범위를 벗어나려고 하면 방향을 바꿈
            if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N || map[next_x][next_y] > 0)
            {
                current_dir++;
                if (current_dir == 4)
                    current_dir = 0;
                continue;
            }
            map[next_x][next_y] = numCnt;
            current_x = next_x;
            current_y = next_y;
            numCnt++;
        }
        cout << "#" << t << "\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << map[i][j] << " ";
            cout << "\n";
        }
    }
}