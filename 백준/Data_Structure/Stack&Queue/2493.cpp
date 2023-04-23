// 탑 G5
// 자료 구조, 스택
#include <iostream>
#include <stack>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
struct laserTop
{
    int height;
    int index;
};
int N;
stack<laserTop> lt;

int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int topHeight;
        cin >> topHeight;
        while (!lt.empty())
        {
            if (topHeight < lt.top().height)
            {
                cout << lt.top().index << " ";
                break;
            }
            lt.pop();
        }
        if (lt.empty())
            cout << 0 << " ";

        lt.push({topHeight, i});
    }
}
