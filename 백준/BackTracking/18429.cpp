// 근손실 S3
// 브루트포스, 백트래킹
// 조합으로 키트 적용 순서를 뽑는다.
// N 일 동안 N 개의 키트
// 증가량 A
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 51
int N, K, answer;
int gain[MAX_SIZE];
bool visited[MAX_SIZE];
int weight = 500;

void dfs(int cur)
{
    if (cur == N)
        answer++;
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                if (weight + gain[i] >= 500)
                {
                    weight += gain[i];
                    dfs(cur + 1);
                    weight -= gain[i];
                    visited[i] = false;
                }
                else
                    visited[i] = false;
            }
        }
    }
}

int main()
{
    fastio;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> gain[i];
        gain[i] -= K;
    }
    dfs(0);
    cout << answer;
}