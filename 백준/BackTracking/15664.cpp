// N과 M (10) S2
// 백트래킹
// N 개의 자연수가 중복으로 주어질 때, 중복되는 수열을 여러 번 출력 x
// 고른 수열은 비내림차순이어야 한다.

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 8
int n, m, arr[MAX_SIZE], res[MAX_SIZE]; // arr : 입력받은 수열, res : 길이m인 수열(출력)
bool chk[MAX_SIZE];                     // 중복확인

void func(int startNum, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", res[i]);
        printf("\n");
        return;
    }
    int xx = 0;
    for (int i = startNum; i < n; i++)
    {
        if (!chk[i] && arr[i] != xx)
        {
            res[cnt] = arr[i];
            xx = res[cnt];
            chk[i] = true;
            func(i, cnt + 1);
            chk[i] = false;
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
    func(0, 0);
}