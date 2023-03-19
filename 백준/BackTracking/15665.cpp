// N과 M (11) S2
// 백트래킹
// N 개의 자연수가 중복으로 주어질 때, 중복되는 수열을 여러 번 출력 x
// N개의 자연수 중에서 M개를 고른 수열
// 같은 수를 여러 번 골라도 된다. --> 중복 체크할 배열이 없어도 된다.
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 8
int n, m, arr[MAX_SIZE], res[MAX_SIZE]; // arr : 입력받은 수열, res : 길이m인 수열(출력)
void func(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << res[i] << " ";
        cout << "\n";
        return;
    }
    int xx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != xx)
        {
            res[cnt] = arr[i];
            xx = res[cnt];
            func(cnt + 1);
        }
    }
}
int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    func(0);
}