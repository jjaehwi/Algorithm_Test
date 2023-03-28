// 맥주 마시면서 걸어가기 G5
// 그래프 탐색, bfs
#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int t, n;
// 각 위치를 지정하기 위해.. 편의점은 여러개이고 좌표 범위가 커서 따로 구조체 생성
struct POS
{
    int x;
    int y;
};
POS home;
POS goal;
POS store[101];
bool visited[101];
bool bfs()
{
    queue<pair<int, int>> q;
    q.push(make_pair(home.x, home.y)); // 시작 점의 좌표로 시작

    while (!q.empty())
    {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();
        // 도착점에 갈 수 있는 경우
        if (abs(current_x - goal.x) + abs(current_y - goal.y) <= 1000)
            return true;
        // 편의점들 탐색
        for (int i = 0; i < n; i++)
        {
            // 이미 방문한 편의점이면 통과
            if (visited[i] == true)
                continue;
            // 현재 있는데에서 편의점까지의 맨해튼거리가 1000 이하이면 방문 가능한 곳
            if (abs(current_x - store[i].x) + abs(current_y - store[i].y) <= 1000)
            {
                visited[i] = true; // 그 편의점의 위치를 방문 처리
                q.push(make_pair(store[i].x, store[i].y));
            }
        }
    }
    return false; // 도착점에 도달 못해서 반복문을 나오게 되는 경우
}

void input()
{
    cin >> n;
    cin >> home.x >> home.y;
    for (int j = 0; j < n; j++)
        cin >> store[j].x >> store[j].y;
    cin >> goal.x >> goal.y;
}

int main()
{
    fastio;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        input();
        if (bfs())
            cout << "happy\n";
        else
            cout << "sad\n";
        // 한번 진행한 후 다음 케이스 진행할 때 방문기록 초기화.
        memset(visited, false, sizeof(visited));
    }
}
