// 구간합 구하기 5 dp
#include <iostream>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1502

int N, M;
int v[MAX_SIZE][MAX_SIZE];
int s[MAX_SIZE][MAX_SIZE];

void dp()
{
    // row/col 이 1일 때를 각각 계산
    // for (int row = 2; row <= N; row++)
    //     s[row][1] = s[row - 1][1] + v[row][1];
    // for (int col = 2; col <= N; col++)
    //     s[1][col] = s[1][col - 1] + v[1][col];

    // 실제 점화식 돌리기
    for (int col = 1; col <= N; col++)
        for (int row = 1; row <= N; row++)
            s[row][col] = s[row - 1][col] + s[row][col - 1] - s[row - 1][col - 1] + v[row][col];
}

int main()
{
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> v[i][j];
        }
    // dp[row][col] 은 자기보다 앞에 있는 값들의 합
    // (row-1, col), (row, col-1) 한거를 더해주면 됨

    // 문제 1. 초기화를 어떻게 해줘야하는가?
    // -> row가 1일때, col이 1일때는 그냥 row-1, col-1 없이 계산해주면 됨
    // -> 어차피 row가 0 일때, col이 0일때는 다 0으로 되어있으므로 (입력을 1부터 받았으니)
    // -> 그냥 둬도 된다. 단 0부터 시작할 땐 따로 해줘야한다.

    // 문제 2. 대각선 왼쪽 위가 중복으로 빠지지 않는 가?
    // -> 그래서 위 두 개를 뺀 후, (row-1, col-1)을 더해줘야한다.
    s[1][1] = v[1][1];
    // 실제 점화식 돌리기
    dp();
    // 중간에 있는 녀석을 빼려면 어떻게 해야하는가
    // 동일 row 범위 왼쪽 끝 col-1을 빼면, 왼쪽 범위를 다 날릴 수 있다.
    // 동일 col 범위 위쪽 끝 row-1을 빼면, 위쪽 범위를 다 날릴 수 있다.
    // 단, 이렇게 될 경우 왼쪽 위 대각선 부분을 두번 빼는 셈이 되므로
    // 이 부분을 다시 더해주면 된다.
    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2, result;
        cin >> x1 >> y1 >> x2 >> y2;
        result = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
        cout << result << "\n";
    }
}
// for (int i = 0; i < m; i++)
// {
//     int x1, y1, x2, y2;
//     cin >> x1 >> y1 >> x2 >> y2;

//     int result = dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1];
//     cout << result << "\n";
// }

/*
시간초과 코드
// 구간합 구하기 5 dp
#include <iostream>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 2500

int N, M;
int v[MAX_SIZE][MAX_SIZE];
int s[MAX_SIZE][MAX_SIZE];

void dp(int x1, int y1, int x2, int y2)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            s[i][j] = s[i][j - 1] + v[i][j];
        }
    }
}

int main()
{
    fastio;
    int num;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> v[i][j];
        }

    for (int i = 0; i < M; i++)
    {
        s[i][0] = v[i][0];
        for (int i = 0; i <= N; i++)
            for (int j = 1; j <= N; j++)
                s[i][j] = 0;

        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        dp(x1, y1, x2, y2);
        long long sum = 0;
        if (x1 == x2 && y1 == y2)
            sum = s[x1][y2] - s[x1][y1 - 1];
        else
        {
            for (int i = x1; i <= x2; i++)
                sum += s[i][y2] - s[i][y1 - 1];
        }
        cout << sum << "\n";
    }
}
*/