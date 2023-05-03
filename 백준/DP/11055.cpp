// 가장 큰 증가하는 부분 수열 S2
// dp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int N;
int main()
{
    fastio;
    cin >> N;
    vector<int> input(N);
    vector<int> result(N);
    for (int i = 0; i < N; i++)
        cin >> input[i];

    int maxVal = 0;
    for (int i = 0; i < N; i++)
    {
        result[i] = input[i];
        for (int j = 0; j < i; j++)
        {
            if (input[i] > input[j] && result[i] < result[j] + input[i])
                result[i] = result[j] + input[i];
        }
        maxVal = max(maxVal, result[i]);
    }
    cout << maxVal;
}