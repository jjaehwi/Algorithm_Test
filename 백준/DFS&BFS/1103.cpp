// 게임 G2
// dp, 그래프 이론, dfs
/*
보드게임 같은 문제를 만나면 보드의 가로 세로 길이를 유심히 봐야한다. 500 정도가 넘어가면 매우 어려워진다.
dfs 가 어울리는 이유 --> 끝까지 한번 가보고 안되면 되돌아오고.. 이런 방식
*/
#include <iostream>
#include <memory.h>
using namespace std;
int N, M;
bool checkInf = false;
// 상하좌우
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char board[51][51];
int map[51][51];
int dp[51][51];
int check[51][51];
int dfs(int x, int y)
{
    if (checkInf)
        return 0;

    if (x < 0 || y < 0 || x > N || y > M || map[x][y] == 0)
        return 0;

    if (check[x][y] == 1)
    {
        checkInf = true;
        return 0;
    }

    if (dp[x][y] != -1)
        return dp[x][y];

    check[x][y] = 1;
    dp[x][y] = 0;

    for (int i = 0; i < 4; i++)
    {
        int x2 = x + (map[x][y] * dx[i]);
        int y2 = y + (map[x][y] * dy[i]);
        dp[x][y] = max(dp[x][y], dfs(x2, y2) + 1);
    }

    check[x][y] = 0;
    return dp[x][y];
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            // H 만나면 0으로 초기화
            if (board[i][j] == 'H')
                map[i][j] = 0;
            // H가 아닌 경우 정수 값으로
            else
                map[i][j] = board[i][j] - '0';
        }
    }
    memset(dp, -1, sizeof(dp));
    int result = dfs(0, 0);
    if (checkInf)
        cout << -1;
    else
        cout << result;
}