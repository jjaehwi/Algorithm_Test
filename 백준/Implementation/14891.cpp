// 톱니바퀴 G5
// 시뮬레이션, 구현

// 4 개의 톱니바퀴 상태 배열 (각각의 톱니바퀴 번호 0 ~ 7) --> 12시 부터 0, 시계방향으로 진행하면서 1 2 ...
// 명령어 배열 (회전시킨 톱니바퀴 번호, 방향)

// i 번째 톱니바퀴의 2 번 index 와 i + 1 번째 톱니바퀴의 6 번째 index 가 맞닿게 된다.

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 4

int k;
vector<int> wheel[MAX_SIZE];
vector<pair<int, int>> command;

void turning(int n, int dir)
{
    // 시계방향
    if (dir == 1)
    {
        int wheelEnd = wheel[n].at(7);
        for (int i = 7; i > 0; i--)
            wheel[n].at(i) = wheel[n].at(i - 1);
        wheel[n].at(0) = wheelEnd;
    }
    else if (dir == -1)
    {
        int wheelStart = wheel[n].at(0);
        for (int i = 0; i < 7; i++)
            wheel[n].at(i) = wheel[n].at(i + 1);
        wheel[n].at(7) = wheelStart;
    }
}

void turnCheck(int n, int dir)
{
    int reverseDir = 0;
    if (dir == 1)
        reverseDir = -1;
    else
        reverseDir = 1;

    // 0 번째 톱니바퀴인 경우 1, 2, 3 번째 톱니바퀴 확인
    if (n == 0)
    {
        if (wheel[n].at(2) != wheel[n + 1].at(6))
        {
            if (wheel[n + 1].at(2) != wheel[n + 2].at(6))
            {
                if (wheel[n + 2].at(2) != wheel[n + 3].at(6))
                {
                    turning(n, dir);
                    turning(n + 1, reverseDir);
                    turning(n + 2, dir);
                    turning(n + 3, reverseDir);
                }
                else
                {
                    turning(n, dir);
                    turning(n + 1, reverseDir);
                    turning(n + 2, dir);
                }
            }
            else
            {
                turning(n, dir);
                turning(n + 1, reverseDir);
            }
        }
        else
            turning(n, dir);
    }

    // 1 번째 톱니바퀴인 경우 0, 2, 3 번째 톱니바퀴 확인
    else if (n == 1)
    {
        if (wheel[n].at(6) != wheel[n - 1].at(2))
            turning(n - 1, reverseDir);

        if (wheel[n].at(2) != wheel[n + 1].at(6))
        {
            if (wheel[n + 1].at(2) != wheel[n + 2].at(6))
            {
                turning(n, dir);
                turning(n + 1, reverseDir);
                turning(n + 2, dir);
            }
            else
            {
                turning(n, dir);
                turning(n + 1, reverseDir);
            }
        }
        else
            turning(n, dir);
    }

    // 2 번째 톱니바퀴인 경우 0, 1, 3 번째 톱니바퀴 확인
    else if (n == 2)
    {
        if (wheel[n].at(2) != wheel[n + 1].at(6))
            turning(n + 1, reverseDir);

        if (wheel[n].at(6) != wheel[n - 1].at(2))
        {
            if (wheel[n - 1].at(6) != wheel[n - 2].at(2))
            {
                turning(n, dir);
                turning(n - 1, reverseDir);
                turning(n - 2, dir);
            }
            else
            {
                turning(n, dir);
                turning(n - 1, reverseDir);
            }
        }
        else
            turning(n, dir);
    }

    // 3 번째 톱니바퀴인 경우 0, 1, 2 번째 톱니바퀴 확인
    else if (n == 3)
    {
        if (wheel[n].at(6) != wheel[n - 1].at(2))
        {
            if (wheel[n - 1].at(6) != wheel[n - 2].at(2))
            {
                if (wheel[n - 2].at(6) != wheel[n - 3].at(2))
                {
                    turning(n, dir);
                    turning(n - 1, reverseDir);
                    turning(n - 2, dir);
                    turning(n - 3, reverseDir);
                }
                else
                {
                    turning(n, dir);
                    turning(n - 1, reverseDir);
                    turning(n - 2, dir);
                }
            }
            else
            {
                turning(n, dir);
                turning(n - 1, reverseDir);
            }
        }
        else
            turning(n, dir);
    }
}

int main()
{
    fastio;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            int value = str[j] - '0'; // int 값으로 저장
            wheel[i].push_back(value);
        }
    }

    // 1: 시계, -1: 반시계
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int index, direction;
        cin >> index >> direction;
        command.push_back({index - 1, direction});
    }

    for (int i = 0; i < command.size(); i++)
        turnCheck(command[i].first, command[i].second);

    int result = 0;

    if (wheel[0].at(0) == 1)
        result += 1;
    if (wheel[1].at(0) == 1)
        result += 2;
    if (wheel[2].at(0) == 1)
        result += 4;
    if (wheel[3].at(0) == 1)
        result += 8;

    cout << result << "\n";
}