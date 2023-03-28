// 토마토 G5
// 그래프 탐색, bfs
#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define MAX_SIZE 101

// 3차원 배열
int N, M, H;
int tomato[MAX_SIZE][MAX_SIZE][MAX_SIZE];

int dx[] = {-1, 1, 0, 0, 0, 0}; // 앞 뒤
int dy[] = {0, 0, -1, 1, 0, 0}; // 좌 우
int dz[] = {0, 0, 0, 0, 1, -1}; // 상 하
void bfs()
{
    queue<pair<pair<int, int>, int>> q; // 3개 저장. first.first, first.second, second
    for (int h = 1; h <= H; h++)
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                if (tomato[h][i][j] == 1)
                    q.push(make_pair(make_pair(h, i), j));
    while (!q.empty())
    {
        int row, col, height;
        height = q.front().first.first;
        col = q.front().first.second;
        row = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int next_height = height + dz[i];
            int next_col = col + dx[i];
            int next_row = row + dy[i];

            if (next_height >= 1 && next_col >= 1 && next_row >= 1 && next_height <= H && next_col <= M && next_row <= N && tomato[next_height][next_col][next_row] == 0)
            {
                q.push(make_pair(make_pair(next_height, next_col), next_row));
                tomato[next_height][next_col][next_row] = tomato[height][col][row] + 1;
            }
        }
    }
}
int main()
{
    scanf("%d %d %d", &N, &M, &H);
    for (int h = 1; h <= H; h++)
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                scanf("%d", &tomato[h][i][j]);

    bfs();

    int answer = 1;
    for (int h = 1; h <= H; h++)
    {
        for (int i = 1; i <= M; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (tomato[h][i][j] == 0)
                {
                    answer = -1;
                    break;
                }
                if (tomato[h][i][j] > answer)
                    answer = tomato[h][i][j];
            }
            if (answer == -1)
                break;
        }
        if (answer == -1)
            break;
    }
    if (answer == -1)
        printf("%d", answer);
    else
        printf("%d", answer - 1);
    return 0;
}