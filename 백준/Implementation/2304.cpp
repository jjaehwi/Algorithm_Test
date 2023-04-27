// 창고 다각형 S2
// 브루트포스, 구현
#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1001
int n, res = 0;
int arr[MAX_SIZE];
int max_height, max_pos;
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int pos, height;
        cin >> pos >> height;
        arr[pos] = height;
        if (max_height < height)
        {
            max_height = height;
            max_pos = pos;
        }
    }

    int left_max = 0;
    int right_max = 0;

    for (int i = 0; i < max_pos; i++)
    {
        if (arr[i] > left_max)
            left_max = arr[i];
        res += left_max;
    }

    for (int i = MAX_SIZE - 1; i > max_pos; i--)
    {
        if (arr[i] > right_max)
            right_max = arr[i];
        res += right_max;
    }
    res += max_height;

    cout << res;
}