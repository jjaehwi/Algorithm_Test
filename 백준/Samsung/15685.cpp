// 드래곤 커브 G4
// 구현, 시뮬레이션
// 한 세대의 방향정보를 역순으로 탐색하면서 +1 을 시켜준 값이 그 다음 세대의 방향정보...!
// 주의 4세대에서.. 3 은 +1 이 된 4가  아니라 0 이 된다.
// --> 다음 세대의 추가되는 선분의 방향정보 = 이전 세대의 방향정보를 역순으로 탐색하면서 + 1 % 4 를 한 것..!
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 101
int N, x, y, d, g;
int map[MAX_SIZE][MAX_SIZE];
// 0: x좌표가 증가하는 방향 (→), 1: y좌표가 감소하는 방향 (↑), 2: x좌표가 감소하는 방향 (←), 3: y좌표가 증가하는 방향 (↓)
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
// 방향 정보를 저장할 벡터
vector<int> dir_info;

void dragon_Curve()
{
    int S = dir_info.size();
    // 역순으로 탐색하면서 +1 % 4
    for (int i = S - 1; i >= 0; i--)
    {
        int nD = (dir_info[i] + 1) % 4;
        x = x + dx[nD];
        y = y + dy[nD];
        map[x][y] = 1;

        dir_info.push_back(nD);
    }
}
void count()
{
    int cnt = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == true)
                cnt++;
        }
    }
    cout << cnt << "\n";
}

int main()
{
    fastio;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> y >> x >> d >> g;
        dir_info.clear();
        // 시작점
        map[x][y] = 1;
        x = x + dx[d];
        y = y + dy[d];
        // 시작 방향으로부터 뻗어나가기
        map[x][y] = 1;
        dir_info.push_back(d);
        for (int j = 0; j < g; j++)
            dragon_Curve();
    }
    count();
}