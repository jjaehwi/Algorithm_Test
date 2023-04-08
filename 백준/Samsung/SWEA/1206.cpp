// View [S/W 문제해결 기본] 1일차 D3
// 구현
// 현재 기준 아파트가 왼쪽 2칸, 오른쪽 2칸 중 가장 높다면..
// 왼쪽 2칸, 오른쪽 2칸 중 가장 높은 아파트의 층수와 현재 기준 아파트의 층수를 빼면 조망이 확보된 세대 수
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1001
int N, answer;
int apartment[MAX_SIZE];

int main()
{
    fastio;
    for (int t = 1; t <= 10; t++)
    {
        cin >> N;
        answer = 0;
        memset(apartment, 0, sizeof(apartment));
        for (int i = 0; i < N; i++)
            cin >> apartment[i];

        // 2부터 시작해서 N-3 까지.. 왼쪽 두개 0, 1, 오른쪽 두개 N-2, N-1
        for (int i = 2; i < N - 2; i++)
        {
            int current_height = apartment[i];
            // 양쪽 4개의 아파트 중에서 가장 높은 아파트의 층 수를 구함
            int max_height = max(apartment[i - 2], max(apartment[i - 1], max(apartment[i + 1], apartment[i + 2])));
            if (current_height > apartment[i - 2] &&
                current_height > apartment[i - 1] &&
                current_height > apartment[i + 1] &&
                current_height > apartment[i + 2])
                answer += current_height - max_height;
        }
        cout << "#" << t << " " << answer << "\n";
    }
}