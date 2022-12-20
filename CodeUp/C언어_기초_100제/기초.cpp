#include <iostream>
using namespace std;

int arr[11][11];

void backtrack(int x, int y)
{
    if (arr[x][y] == 2)
    {
        arr[x][y] = 9;
        return;
    }
    arr[x][y] = 9;

    if (arr[x][y + 1] != 1)
        backtrack(x, y + 1);
    else if (arr[x + 1][y] != 1)
        backtrack(x + 1, y);
}

int main()
{
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
            cin >> arr[i][j];
    }

    backtrack(2, 2);

    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}