// 사탕 게임 S2
// 브루트 포스, 구현

/*
시간 복잡도 : O(N^2)
행을 기준으로 swap
열을 기준으로 swap

가장 큰 값을 저장하고 있다가 갱신
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 51
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
char map[MAX_SIZE][MAX_SIZE];
int n, answer;

// 연속되는 가장 큰 행/열 계산
void check()
{
    char c;
    // 행 계산
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        c = map[i][0];
        for (int j = 1; j < n; j++)
        {
            if (map[i][j] == c)
                count++;
            else
                count = 1;
            c = map[i][j];

            answer = max(answer, count);
        }
    }

    // 열 계산
    for (int j = 0; j < n; j++)
    {
        int count = 1;
        c = map[0][j];
        for (int i = 1; i < n; i++)
        {
            if (map[i][j] == c)
                count++;
            else
                count = 1;
            c = map[i][j];

            answer = max(answer, count);
        }
    }
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    // 행 기준
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
        {
            swap(map[i][j], map[i][j + 1]);
            check();
            swap(map[i][j], map[i][j + 1]);
        }
    // 열 기준
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n - 1; i++)
        {
            swap(map[i][j], map[i + 1][j]);
            check();
            swap(map[i][j], map[i + 1][j]);
        }

    cout << answer;
}