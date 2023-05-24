// 수리공 항승 S3
// 그리디, 정렬
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1001
int N, L, cnt = 1;
vector<int> pipe;
int main()
{
    fastio;
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        pipe.push_back(n);
    }
    sort(pipe.begin(), pipe.end());

    int index = 0;
    for (int i = 0; i < N; i++)
    {
        if (L >= abs(pipe[index] - pipe[i]) + 1)
            continue;
        else
        {
            cnt++;
            index = i;
        }
    }
    cout << cnt;
}