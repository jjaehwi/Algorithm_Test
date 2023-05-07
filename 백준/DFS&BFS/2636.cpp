// 치즈 G4
// 그래프 탐색, bfs
#include <iostream>
#include <queue>
using namespace std;
int r, c;
int map[101][101];
bool visit[101][101];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int cnt, area;
void bfs()
{
    queue<pair<int, int>> q;
    queue<pair<int, int>> temp;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        area = q.size(); // 남은 치즈 개수 체크
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < c && ny >= 0 && ny < r)
                {
                    if (!visit[ny][nx] && map[ny][nx] == 1)
                    {
                        temp.push(make_pair(nx, ny)); // 가장자리 치즈 만 저장
                    }
                    else if (!visit[ny][nx] && map[ny][nx] == 0)
                    {
                        q.push(make_pair(nx, ny)); // 탐색 진행
                    }
                    visit[ny][nx] = true;
                }
            }
        }
        while (!temp.empty())
        {
            q.push(temp.front());
            temp.pop();
        }
        cnt++;
    }
}
int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }
    visit[0][0] = true;
    bfs();
    cout << cnt - 1 << '\n'; // while문 구조상 카운트가 한번 더 됨.
    cout << area << '\n';
    return 0;
}