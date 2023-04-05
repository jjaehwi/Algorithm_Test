// 미세먼지 안녕! G4
// 시뮬레이션, 구현
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 51
int R, C, T, result;
int map[MAX_SIZE][MAX_SIZE];
int mapCopy[MAX_SIZE][MAX_SIZE];
pair<int, int> cleaner[2];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void diffusion()
{
    // 원본 map 저장
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            mapCopy[i][j] = map[i][j];

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            // 벽이 아니고 공기청정기가 있는 부분이 아니라면
            // 비교는 원본으로 갱신은 복사본에
            if (map[i][j] != 0 && map[i][j] != -1)
            {
                int count = 0;
                // 원본 값으로 확산하는 값 설정
                int value = map[i][j] / 5;
                // 네 방향으로 확산
                for (int k = 0; k < 4; k++)
                {
                    int next_x = i + dx[k];
                    int next_y = j + dy[k];

                    if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C)
                    {
                        // 원본 값이랑 비교
                        if (map[next_x][next_y] != -1)
                        {
                            // 갱신은 복사본에
                            mapCopy[next_x][next_y] = mapCopy[next_x][next_y] + value;
                            count++;
                        }
                    }
                }
                // 확산 끝나면 원래 자리 갱신
                mapCopy[i][j] = mapCopy[i][j] - (count * value);
            }
        }
    }
    /* 출력 확인
    cout << "###############원본###################\n";
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << map[i][j] << " ";
        cout << "\n";
    }
    cout << "###############복사본################\n";
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << mapCopy[i][j] << " ";
        cout << "\n";
    }
    */

    // 갱신된 map 을 원본으로 갱신
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            map[i][j] = mapCopy[i][j];
}

void wind()
{
    for (int i = 0; i < 2; i++)
    {
        // 윗 부분
        if (i == 0)
        {
            // 1. 공기청정기 위에서부터 (0, 0)까지  이동
            for (int j = cleaner[0].first - 1; j > 0; j--)
                map[j][0] = map[j - 1][0];
            // 2. 제일 윗 줄 이동
            for (int j = 0; j <= C - 2; j++)
                map[0][j] = map[0][j + 1];
            // 3. 공기청정기 반대편 세로 줄
            for (int j = 0; j < cleaner[0].first; j++)
                map[j][C - 1] = map[j + 1][C - 1];
            // 4. 공기청정기 위치한 가로 줄
            for (int j = C - 1; j >= 2; j--)
                map[cleaner[0].first][j] = map[cleaner[0].first][j - 1];
            // 공기청정기는 항상 1번 열에 설치 --> 공기청정기에서 처음으로 밀고 나오는 값 0 으로
            map[cleaner[0].first][1] = 0;
        }
        // 아래 부분
        else
        {
            // 1. 공기청정기 아래에서부터 (R-1, 0) 까지 가므로 R-2 까지 하면 R-2 +1 이어서 R-1 을 가져와서 세팅
            for (int j = cleaner[1].first + 1; j <= R - 2; j++)
                map[j][0] = map[j + 1][0];
            // 2. 제일 아래 줄
            for (int j = 0; j <= C - 2; j++)
                map[R - 1][j] = map[R - 1][j + 1];
            // 3. 공기청정기 반대편 세로 줄
            for (int j = R - 1; j > cleaner[1].first; j--)
                map[j][C - 1] = map[j - 1][C - 1];
            // 4. 공기청정기 위치한 가로 줄
            for (int j = C - 1; j > 1; j--)
                map[cleaner[1].first][j] = map[cleaner[1].first][j - 1];
            map[cleaner[1].first][1] = 0;
        }
    }
}

int dustCnt()
{
    int sum = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == -1)
                continue;
            sum += map[i][j];
        }
    return sum;
}

int main()
{
    fastio;
    cin >> R >> C >> T;
    int cleanerIndex = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            // 공기청정기의 윗 부분과 아랫 부분 위치를 저장
            if (map[i][j] == -1)
            {
                cleaner[cleanerIndex].first = i;
                cleaner[cleanerIndex].second = j;
                cleanerIndex++;
            }
        }

    for (int i = 0; i < T; i++)
    {
        diffusion();
        wind();
        // cout << "###############원본###################\n";
        // for (int i = 0; i < R; i++)
        // {
        //     for (int j = 0; j < C; j++)
        //         cout << map[i][j] << " ";
        //     cout << "\n";
        // }
    }
    cout << dustCnt() << "\n";
}