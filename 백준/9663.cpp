#include <iostream>
using namespace std;
int N, result = 0;
int chess[15];

// level : 현재 배치한 퀸의 행
bool promising(int position)
{
    for (int i = 0; i < position; i++)
    {
        // 배치했던 퀸들과 현재 배치하려는 퀸이 서로 공격할 수 있다면 return 0
        // 세로축(열) 판단: 현재 배치한 퀸의 열 == 배치했던 퀸의 열 ||
        // 대각축 판단: 현재 배치한 퀸의 행 - 배치했던 퀸의 행 ==
        //             절대값(현재 배치한 퀸의 열 - 배치했던 퀸의 열)
        if (chess[i] == chess[position] || abs(chess[position] - chess[i]) == (position - i))
            return false;
    }
    // 현재 퀸을 배치할 수 있다면 true
    return true;
}

void n_queens(int level)
{
    // 현재 배치한 퀸의 갯수가 입력값(N)과 같다면 탈출
    if (level == N)
    {
        result += 1;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        // [level], j] 에 배치해보고
        chess[level] = i;
        // 배치가 가능하면
        if (promising(level))
            // 퀸의 행 + 1 해서 다음 퀸을 배치해본다.
            n_queens(level + 1);
    }
}
int main()
{
    cin >> N;
    n_queens(0);
    cout << result;
}
