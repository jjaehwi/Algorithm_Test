// 스타트링크 S1
// 그래프 탐색, bfs
#include <iostream>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1000001
int F, S, G, U, D;
int visited[MAX_SIZE];
void bfs()
{
    queue<int> q;
    q.push(S);
    visited[S] = 1;
    while (!q.empty())
    {
        int current_level = q.front();
        q.pop();
        if (current_level == G)
            break;
        int level_up = current_level + U;
        int level_down = current_level - D;
        // cout << "current level : " << current_level << " \n";
        // cout << "level_up : " << level_up << " \n";
        // cout << "level_down : " << level_down << " \n";
        if (level_up <= F)
            if (visited[level_up] == 0)
            {
                visited[level_up] = visited[current_level] + 1;
                q.push(level_up);
            }

        if (level_down >= 1)
            if (visited[level_down] == 0)
            {
                visited[level_down] = visited[current_level] + 1;
                q.push(level_down);
            }
    }
}
int main()
{
    fastio;
    cin >> F >> S >> G >> U >> D;
    bfs();
    if (visited[G] == 0)
        cout << "use the stairs\n";
    else
        cout << visited[G] - 1;
}