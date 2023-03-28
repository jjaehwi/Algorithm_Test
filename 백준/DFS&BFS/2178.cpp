// 미로 탐색 S1
// 그래프 이론, 그래프 탐색, 너비 우선 탐색
// 2차원 큐 --> https://kgh940525.tistory.com/entry/알고리즘-Queue의-Pair을-사용하는-이유
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define MAX_SIZE 101
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int N, M;
int map[MAX_SIZE][MAX_SIZE];      // map 표현
bool visited[MAX_SIZE][MAX_SIZE]; // 방문 기록
int dist[MAX_SIZE][MAX_SIZE];     // 이동 거리 카운트

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int start_x, int start_y)
{
    visited[start_x][start_y] = true;
    queue<pair<int, int>> q;
    // utility 헤더 선언 안하고 사용할 때 --> q.push(part<int, int>(start_x, start_y));
    q.push(make_pair(start_x, start_y));
    dist[start_x][start_y]++; // 시작 거리를 1 로
    // 모든 좌표를 탐색
    while (!q.empty())
    {
        // queue 의 front 좌표를, 현재 좌표로 지정
        int current_x = q.front().first;
        int current_y = q.front().second;
        // front 제거
        q.pop();
        // 현재 좌표와 상하좌우로 인접한 좌표 확인
        for (int i = 0; i < 4; i++)
        {
            // 현재 좌표와 상하좌우로 인접한 좌표
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];

            // 인접한 좌표가, 미로 내에 존재하는지, 방문한 적이 없는지, 이동이 가능한지 확인
            if ((next_x >= 1 && next_x <= N) && (next_y >= 1 && next_y <= M) && !visited[next_x][next_y] && map[next_x][next_y] == 1)
            {
                // 이동 가능 하다면 방문 처리하고, 큐에 넣고, 거리를 올린다.
                visited[next_x][next_y] = true;
                q.push(make_pair(next_x, next_y));
                dist[next_x][next_y] = dist[current_x][current_y] + 1;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    // scanf("%1d") 로 붙어있어도 한번에 한개씩 입력 받을 수 있다.
    // fastio를 쓰면 scanf를 사용하지 못한다.
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%1d", &map[i][j]);
    bfs(1, 1);
    cout << dist[N][M];
}

/* 벡터 쓰는 경우 입력 받을 때..
   map.resize(N + 1);
   for (int i = 0; i < N; i++)
   {
       string str;
       cin >> str;
       for (int j = 0; j < M; j++)
           map[i].push_back(str[j] - '0');
   }
   for (int i = 0; i < N; i++)
   {
       for (int j = 0; j < M; j++)
           cout << map[i][j] << " ";
       cout << "\n";
   }
   */