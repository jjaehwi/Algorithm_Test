// 배열 복원하기 S3
// 시뮬레이션, 구현

#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 601

int H, W, X, Y;
int arr[MAX_SIZE][MAX_SIZE];

void solve()
{
    for (int i = X; i < H; i++)
        for (int j = Y; j < W; j++)
            arr[i][j] -= arr[i - X][j - Y];

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}
int main()
{
    cin >> H >> W >> X >> Y;
    for (int i = 0; i < H + X; i++)
        for (int j = 0; j < W + Y; j++)
            cin >> arr[i][j];

    solve();
    return 0;
}