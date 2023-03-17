// N과 M (8)
// 백트래킹
// N 개의 자연수가 주어질 때, 중복 조합
#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 8
int arr[MAX_SIZE];
int result[MAX_SIZE];
bool visited[MAX_SIZE]; // 중복을 허용하지 않을 때 사용, 여기선 중복을 허용하므로 사용안함
int N, M;
void func(int startNum, int cur) // startNum 을 받아서 시작 값 보다 같거나 큰 것만 출력하게.. 즉, 비내림차순으로
{
    if (cur == M)
    {
        for (int i = 0; i < M; i++)
            cout << result[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = startNum; i < N; i++)
    {
        result[cur] = arr[i];
        func(i, cur + 1);
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