#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m, s, t;
    int count = -1;
    cin >> n >> m;
    // 2차원 벡터 n,m 크기로 선언
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            v[i][j] = c;
        }
    }
    cin >> s >> t;
    for (int i = s - 1; i < t - 1;)
    {
        // 방을 옮길 때마다 count를 증가시킴
        count++;
        // 가장 길게 머무를 수 있는 방을 선택, max값 초기화
        int max = 0;
        // 1번 방 부터 m번 방 까지 탐색
        for (int j = 0; j < m; j++)
        {
            // 날짜 초기화
            int day = 0;
            // 시작 일 부터 종료 일 까지 탐색
            for (int k = i; k < t - 1; k++)
            {
                // 예약 가능한 방인 경우 day 값 ++
                if (v[k][j] == 'O')
                    day++;
                else
                    break;
            }
            if (max < day)
                max = day;
        }
        // 머무를 수 없는 경우
        if (max == 0)
        {
            count = -1;
            break;
        }
        // 머무른 일 수 만큼 증가 시킴
        i += max;
    }
    cout << count;
}