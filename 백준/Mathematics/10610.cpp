// 30 S4
// 수학, 문자열, 그리디, 정수론
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end(), greater<>());
    if (s[s.length() - 1] != '0')
        cout << -1;
    else
    {
        long long sum = 0;
        for (auto o : s)
        {
            sum += o - '0';
        }
        if (sum % 3 == 0)
            cout << s;
        else
            cout << -1;
    }
}