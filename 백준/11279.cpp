#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int> max; // 최대힙
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long long num;
        cin >> num;
        if (num == 0)
        {
            if (max.empty())
            {
                cout << "0\n";
                continue;
            }
            cout << max.top() << "\n";
            max.pop();
        }
        else
            max.push(num);
    }
}
