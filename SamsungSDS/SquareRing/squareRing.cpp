#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int T, N;
    int count, maxCount = 0;
    cin >> T;
    for (int k = 0; k < T; k++)
    {
        vector<int> v;
        vector<int> s;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        do
        {
            for (int j = 0; j < N; j++)
            {
                if (j == N - 1)
                {
                    int sum = v[j] + v[0];
                    int sqrt_sum = (int)sqrt(sum);
                    if (sqrt_sum * sqrt_sum == sum)
                        count++;
                }
                if (j < N - 1)
                {
                    int sum = v[j] + v[j + 1];
                    int sqrt_sum = (int)sqrt(sum);
                    if (sqrt_sum * sqrt_sum == sum)
                        count++;
                }
            }

            if (count > maxCount)
                maxCount = count;
            count = 0;
        } while (next_permutation(v.begin(), v.end()));
        cout << "#" << k + 1 << " " << maxCount << endl;
        maxCount = 0;
    }
}
