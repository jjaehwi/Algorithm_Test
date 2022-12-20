#include <iostream>
using namespace std;
int main()
{
    int h, w, n, l, d, x, y;
    cin >> h >> w;
    cin >> n;
    // 2차원 배열 만들기
    int **arr;
    arr = new int *[h];
    for (int i = 0; i < h; i++)
        arr[i] = new int[w];

    // 막대 입력 받고 배치하기
    for (int i = 0; i < n; i++)
    {
        cin >> l >> d >> x >> y;
        if (d == 0)
            for (int j = 0; j < l; j++)
                arr[x - 1][y + j - 1] = 1;
        if (d == 1)
            for (int j = 0; j < l; j++)
                arr[x + j - 1][y - 1] = 1;
    }

    // 2차원 배열 출력하기
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}