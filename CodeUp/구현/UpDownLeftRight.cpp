/* 상하좌우
여행가 A는 N x N 크기의 정사각형 공간 위에 서 있습니다. 이 공간은 1 x 1 크기의 정사각형으로 나누어져 있습니다.
가장 왼쪽 위 좌표는 (1,1)이며, 가장 오른쪽 아래 좌표는 (N,N)에 해당합니다. 여행가 A는 상, 하, 좌, 우 방향으로 이동할 수 있으며, 시작 좌표는 항상 (1,1)입니다.
우리 앞에는 여행가 A가 이동할 계획이 적힌 계획서가 놓여 있습니다.

계획서에는 하나의 줄에 띄어쓰기를 기준으로 하여, L, R, U, D 중 하나의 문자가 반복적으로 적혀 있습니다. 각 문자의 의미는 다음과 같습니다.
L: 왼쪽으로 한 칸 이동
R: 오른쪽으로 한 칸 이동
U: 위로 한 칸 이동
D: 아래로 한 칸 이동

이 때, 여행가 A가 N x N 크기의 정사각형 공간을 벗어나는 움직임은 무시됩니다. 예를 들어 (1,1)의 위치에서 L 혹은 U를 만나면 무시됩니다.

요구사항대로 충신히 구현하면 되는 문제이다. 일련의 명령에 따라 개체를 차례대로 이동시킨다는 점에서 시뮬레이션 유형으로도 분류되며 구현이 중요한 대표적인 문제유형.
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string plans;
    int x = 1, y = 1;
    // L, R, U, D에 따른 이동 방향
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    char moveTypes[4] = {'L', 'R', 'U', 'D'};

    cin >> n;
    cin.ignore(); // 버퍼 지우기
    getline(cin, plans);
    // 이동 계획을 하나씩 확인하기
    for (int i = 0; i < plans.size(); i++)
    {
        char plan = plans[i];
        // 이동 후 좌표 구하기
        int nx = -1, ny = -1;
        for (int j = 0; j < 4; j++)
        {
            if (plan == moveTypes[j])
            {
                nx = x + dx[j];
                ny = y + dy[j];
            }
        }
        // 공간을 벗어나는 경우 무시
        if (nx < 1 || ny < 1 || nx > n || ny > n)
            continue;
        // 이동 수행
        x = nx;
        y = ny;
    }
    cout << x << ' ' << y << '\n';
}
