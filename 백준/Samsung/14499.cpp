// 주사위 굴리기 G4
// 구현, 시뮬레이션
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 21
int n, m, x, y, k;
int map[MAX_SIZE][MAX_SIZE];
int order[1001];
// index 1 윗면, 2 북쪽면, 3 동쪽면, 4 서쪽면, 5 남쪽면, 6 아랫면
vector<int> dice(7);

// 1 동쪽, 2 서쪽, 3 북쪽, 4 남쪽
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

// 동쪽으로 굴리기
void rollEast()
{
    dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
}

// 서쪽으로 굴리기
void rollWest()
{
    dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
}

// 북쪽으로 굴리기
void rollNorth()
{
    dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
}

// 남쪽으로 굴리기
void rollSouth()
{
    dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
}

// order에 따라 주사위 굴리기
void roll(int order)
{
    switch (order)
    {
    case 1:
        rollEast();
        break;
    case 2:
        rollWest();
        break;
    case 3:
        rollNorth();
        break;
    case 4:
        rollSouth();
        break;
    default:
        break;
    }
}

void solve()
{
    for (int i = 0; i < k; i++)
    {
        int nx = dx[order[i]];
        int ny = dy[order[i]];
        // 범위 넘어가면 출력 없이 통과
        if (x + nx >= n || x + nx < 0 || y + ny >= m || y + ny < 0)
            continue;
        // 다음 칸으로 이동
        x += nx;
        y += ny;
        roll(order[i]);
        cout << dice[1] << "\n"; // 굴린 뒤 윗 면 출력

        // 이동한 후 도착한 보드 칸이 0이라면 주사위 아랫면 숫자를 칸에 복사
        if (map[x][y] == 0)
            map[x][y] = dice[6];
        // 도착한 보드 칸이 0이 아니라면 칸 숫자를 주사위 아래에 복사, 이후 그 칸은 0으로 초기화
        else
        {
            dice[6] = map[x][y];
            map[x][y] = 0;
        }
    }
}

int main()
{
    fastio;
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    for (int i = 0; i < k; i++)
        cin >> order[i];
    solve();
}