// N과 M (6) S3
// 백트래킹
// N 개의 자연수가 주어질 때, 조합
#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 14
using namespace std;
int N, M;
int arr[MAX_SIZE];
int result[MAX_SIZE];
bool visited[MAX_SIZE];
void func(int startNum, int cur)
{
    if (cur == M)
    {
        for (int i = 0; i < M; i++)
            cout << result[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = startNum; i <= N; i++)
    {
        if (!visited[i] && arr[i] != 0)
        {
            visited[i] = true;
            result[cur] = arr[i];
            func(i + 1, cur + 1);
            visited[i] = false;
        }
    }
}
int main()
{
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    func(0, 0);
}