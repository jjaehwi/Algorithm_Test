// N과 M (2) S3
// 백트래킹, next_permutation
// 서로 다른 n개에서 r개를 뽑는 조합
// 중복 없이 조합 nCm

#include <iostream>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 14
using namespace std;
int N, M;
int arr[MAX_SIZE];
bool issued[MAX_SIZE];

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
        if (!issued[i])
        {
            issued[i] = true;
            arr[cur] = i;
            // 재귀 호출에서, 현재 뽑은 원소의 이전값들은 고려하지 않게끔, for문의 i값을 함께 넘겨준다.
            func(i + 1, cur + 1);
            issued[i] = false;
        }
    }
}

int main()
{
    fastio;
    cin >> N >> M;
    func(1, 0);
}

/*
// next_permutation 풀이

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int main()
{
    cin >> N >> M;
    vector<int> a(N, 1);
    for (int i = 0; i < M; i++)
        a[i] = 0;
    // for (int i = 0; i < N; i++)
    //     cout << a[i] << " ";
    // cout << "\n";
    do
    {
        for (int i = 0; i < N; i++)
        {
            if (a[i] == 0)
                cout << i + 1 << " ";
        }
        cout << "\n";
    } while (next_permutation(a.begin(), a.end()));
}
*/