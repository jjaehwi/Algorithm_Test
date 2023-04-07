// 마법사 상어와 파이어볼 G4
// 시뮬레이션, 구현
// N x N 격자, 파이어볼 M 개, K 번 명령
// 위치 ri,ci
// 질량 mi
// 방향 di
// 속력 si
/*
파이어볼의 방향은 본인을 가운데 기준으로
7 0 1
6   2
5 4 3
이다.
*/
// 이동을 명령하면,, 파이어볼들은 자신의 방향 di 로 속력 si 만큼 칸 이동
// 이동 후 2개 이상 파이어볼이 있다면,,
// 같은 칸에 있는 파이어볼은 하나로 합쳐짐
// 파이어볼이 4개의 파이어볼로 나뉘어짐
// 나눠질 때 질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋
// 나눠질 때 속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋
// 합쳐지는 파이어볼의 방향이 모두 홀수, 모두 짝수면 방향은 0,2,4,6 / 그렇지 않으면 1,3,5,7
// 질량이 0 인 파이어볼은 소멸되어 사라짐
// 마법사가 이동을 K 번 명령한 뒤 남아있는 파이어볼 질량의 합을 구해라.

/*
파이어볼 움직이기
1번 행은 N번과 연결되어 있고, 1번 열은 N번 열과 연결되어 있다. = N번 움직이게 되면, 다시 본인의 자리로 돌아온다.
속력 % N = 현재 속력으로 움직이게 되면, 속력 / N번 만큼 자기 자리에 위치하게 될 것이고, 속력 % N번칸 만큼 더 움직이면 된다.

1) "파이어볼의 속력 % N(맵의 크기)" 를 통해서 실제로 몇 칸을 움직이면 되는지 구한다.
2) 1)의 과정을 통해 움직일 칸수를 구했을 때, 맵의 범위를 넘어간다면 +N or -N을 통해서 올바른 위치를
   찾아준다.
*/

/*
파이어볼 나누기 : 한 칸에 여러 개의 파이어볼이 동시에 존재하는 칸에 대한 처리
해당 좌표의 크기를 확인했을 때, 2개 이상 들어가있다면 size >= 2 일 것이다.
2개 이상의 파이어볼이 있다면, 문제에서 제시한대로 해당 파이어볼들을 나누기 위해서, 해당 파이어볼들의 질량의 합을 구해주면 되고, 속력의 합을 구해준다.
동시에 파이어볼들의 방향이 홀수로만 이루어져있는지, 짝수로만 이루어져 있는지를 판단한다.

*/

#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 51
int N, M, K;
struct fireball
{
    int x;
    int y;
    int mass;
    int speed;
    int dir;
};
vector<fireball> map[MAX_SIZE][MAX_SIZE];
vector<fireball> fb;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int evenDir[] = {0, 2, 4, 6};
int oddDir[] = {1, 3, 5, 7};

void moveFireball()
{
    // 파이어 볼이 움직일 때마다 map 을 전체적으로 다시 갱신할 것이기 때문
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            map[i][j].clear();

    for (int i = 0; i < fb.size(); i++)
    {
        int start_x = fb[i].x;
        int start_y = fb[i].y;
        int start_mass = fb[i].mass;
        int start_speed = fb[i].speed;
        int start_dir = fb[i].dir;

        int moveVal = start_speed % N;
        int next_x = start_x + dx[start_dir] * moveVal;
        int next_y = start_y + dy[start_dir] * moveVal;
        if (next_x > N)
            next_x -= N;
        if (next_x < 1)
            next_x += N;
        if (next_y > N)
            next_y -= N;
        if (next_y < 1)
            next_y += N;
        // 바뀐 자리를 map 에 반영해주고, 파이어볼의 위치도 바꿔준다.
        map[next_x][next_y].push_back({next_x, next_y, start_mass, start_speed, start_dir});
        fb[i].x = next_x;
        fb[i].y = next_y;
    }
}

void sumFireball()
{
    // 파이어볼 정보 임시 저장 벡터
    vector<fireball> temp;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            // map 에 파이어볼이 없으면 넘어가고, 파이어볼이 하나면 temp 에 저장하고 넘어간다.
            if (map[i][j].size() == 0)
                continue;
            if (map[i][j].size() == 1)
            {
                temp.push_back(map[i][j][0]);
                continue;
            }
            // 만약 파이어볼이 2개 라면... 분리되는 처리
            int fireballCnt = map[i][j].size();
            int totalMass = 0;
            int totalSpeed = 0;

            bool even = false;
            bool odd = false;

            for (int k = 0; k < fireballCnt; k++)
            {
                totalMass += map[i][j][k].mass;
                totalSpeed += map[i][j][k].speed;
                if (map[i][j][k].dir % 2 == 0)
                    even = true;
                else
                    odd = true;
            }

            int newMass = totalMass / 5;
            int newSpeed = totalSpeed / fireballCnt;
            if (newMass == 0)
                continue;

            if (!even || !odd)
                for (int k = 0; k < 4; k++)
                    temp.push_back({i, j, newMass, newSpeed, evenDir[k]});
            else
                for (int k = 0; k < 4; k++)
                    temp.push_back({i, j, newMass, newSpeed, oddDir[k]});
        }
    }
    // 이후 임시로 저장해놨던 파이어볼 정보를 진짜 파이어볼 정보에 옮겨준다.
    fb = temp;
}

int main()
{
    fastio;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        // 입력받은 파이어볼의 정보 저장
        fb.push_back({r, c, m, s, d});
    }
    for (int i = 0; i < K; i++)
    {
        moveFireball();
        sumFireball();
    }
    int answer = 0;
    for (int i = 0; i < fb.size(); i++)
        answer += fb[i].mass;

    cout << answer << "\n";
}