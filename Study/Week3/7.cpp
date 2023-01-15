// 백준 1439번 S5
// 그리디
#include <iostream>
#include <string>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

using namespace std;

int main()
{
    fastio;
    string s;
    cin >> s;
    int len, zero = 0, one = 0;
    len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] != s[i + 1])
        {
            if (s[i] == '0')
                zero++;
            if (s[i] == '1')
                one++;
        }
    }
    cout << min(zero, one);
}
