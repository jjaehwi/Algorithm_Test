// 에라토스테네스의 체
#include <iostream>

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
#define MAX 1000000

int arr[MAX + 1];

using namespace std;

int M, N;

int main()
{
    fastio;
    cin >> M >> N;

    for (int i = 2; i <= N; i++)
        arr[i] = i;

    for (int i = 2; i * i <= N; i++)
    {
        if (arr[i] == 0)
            continue;
        for (int j = i * i; j <= N; j += i)
            arr[j] = 0;
    }

    for (int i = M; i <= N; i++)
        if (arr[i] != 0)
            cout << arr[i] << "\n";
}