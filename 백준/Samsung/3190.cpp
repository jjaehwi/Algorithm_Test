#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

deque<pair<int, int>> dq; // 뱀의 몸 표시
int map[101][101] = {
    0,
}; // 사과 위치 표시
vector<pair<int, char>> dir;
bool check[101][101]; // 뱀의 몸이 있는지 여부
int n, k, x, y, l, m;
char c;

int main()
{
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        map[x - 1][y - 1] = 1;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> c;
        dir.push_back(make_pair(l, c));
    }

    int dir_idx = 0;
    int time = 0;
    int cx = 0;
    int cy = 0;
    dq.push_front(make_pair(0, 0));
    check[0][0] = true;
    int idx = 0;
    while (1)
    {
        time++;
        int nx, ny;
        nx = cx + dx[dir_idx];
        ny = cy + dy[dir_idx];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || check[nx][ny] == true)
        {
            break;
        }
        cx = nx;
        cy = ny;
        check[nx][ny] = true;
        dq.push_front(make_pair(nx, ny));
        // 사과가 없다면
        if (map[nx][ny] == 0)
        {
            int tx = dq.back().first;
            int ty = dq.back().second;
            check[tx][ty] = false;
            dq.pop_back();
        }
        else
        { // 사과가 있다면
            map[nx][ny] = 0;
        }

        // 방향 조절
        if (time == dir[idx].first)
        {
            if (dir[idx].second == 'D')
            {
                dir_idx++;
                if (dir_idx > 3)
                    dir_idx = 0;
            }
            else
            {
                dir_idx--;
                if (dir_idx < 0)
                    dir_idx = 3;
            }
            idx++;
        }
    }
    cout << time << endl;

    return 0;
}