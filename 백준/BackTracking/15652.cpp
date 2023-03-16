// N과 M (4) S3
// 백트래킹
// 중복순열, 시작 숫자보다 크거나 같게
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 9
int N, M;
int arr[MAX_SIZE];
void func(int startNum, int cur)
{
    if (cur == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = startNum; i <= N; i++)
    {
        arr[cur] = i;
        func(i, cur + 1);
    }
}
int main()
{
    fastio;
    cin >> N >> M;
    func(1, 0);
}