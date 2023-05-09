// 빙고 S4
// 구현, 시뮬레이션
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 5
vector<int> result;
int bingoMap[MAX_SIZE][MAX_SIZE];
bool bingoCheck[MAX_SIZE][MAX_SIZE];

void checkBingoMap(int num)
{
    for (int i = 0; i < MAX_SIZE; i++)
        for (int j = 0; j < MAX_SIZE; j++)
            if (bingoMap[i][j] == num)
                bingoCheck[i][j] = true;
}

int checkCol()
{
    int bingo = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        int check = 0;
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (bingoCheck[i][j])
                check++;
            if (check == 5)
                bingo++;
        }
    }
    return bingo;
}

int checkRow()
{
    int bingo = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        int check = 0;
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (bingoCheck[j][i])
                check++;
            if (check == 5)
                bingo++;
        }
    }
    return bingo;
}

int checkDiag()
{
    int bingo = 0;
    int check1 = 0;
    int check2 = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (bingoCheck[i][i])
            check1++;
        if (bingoCheck[i][MAX_SIZE - i - 1])
            check2++;
    }
    if (check1 == 5)
        bingo++;
    if (check2 == 5)
        bingo++;

    return bingo;
}

bool isBingo()
{
    // cout << "가로 : " << checkCol() << "\n";
    // cout << "세로 : " << checkRow() << "\n";
    // cout << "대각선 : " << checkDiag() << "\n";
    if (checkCol() + checkRow() + checkDiag() >= 3)
        return true;
    else
        return false;
}

int main()
{
    fastio;
    for (int i = 0; i < MAX_SIZE; i++)
        for (int j = 0; j < MAX_SIZE; j++)
            cin >> bingoMap[i][j];

    int k = MAX_SIZE * MAX_SIZE;
    int count = 0;
    bool flag = false;
    while (k--)
    {
        int num;
        cin >> num;
        count++;
        checkBingoMap(num);

        if (isBingo())
            result.push_back(count);
    }
    cout << result[0];
}

/*
x x o x o
o x o o x
x x o x o
x o o x x
o x o x x
*/