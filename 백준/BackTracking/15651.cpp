// N과 M (3) S3
// 백트래킹
// 서로 다른 n개에서 r개를 뽑아 배열하는 순열. nPm (N과 M(1)) 에서
// 자기 자신도 포함 가능한 중복 순열, 중복 순열 계산 nNm --> n^m
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 14

int N, M;
int arr[MAX_SIZE];

void func(int cur)
{
    if (cur == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        arr[cur] = i;
        func(cur + 1);
    }
}

int main()
{
    fastio;
    cin >> N >> M;
    func(0);
}