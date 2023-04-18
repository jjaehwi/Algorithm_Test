// 비밀번호 발음하기 S5
// 구현, 문자열

// 1단계 : 모음 (a,e,i,o,u) 하나 포함
// 2단계 : 모음 3개 , 자음 3개 연속 x
// 3단계 : 같은 글자 2개 연속 x, ee 와 oo 만 가능

#include <iostream>
#include <cstring>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

bool checkStr(string str)
{
    bool flag = false; // 적어도 하나의 모음이 포함되는지 확인
    int ja = 0;        // 연속되는 자음
    int mo = 0;        // 연속되는 모음

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            flag = true;
            mo++;
            ja = 0;
        }
        else
        {
            ja++;
            mo = 0;
        }
        // 3 번 조건
        if (i >= 1 && str[i - 1] == str[i] && !(str[i] == 'e' || str[i] == 'o'))
            return false;
        // 2 번 조건
        if (ja == 3 || mo == 3)
            return false;
    }
    // 1 번 조건
    if (!flag)
        return false;

    return true;
}

int main()
{
    fastio;
    string str;
    while (1)
    {
        cin >> str;
        if (str == "end")
            break;

        if (checkStr(str))
            cout << "<" << str << ">"
                 << " is acceptable.\n";
        else
            cout << "<" << str << ">"
                 << " is not acceptable.\n";
    }
}