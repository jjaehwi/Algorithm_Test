// 햄버거 S3
// 그리디
#include <iostream>
#include <cstring>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int N, K, res;
string str;
int main()
{
    fastio;
    cin >> N >> K;
    cin >> str;

    for (int i = 0; i < N; i++)
    {
        // 사람이 아니면 통과
        if (str[i] != 'P')
            continue;
        // 사람을 만난 경우 검사 진행 (제일 왼쪽에서부터)
        for (int j = i - K; j <= i + K; j++)
        {
            // 그 자리에 햄버거가 있으면
            if (j >= 0 && j < N && str[j] == 'H')
            {
                res++;
                str[j] = 'N';
                break;
            }
        }
    }
    cout << res;
}