// 연산자 끼워넣기 S1
// 브루트포스, 백트래킹
// 연산자를 어떻게 끼워넣어도 항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과가 나오는 입력만 주어진다.
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int N;
long long maxVal = -1000000000;
long long minVal = 1000000000;
vector<int> numVec;
int op[4];
void Calculate(int cnt, int result)
{
    if (N == cnt)
    {
        if (minVal > result)
            minVal = result;
        if (maxVal < result)
            maxVal = result;
        return;
    }
    if (op[0] != 0)
    {
        op[0] -= 1;
        int newVal = result + numVec[cnt];
        Calculate(cnt + 1, newVal);
        op[0]++;
    }
    if (op[1] != 0)
    {
        op[1] -= 1;
        int newVal = result - numVec[cnt];
        Calculate(cnt + 1, newVal);
        op[1]++;
    }
    if (op[2] != 0)
    {
        op[2] -= 1;
        int newVal = result * numVec[cnt];
        Calculate(cnt + 1, newVal);
        op[2]++;
    }
    if (op[3] != 0)
    {
        op[3] -= 1;
        int newVal = result / numVec[cnt];
        Calculate(cnt + 1, newVal);
        op[3]++;
    }
}
int main()
{
    fastio;
    cin >> N;
    numVec.resize(N);
    for (int i = 0; i < N; i++)
        cin >> numVec[i];

    for (int i = 0; i < 4; i++)
        cin >> op[i];

    Calculate(1, numVec[0]);

    cout << maxVal << "\n"
         << minVal << "\n";
}