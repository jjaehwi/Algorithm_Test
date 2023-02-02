// 맥주 마시면서 걸어가기 G5
// 그래프 탐색, bfs
#include <cstdio>
#include <cstring>
#include <queue>
#define abs(x) (((x) > 0) ? (x) : -(x))
using namespace std;

int N;
struct ST
{
    int x;
    int y;
};
ST store[100];
ST goal;
ST home;
bool visited[100];
// 편의점 없이 갈 수 있는 최대 거리 1,000m (50 m * 20)
bool Solve()
{
    queue<pair<int, int>> q;
    q.push({home.x, home.y}); // 시작

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (abs(x - goal.x) + abs(y - goal.y) <= 1000)
            return true;

        for (int i = 0; i < N; i++)
        {
            if (visited[i] == true)
                continue;
            int d = (abs(x - store[i].x) + abs(y - store[i].y));
            if (d <= 1000)
            {
                visited[i] = true;
                q.push({store[i].x, store[i].y});
            }
        }
    }
    return false;
}
void Input()
{
    scanf("%d", &N);
    scanf("%d %d", &home.x, &home.y);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &store[i].x, &store[i].y);
    }
    scanf("%d %d", &goal.x, &goal.y);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        Input();
        if (Solve())
            printf("happy\n");
        else
            printf("sad\n");
        memset(visited, 0, sizeof(visited));
    }
}
