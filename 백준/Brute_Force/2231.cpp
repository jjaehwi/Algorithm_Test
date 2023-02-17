// 분해 합 B2
// 브루트 포스
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int main()
{
    fastio;
    int num, partNum, sum;
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        partNum = i;
        sum = i;
        while (partNum)
        {
            sum += partNum % 10;
            partNum /= 10;
        }
        if (sum == num)
        {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}