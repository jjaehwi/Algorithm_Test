// 감시 G4
// 시뮬레이션, 브루트포스
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 8
int N, M, answer = 987654321;
int map[MAX_SIZE][MAX_SIZE];
int copyMap[MAX_SIZE][MAX_SIZE];
struct cctv
{
    int x;
    int y;
    int spec; // cctv 종류 1~5
    int dir;  // cctv 배치 경우의 수 1~4
};
vector<cctv> cctvVec;

void checkRight(int start_x, int start_y)
{
    for (int i = start_y + 1; i < M; i++)
    {
        // 6 이라는 벽을 만나면 끝
        if (copyMap[start_x][i] == 6)
            break;
        // cctv 를 만나면 끝나진 않고 계속 진행
        if (copyMap[start_x][i] >= 1 && copyMap[start_x][i] <= 5)
            continue;
        // 0 을 만나면 -1 로 바꿈
        copyMap[start_x][i] = -1;
    }
}
void checkLeft(int start_x, int start_y)
{
    for (int i = start_y - 1; i >= 0; i--)
    {
        // 6 이라는 벽을 만나면 끝
        if (copyMap[start_x][i] == 6)
            break;
        // cctv 를 만나면 끝나진 않고 계속 진행
        if (copyMap[start_x][i] >= 1 && copyMap[start_x][i] <= 5)
            continue;
        // 0 을 만나면 -1 로 바꿈
        copyMap[start_x][i] = -1;
    }
}
void checkDown(int start_x, int start_y)
{
    for (int i = start_x + 1; i < N; i++)
    {
        // 6 이라는 벽을 만나면 끝
        if (copyMap[i][start_y] == 6)
            break;
        // cctv 를 만나면 끝나진 않고 계속 진행
        if (copyMap[i][start_y] >= 1 && copyMap[i][start_y] <= 5)
            continue;
        // 0 을 만나면 -1 로 바꿈
        copyMap[i][start_y] = -1;
    }
}
void checkUp(int start_x, int start_y)
{
    for (int i = start_x - 1; i >= 0; i--)
    {
        // 6 이라는 벽을 만나면 끝
        if (copyMap[i][start_y] == 6)
            break;
        // cctv 를 만나면 끝나진 않고 계속 진행
        if (copyMap[i][start_y] >= 1 && copyMap[i][start_y] <= 5)
            continue;
        // 0 을 만나면 -1 로 바꿈
        copyMap[i][start_y] = -1;
    }
}

void checkArea()
{
    // 맵 복사본
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            copyMap[i][j] = map[i][j];

    for (int i = 0; i < cctvVec.size(); i++)
    {
        // 4가지 경우
        if (cctvVec[i].spec == 1)
        {
            if (cctvVec[i].dir == 0)
                checkRight(cctvVec[i].x, cctvVec[i].y);
            else if (cctvVec[i].dir == 1)
                checkLeft(cctvVec[i].x, cctvVec[i].y);
            else if (cctvVec[i].dir == 2)
                checkDown(cctvVec[i].x, cctvVec[i].y);
            else if (cctvVec[i].dir == 3)
                checkUp(cctvVec[i].x, cctvVec[i].y);
        }
        // 2가지 경우
        else if (cctvVec[i].spec == 2)
        {
            if (cctvVec[i].dir == 0 || cctvVec[i].dir == 1)
            {
                checkRight(cctvVec[i].x, cctvVec[i].y);
                checkLeft(cctvVec[i].x, cctvVec[i].y);
            }
            else if (cctvVec[i].dir == 2 || cctvVec[i].dir == 3)
            {
                checkUp(cctvVec[i].x, cctvVec[i].y);
                checkDown(cctvVec[i].x, cctvVec[i].y);
            }
        }
        // 4가지 경우
        else if (cctvVec[i].spec == 3)
        {
            if (cctvVec[i].dir == 0)
            {
                checkUp(cctvVec[i].x, cctvVec[i].y);
                checkRight(cctvVec[i].x, cctvVec[i].y);
            }
            else if (cctvVec[i].dir == 1)
            {
                checkRight(cctvVec[i].x, cctvVec[i].y);
                checkDown(cctvVec[i].x, cctvVec[i].y);
            }
            else if (cctvVec[i].dir == 2)
            {
                checkDown(cctvVec[i].x, cctvVec[i].y);
                checkLeft(cctvVec[i].x, cctvVec[i].y);
            }
            else if (cctvVec[i].dir == 3)
            {
                checkLeft(cctvVec[i].x, cctvVec[i].y);
                checkUp(cctvVec[i].x, cctvVec[i].y);
            }
        }
        // 4가지 경우
        else if (cctvVec[i].spec == 4)
        {
            if (cctvVec[i].dir == 0)
            {
                checkLeft(cctvVec[i].x, cctvVec[i].y);
                checkUp(cctvVec[i].x, cctvVec[i].y);
                checkRight(cctvVec[i].x, cctvVec[i].y);
            }
            else if (cctvVec[i].dir == 1)
            {
                checkUp(cctvVec[i].x, cctvVec[i].y);
                checkRight(cctvVec[i].x, cctvVec[i].y);
                checkDown(cctvVec[i].x, cctvVec[i].y);
            }
            else if (cctvVec[i].dir == 2)
            {
                checkRight(cctvVec[i].x, cctvVec[i].y);
                checkDown(cctvVec[i].x, cctvVec[i].y);
                checkLeft(cctvVec[i].x, cctvVec[i].y);
            }
            else if (cctvVec[i].dir == 3)
            {
                checkDown(cctvVec[i].x, cctvVec[i].y);
                checkLeft(cctvVec[i].x, cctvVec[i].y);
                checkUp(cctvVec[i].x, cctvVec[i].y);
            }
        }
        // 1가지 경우
        else if (cctvVec[i].spec == 5)
        {
            checkRight(cctvVec[i].x, cctvVec[i].y);
            checkDown(cctvVec[i].x, cctvVec[i].y);
            checkLeft(cctvVec[i].x, cctvVec[i].y);
            checkUp(cctvVec[i].x, cctvVec[i].y);
        }
    }
}
int sumArea()
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (copyMap[i][j] == 0)
                sum++;
        }
    }
    return sum;
}

void dfs(int cur)
{
    if (cur == cctvVec.size())
    {
        checkArea();
        answer = min(answer, sumArea());
        return;
    }

    cctvVec[cur].dir = 0;
    dfs(cur + 1);
    cctvVec[cur].dir = 1;
    dfs(cur + 1);
    cctvVec[cur].dir = 2;
    dfs(cur + 1);
    cctvVec[cur].dir = 3;
    dfs(cur + 1);
}
int main()
{
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 5)
            {
                cctvVec.push_back({i, j, map[i][j], -1}); // 방향을 정하기 전
            }
        }
    dfs(0);
    cout << answer << "\n";
}