// 단어의 개수 B2
// 문자열, 구현
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    // 공백을 포함한 문자열 받기
    getline(cin, s);
    int count = 0;
    if (s.empty())
    {
        cout << "0";
        return 0;
    }
    count = 1;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ' ')
            count++;

    // 처음이 공백인 경우
    if (s[0] == ' ')
        count--;

    // 끝이 공백인 경우
    if (s[s.size() - 1] == ' ')
        count--;

    cout << count;
    return 0;
}