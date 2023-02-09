// 테트리스 G4
// 구현, dfs
#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 501
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int N, M;
int max_value;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void findMax_T_Shape(int x, int y)
{
    // ㅗ 모양
    if (x - 1 >= 1 && y + 2 <= M)
        max_value = max(max_value, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x - 1][y + 1]);
    // ㅜ 모양
    if (x + 1 <= N && y + 2 <= M)
        max_value = max(max_value, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1]);
    // ㅓ 모양
    if (x + 2 <= N && y - 1 >= 1)
        max_value = max(max_value, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y - 1]);
    // ㅏ 모양
    if (x + 2 <= N && y + 1 <= M)
        max_value = max(max_value, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1]);
}

void findMax_OtherShape(int x, int y, int cnt, int sum)
{
    if (cnt == 3)
    {
        max_value = max(max_value, sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > N || ny < 1 || ny > M)
            continue;
        if (visited[nx][ny])
            continue;
        visited[nx][ny] = true;
        findMax_OtherShape(nx, ny, cnt + 1, sum + map[nx][ny]);
        visited[nx][ny] = false;
    }
}

void findMax(int x, int y)
{
    findMax_T_Shape(x, y);
    visited[x][y] = true;
    findMax_OtherShape(x, y, 0, map[x][y]);
    visited[x][y] = false;
}
int main()
{
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> map[i][j];

    // 모든 점 마다 테트로미노 합 최대값 찾기
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            findMax(i, j);
    cout << max_value;
}