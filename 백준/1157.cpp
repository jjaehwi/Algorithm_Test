// 단어 공부 B1
// 구현, 문자열
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int main()
{
    fastio;
    int maxCnt = 0, checkCnt = 0, idx = 0;
    string s;
    vector<int> v(26);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] <= 90 && s[i] >= 65)
            v[s[i] - 65]++;

        else
            v[s[i] - 97]++;
    }

    for (int i = 0; i < 26; i++)
        if (v[i] > maxCnt)
        {
            maxCnt = v[i];
            idx = i;
        }

    for (int i = 0; i < 26; i++)
        if (maxCnt == v[i])
            checkCnt++;

    if (checkCnt == 1)
        cout << (char)(idx + 65);
    else
        cout << "?";
}