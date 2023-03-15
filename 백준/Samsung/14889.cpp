// 스타트와 링크 S2
// 브루트포스, 백트래킹
// N 명 중 N / 2 명을 뽑는 모든 조합을 생각한 후, 능력치를 min 으로 갱신하면서 구한다..
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 21
int N, minVal = 100000000;
int map[MAX_SIZE][MAX_SIZE];
bool team[MAX_SIZE];
void dfs(int idx, int cur)
{
    vector<int> start;
    vector<int> link;
    int start_score = 0;
    int link_score = 0;
    if (cur == (N / 2))
    {
        for (int i = 0; i < N; i++)
        {
            if (team[i] == true) // 선택된 사람들은 start 팀
                start.push_back(i);
            else // 그 외의 사람들은 link 팀
                link.push_back(i);
        }
        for (int i = 0; i < (N / 2); i++)
            for (int j = 0; j < (N / 2); j++)
            {
                start_score += map[start[i]][start[j]];
                link_score += map[link[i]][link[j]];
            } // 각 팀의 능력치의 합 계산
        if (abs(start_score - link_score) < minVal)
            minVal = abs(start_score - link_score);
        return;
    }
    for (int i = idx; i < N; i++)
    {
        if (team[i])
            continue;
        else
        {
            team[i] = true;
            dfs(i, cur + 1);
            team[i] = false;
        }
    }
}

int main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    dfs(0, 0);
    cout << minVal;
}