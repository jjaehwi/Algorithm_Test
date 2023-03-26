// 극장 S1
// dp
#include <iostream>

#define endl "\n"
#define MAX 45
using namespace std;

int N, M;
int DP[MAX];
int Vip[MAX];

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> Vip[i];
}

void Solution()
{
    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 2;
    for (int i = 3; i <= N; i++)
        DP[i] = DP[i - 1] + DP[i - 2];

    int Answer = 1;
    int Start = 0;
    for (int i = 0; i < M; i++)
    {
        int End = Vip[i];
        Answer = Answer * DP[End - Start - 1];
        Start = End;
    }
    Answer = Answer * DP[N - Start];
    cout << Answer << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}
