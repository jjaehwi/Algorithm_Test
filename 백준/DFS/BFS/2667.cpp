// 단지번호붙이기 S1
// 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define MAX_SIZE 27
int N, house, cnt;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<int> result;
void bfs(int start_x, int start_y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(start_x, start_y));
    while (!q.empty())
    {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];

            if (map[next_x][next_y] != 0 && !visited[next_x][next_y])
            {
                house++;
                visited[next_x][next_y] = true;
                q.push(make_pair(next_x, next_y));
            }
        }
    }
}
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%1d", &map[i][j]);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (map[i][j] && !visited[i][j])
            {
                house = 0;
                bfs(i, j);
                if (house == 0)
                {
                    cnt++;
                    result.push_back(1);
                }
                else
                {
                    cnt++;
                    result.push_back(house);
                }
            }
        }
    }
    cout << cnt << "\n";
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << "\n";
}