// 스위치 켜고 끄기 S4
// 구현, 시뮬레이션
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 101

int n, arr[MAX_SIZE], student, g, y, i, k;

int main()
{
    fastio;
    cin >> n;

    // 스위치의 상태 입력 받기
    for (i = 1; i <= n; i++)
        cin >> arr[i];

    cin >> student;
    for (k = 0; k < student; k++)
    {
        // 학생의 성별, 번호 입력
        // 남학생 1, 여학생 2
        cin >> g >> y;

        if (g == 1) // 남학생일 때
        {
            for (i = 1; i <= n; i++)
                if (i % y == 0)       // 배수일 때
                    arr[i] = !arr[i]; // 스위치의 상태를 바꾼다.
        }
        else // 여학생일 때
        {
            arr[y] = !arr[y];                          // 우선 자기자신(중심)의 상태를 바꾼다.
            for (i = 1; arr[y + i] == arr[y - i]; i++) // 대칭이라면 실행
            {
                if (y + i > n || y - i < 1) // 인덱스가 벗어나면 멈춘다.
                    break;
                arr[y + i] = !arr[y + i]; // 상태 바꾸기
                arr[y - i] = !arr[y - i]; // 상태 바꾸기
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
        if (i % 20 == 0) // 한 줄에 20개씩 출력
            cout << "\n";
    }
}