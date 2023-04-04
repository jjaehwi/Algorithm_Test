// 야구 G4
// 브루트포스, 순열, 구현
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 51
#define PLAYER 10
int N, res;
int order[PLAYER];     // 타순 저장
int game[MAX][PLAYER]; // 게임마다 선수들의 능력치를 저장할 배열 (입력받는 배열)
bool selected[PLAYER]; // 뽑았는지 안뽑았는지 판단
// 게임 진행하는 함수
void playGame()
{
    /* 실제로 게임을 진행해보기 위한 함수 */
    int score = 0;
    int start_player = 1;
    int baseState[4];

    /* Base[4]의 의미.
       Base[0] = 홈, Base[1] = 1루, Base[2] = 2루, Base[3] = 3루를 의미한다.
       Base[x] = 0의 의미는 "현재 x루 에는 사람이 없습니다."를 의미하고
       Base[x] = 1의 의미는 "현재 x루 에는 사람이 있습니다."를 의미한다.
       즉, 누군가가 안타, 1루타, 2루타, 3루타 등을 치게 될 경우
       각각의 상황에 맞게 Base[]의 상태를 변경해준다.
    */
    for (int i = 1; i <= N; i++)
    {                   // N 이닝동안
        int outCnt = 0; // 아웃
        bool nextIning = false;
        memset(baseState, 0, sizeof(baseState));

        while (1)
        {
            for (int j = start_player; j < PLAYER; j++)
            {
                int player = game[i][order[j]];
                // 아웃을 치게되면 Out_Cnt 증가
                if (player == 0)
                    outCnt++;
                // 안타
                else if (player == 1)
                {
                    // 각 베이스에 있던 선수들이 전진시킬 것 (3루부터 전진시켜야한다. 1루부터 전진시키면 바로바로 반영이 되어버릴 수 있기 때문...)
                    for (int k = 3; k >= 1; k--)
                    {
                        // k 베이스에 사람이 있는데
                        if (baseState[k] == 1)
                        {
                            // 안타 이므로 때문에 3루에 선수가 있는 경우 1 득점
                            if (k == 3)
                            {
                                baseState[k] = 0;
                                score++;
                            }
                            // 3루가 아닌 다른 베이스에 있는 선수들은 하나씩 전진
                            else
                            {
                                baseState[k + 1] = 1;
                                baseState[k] = 0;
                            }
                        }
                    }
                    // 안타친 본인도 진루
                    baseState[1] = 1;
                }
                // 2루타
                else if (player == 2)
                {
                    for (int k = 3; k >= 1; k--)
                    {
                        if (baseState[k] == 1)
                        {
                            // 2루타 이므로 2루, 3루 선수가 있으면 1 득점씩
                            if (k == 3 || k == 2)
                            {
                                baseState[k] = 0;
                                score++;
                            }
                            else
                            {
                                baseState[k + 2] = 1;
                                baseState[k] = 0;
                            }
                        }
                    }
                    // 본인 2루로 전진
                    baseState[2] = 1;
                }
                // 3루타
                else if (player == 3)
                {
                    for (int k = 3; k >= 1; k--)
                    {
                        // 3루타는 모든 베이스에 선수가 있으면 무조건 득점
                        if (baseState[k] == 1)
                        {
                            baseState[k] = 0;
                            score++;
                        }
                    }
                    // 본인 3루로 전진
                    baseState[3] = 1;
                }
                // 홈런
                else
                {
                    for (int k = 1; k <= 3; k++)
                    {
                        // 홈런도 모든 베이스에 선수가 있으면 무조건 득점
                        if (baseState[k] == 1)
                        {
                            baseState[k] = 0;
                            score++;
                        }
                    }
                    // 본인도 득점
                    score++;
                }
                // 3 아웃이 되면
                if (outCnt == 3)
                {
                    start_player = j + 1;
                    // 마지막 타자였다면 다시 1번 타자부터
                    if (start_player == PLAYER)
                        start_player = 1;
                    // 다음 이닝으로 넘어가도록 하는 것
                    nextIning = true;
                    break;
                }
            }
            // true 값이면 다음 이닝으로 넘어가고 아니면 다시 1번타자부터
            if (nextIning == true)
                break;
            start_player = 1;
        }
    }
    res = max(res, score);
}

// 순열을 뽑는 함수
void dfs(int cur)
{
    if (cur == PLAYER)
    {
        // 선수들의 타순이 정해지면 게임을 시작
        playGame();
        return;
    }
    // 1번 타순부터 정한다 9번 타순까지 정하기
    for (int i = 1; i < PLAYER; i++)
    {
        if (selected[i] == true)
            continue;
        selected[i] = true;
        order[i] = cur;
        dfs(cur + 1);
        selected[i] = false;
    }
}
int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j < PLAYER; j++)
            cin >> game[i][j];

    selected[4] = true; // 4번 타자는 1번 선수로 정해놨기 때문
    order[4] = 1;       // 4번 타자는 1번 선수 인 것.
    dfs(2);             // 순열 뽑기 (1번 타자는 뽑았으므로 2번 타자부터..)

    cout << res << "\n";
}