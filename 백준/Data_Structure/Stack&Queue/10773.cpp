// 제로 S4
// 자료구조, 구현, 스택
#include <iostream>
#include <stack>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int K, num, res;
stack<int> s;
int main()
{
    fastio;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> num;
        if (num != 0)
            s.push(num);
        else
            s.pop();
    }
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        res += s.top();
        s.pop();
    }
    cout << res;
}
