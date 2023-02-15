// 부분합 G4
// 투 포인터, 누적 합
#include <iostream>
#include <vector>
using namespace std;
int N, S, sum;
int main()
{
    int index;
    cin >> N >> S;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    int start = 0, end = 0, sum = v[0], result = 100000;
    while (start <= end && start >= 0 && end < N)
    {
        if (sum >= S)
            result = min(result, (end - start + 1));
        if (sum < S)
        {
            end++;
            sum += v[end];
        }
        else
        {
            sum -= v[start];
            start++;
        }
    }
    if (result == 100000)
        cout << "0";
    else
        cout << result;
}