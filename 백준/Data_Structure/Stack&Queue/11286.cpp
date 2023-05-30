// 절댓값 힙 S1
// 자료 구조, 우선순위 큐
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

struct comp
{
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;
        else
            return abs(a) > abs(b);
    }
};

void Solution(int n)
{
    priority_queue<int, vector<int>, comp> pq;

    while (n--)
    {
        int command;
        cin >> command;

        if (command == 0)
        {
            if (pq.empty())
            {
                cout << '0' << '\n';
            }
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
            pq.push(command);
    }
}

int main()
{
    fastio;
    int n;
    cin >> n;
    Solution(n);

    return 0;
}