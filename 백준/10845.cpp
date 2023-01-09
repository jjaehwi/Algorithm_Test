#include <iostream>
#include <string>
using namespace std;

int queue[10001];
int ft = 0, bk = 0;

void push(int num)
{
    queue[bk] = num;
    bk++;
}

int empty()
{
    if (ft == bk)
        return 1;
    else
        return 0;
}

int pop()
{
    if (empty() == 1)
        return -1;
    int num = queue[ft];
    queue[ft] = 0;
    ft++;
    return num;
}

int size()
{
    return bk - ft;
}

int front()
{
    if (empty() == 1)
        return -1;
    return queue[ft];
}

int back()
{
    if (empty() == 1)
        return -1;
    return queue[bk - 1];
}

int main()
{
    int N;
    string str;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        if (str == "push")
        {
            int num;
            cin >> num;
            push(num);
        }
        if (str == "pop")
            cout << pop() << "\n";
        if (str == "size")
            cout << size() << "\n";
        if (str == "empty")
            cout << empty() << "\n";
        if (str == "front")
            cout << front() << "\n";
        if (str == "back")
            cout << back() << "\n";
    }
}
