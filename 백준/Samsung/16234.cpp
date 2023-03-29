// 인구 이동 G5
// 그래프 이론, bfs, 구현, 시뮬레이션
#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 51
int N, L, R;
int country[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
// sum = 나라의 인구
// cnt = 연합한 나라 수
// ans = bfs 몇 번 돌았는지
int sum, cnt, ans;
queue<pair<int, int>> q;
// 연합한 나라를 저장
vector<pair<int, int>> v;
// 인구의 갱신이 일어났는지에 대해 일어났으면 true, 안일어났으면 false
bool flag;

void bfs(int start_x, int start_y)
{
    // 현재 방문한 나라에 대한 처리
    cnt++;
    visited[start_x][start_y] = true;
    sum += country[start_x][start_y];
    q.push({start_x, start_y});
    v.push_back({start_x, start_y});

    while (!q.empty())
    {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            // 다음 방문할 나라의 x, y 좌표
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
                continue;
            if (visited[next_x][next_y])
                continue;

            // 두 나라의 인구 수 차이
            int peopleGap = abs(country[current_x][current_y] - country[next_x][next_y]);

            // 차이가 L 과 R 사이라면
            if (peopleGap >= L && peopleGap <= R)
            {
                cnt++;                          // 연합한 나라 수 + 1
                visited[next_x][next_y] = true; // 연합 (방문) 처리
                sum += country[next_x][next_y]; // 방금 연합 맺은 나라의 인구를 현재 연합한 나라 인구 수에 더한다.
                q.push({next_x, next_y});
                v.push_back({next_x, next_y});
            }
        }
    }
}

int main()
{
    fastio;
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> country[i][j];

    while (true)
    {
        // 처음 반복문을 돌고 인구 갱신이 된 이후 다시 while 문을 돌 수 있다.
        // 갱신이 된 이후 이전 연합했던 상태 (visited) 를 초기화해야한다.
        memset(visited, false, sizeof(visited));

        // flag 를 false 로 둬서 인구 이동이 일어나지 않았을 때 반복문을 탈출하게 된다.
        flag = false;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (!visited[i][j])
                {
                    bfs(i, j);

                    // 인구 이동 처리 --> 연합한 나라가 있다면 인구 수를 갱신한다.
                    if (v.size() > 1)
                    {
                        flag = true;

                        for (int i = 0; i < v.size(); i++)
                            country[v[i].first][v[i].second] = sum / cnt;
                    }

                    // 이동처리 끝나면 초기화하고 bfs 를 나온다.
                    v.clear();
                    sum = 0;
                    cnt = 0;
                }

        // 인구 이동이 일어났다면 ans + 1, 일어나지 않았다면 반복문 탈출
        if (flag)
            ans++;
        else
            break;

        /*
        인구 확인
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << country[i][j] << " ";
            cout << "\n";
        }
        */
    }

    cout << ans << "\n";
}
