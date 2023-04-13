// 스택 S4
// 자료구조, 스택
#include <iostream>
#include <string>
using namespace std;
int s = 0;
int stack[10001];

void push(int num)
{
    stack[s] = num;
    s++;
}

int pop()
{
    if (s == 0)
        return -1;
    int num = stack[s - 1];
    s--;
    return num;
}

int size()
{
    return s;
}

int empty()
{
    if (s == 0)
        return 1;
    else
        return 0;
}

int top()
{
    if (s == 0)
        return -1;
    return stack[s - 1];
}

int main()
{
    int n;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "push")
        {
            int num;
            cin >> num;
            push(num);
        }
        if (str == "pop")
        {
            cout << pop() << "\n";
        }
        if (str == "size")
        {
            cout << size() << "\n";
        }
        if (str == "empty")
        {
            cout << empty() << "\n";
        }
        if (str == "top")
        {
            cout << top() << "\n";
        }
    }
}