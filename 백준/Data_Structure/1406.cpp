// 에디터 S2
// 자료 구조, 연결 리스트, 스택

// L --> 커서를 왼쪽으로 한 칸 옮김 (맨 앞이면 무시)
// D --> 커서를 오른쪽으로 한 칸 옮김 (맨 뒤면 무시)
// B --> 커서 왼쪽에 있는 문자를 삭제 (맨 앞이면 무시)
// 삭제하면 커서는 왼쪽으로 이동한 것 처럼 보이지만, 실제로 커서의 오른쪽에 있는 문자는 그대로임
// P $ --> $ 라는 문자를 커서 왼쪽에 추가
// 초기에 편집기에 입력되어 있는 문자열이 주어지고, 그 이후 입력한 명령어가 차례로 주어진다.
// 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 구해라
// 초기 커서는 문장의 맨 뒤
#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
string str;
int cnt;
int main()
{
    fastio;
    cin >> str;
    cin >> cnt;
    stack<char> left;
    stack<char> right;
    for (int i = 0; i < str.size(); i++)
        left.push(str[i]);

    while (cnt--)
    {
        char order;
        cin >> order;
        // P 명령 --> 왼쪽에 문자 삽입
        if (order == 'P')
        {
            char c;
            cin >> c;
            left.push(c);
        }
        // L 명령 -> 왼쪽 스택의 top 을 오른쪽 스택으로 push
        else if (order == 'L')
        {
            if (left.empty())
                continue;
            else
            {
                right.push(left.top());
                left.pop();
            }
        }
        // B 명령 --> 왼쪽 문자 삭제
        else if (order == 'B')
        {
            if (left.empty())
                continue;
            else
                left.pop();
        }
        // D 명령 --> 오른쪽 스택의 top 을 왼쪽 스택으로 push
        else if (order == 'D')
        {
            if (right.empty())
                continue;
            else
            {
                left.push(right.top());
                right.pop();
            }
        }
    }
    // 왼쪽 스택의 값을 오른쪽 스택으로 붙힘
    while (!left.empty())
    {
        right.push(left.top());
        left.pop();
    }
    // 오른쪽 스택을 출력
    while (!right.empty())
    {
        cout << right.top();
        right.pop();
    }
    return 0;
}
