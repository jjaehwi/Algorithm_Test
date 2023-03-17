// N과 M (7)
// 백트래킹
// N 개의 자연수가 주어질 때, 중복 순열
#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 8
int arr[MAX_SIZE];
int result[MAX_SIZE];
bool visited[MAX_SIZE];
int N, M;
void func(int cur)
{
    if (cur == M)
    {
        for (int i = 0; i < M; i++)
            cout << result[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; i++)
    {
        result[cur] = arr[i];
        func(cur + 1);
    }
}
int main()
{
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    func(0);
}
