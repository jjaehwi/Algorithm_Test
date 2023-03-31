// 상어 초등학교 G5
// 구현
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 21
#define MAX_SIZE2 401
int N;

int seat[MAX_SIZE][MAX_SIZE];            // 학생들이 앉을 자리
int student_sequence[MAX_SIZE2];         // 학생들 앉힐 순서
bool student_like[MAX_SIZE2][MAX_SIZE2]; // 각 학생들이 좋아하는 학생 4명
int visited[MAX_SIZE][MAX_SIZE];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool cmp(pair<pair<int, int>, pair<int, int>> &a, pair<pair<int, int>, pair<int, int>> &b)
{
    if (a.first.first == b.first.first)
    {
        if (a.first.second == b.first.second)
        {
            if (a.second.first == b.second.first)
            {
                return a.second.second < b.second.second;
            }
            return a.second.first < b.second.first;
        }
        return a.first.second > b.first.second;
    }
    return a.first.first > b.first.first;
}

// 자리에 앉히는 함수
void placement(int index)
{
    int studentIdx = student_sequence[index]; // 앉힐 학생의 순서
    vector<pair<pair<int, int>, pair<int, int>>> canSit;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // 현재 자리에 누가 앉아있으면 다음 자리 탐색
            if (visited[i][j])
                continue;
            int loveStu = 0; // 선호도
            int empty = 0;
            for (int k = 0; k < 4; k++)
            {
                int next_x = i + dx[k];
                int next_y = j + dy[k];

                // 범위 넘어가면 넘김
                if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N)
                    continue;
                // 조건 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
                // 현재 배치하려는 학생이 좋아하는 학생이 존재하면 선호도 ++
                if (student_like[studentIdx][visited[next_x][next_y]] != 0)
                    loveStu++;
                // 조건 2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
                // 현재 배치하려는 자리에서 주변 빈 공간 탐색
                else if (!visited[next_x][next_y])
                    empty++;
            }
            canSit.push_back({{loveStu, empty}, {i, j}});
        }
    }
    // 조건에 맞게 정렬해서 맨 앞에 있는 자리 선택
    sort(canSit.begin(), canSit.end(), cmp);

    int seatR = canSit[0].second.first;
    int seatC = canSit[0].second.second;
    visited[seatR][seatC] = studentIdx;
}

int score()
{
    int result = 0;
    int satisfication[5] = {0, 1, 10, 100, 1000};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int loveStuCnt = 0;
            int stuNum = visited[i][j];
            for (int k = 0; k < 4; k++)
            {
                int next_x = i + dx[k];
                int next_y = j + dy[k];
                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
                    continue;
                if (student_like[stuNum][visited[next_x][next_y]] != 0)
                    loveStuCnt++;
            }
            result += satisfication[loveStuCnt];
        }
    }
    return result;
}

int main()
{
    fastio;
    cin >> N;

    for (int i = 0; i < N * N; i++)
    {
        cin >> student_sequence[i];
        for (int j = 0; j < 4; j++)
        {
            int student;
            cin >> student;
            student_like[student_sequence[i]][student] = true;
        }
    }
    for (int i = 0; i < N * N; i++)
        placement(i);

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //         cout << visited[i][j] << " ";
    //     cout << "\n";
    // }
    cout << score();
    return 0;
}