// 균형잡힌 세상 S3
// 자료 구조, 문자열, 스택
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    while (true)
    {
        string input;
        getline(cin, input);

        if (input == ".")
        {
            break;
        }

        stack<char> s;
        bool flag = 0;
        for (int i = 0; i < input.length(); i++)
        {
            char c = input[i];

            if ((c == '(') || (c == '['))
            {
                s.push(c);
            }
            else if (c == ')')
            {
                if (!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
            else if (c == ']')
            {
                if (!s.empty() && s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0 && s.empty())
        {
            cout << "yes"
                 << "\n";
        }
        else
        {
            cout << "no"
                 << "\n";
        }
    }
}
