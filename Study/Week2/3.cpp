/* 백준 2580번 스도쿠 */

#include <iostream>
using namespace std;
int arr[9][9];

// 유망한지 검사하는 함수
bool promising(int x, int y, int checkNum)
{
    // 세로, 가로 검사
    for (int i = 0; i < 9; i++)
    {
        if (arr[x][i] == checkNum)
            return false;
        if (arr[i][y] == checkNum)
            return false;
    }
    // 3x3 사각형 검사
    for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)
    {
        for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
            if (arr[i][j] == checkNum)
                return false;
    }
    // 위 검사에 걸리지 않으면 true
    return true;
}

void sudoku(int x, int y)
{
    // 아래로 끝까지 내려간 경우 출력한다.
    if (x == 9)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << arr[i][j] << " ";
            cout << "\n";
        }
        exit(0);
    }
    // 옆으로 끝까지 간 경우 한 칸 아래로 내려간다.
    if (y == 9)
        sudoku(x + 1, 0);
    // 0을 만나면 유망한지 검사한다.
    if (arr[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (promising(x, y, i))
            {
                arr[x][y] = i;
                sudoku(x, y + 1);
                arr[x][y] = 0;
            }
        }
    }
    else
        sudoku(x, y + 1);
}

int main()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> arr[i][j];
    sudoku(0, 0);
    return 0;
}