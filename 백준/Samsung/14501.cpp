#include <iostream>
using namespace std;

#define MAX 16

int N;
int Ti[MAX] = {
    0,
};
int Pi[MAX] = {
    0,
};
int res[MAX] = {
    0,
};

int Max(int a, int b)
{
    return a > b ? a : b;
}

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> Ti[i] >> Pi[i];
    }
}

void Dp()
{
    int deadline;
    for (int i = N; i > 0; i--)
    {
        deadline = i + Ti[i];
        if (deadline > N + 1)
        {
            // 상담 불가
            res[i] = res[i + 1];
        }
        else
        {
            // 상담 가능, 최대 이익 판별 필요
            res[i] = Max(res[i + 1], res[deadline] + Pi[i]);
        }
    }
}

int main()
{
    Input();
    Dp();

    cout << res[1] << endl;
    return 0;
}