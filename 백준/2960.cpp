#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

using namespace std;

int N, K;

int main()
{
    fastio;
    cin >> N >> K;
    vector<int> v(N + 1);
    vector<int> order;
    for (int i = 2; i <= N; i++)
        v[i] = i;

    for (int i = 2; i <= N; i++)
    {
        if (v[i] == 0)
            continue;
        for (int j = i; j <= N; j += i)
        {
            if (v[j] == 0)
                continue;
            order.push_back(v[j]);
            v[j] = 0;
        }
    }
    cout << order[K - 1];
}