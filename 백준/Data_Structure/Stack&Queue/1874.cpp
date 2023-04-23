// 스택 수열 S2
// 자료 구조, 스택
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int n;
stack<int> s;
vector<char> v;
int main()
{
    fastio;
    int cnt = 1;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        for (; cnt <= num; cnt++)
        {
            s.push(cnt);
            v.push_back('+');
        }
        if (s.top() == num)
        {
            s.pop();
            v.push_back('-');
        }
        else
        {
            cout << "NO\n";
            return 0;
        }
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
}