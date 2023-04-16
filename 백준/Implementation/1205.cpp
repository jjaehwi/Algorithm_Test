// 등수 구하기 S4
// 구현
#include <iostream>
#include <cstring>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int N, newScore, P;
int main()
{
    fastio;
    cin >> N >> newScore >> P;
    int arr[P - 1];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int cnt = 0;
    int my_rank = 1;
    for (int i = 0; i < N; i++)
    {
        if (newScore < arr[i])
            my_rank += 1;
        else if (newScore == arr[i])
            my_rank = my_rank;
        else
            break;
        cnt++;
    }
    if (cnt == P)
        my_rank = -1;
    if (N == 0)
        my_rank = 1;

    cout << my_rank;
}