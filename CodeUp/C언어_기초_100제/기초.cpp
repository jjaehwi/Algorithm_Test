#include <iostream>
using namespace std;

int arr[20][20];

int main()
{
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j < 20; j++)
            cin >> arr[i][j];
    }

    int n;
    cin >> n;

    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        for (int j = 1; j < 20; j++)
            arr[x][j] = !arr[x][j];
        for (int j = 1; j < 20; j++)
            arr[j][y] = !arr[j][y];
    }

    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j < 20; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}