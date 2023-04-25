// 랜선 자르기 S2
// 이분 탐색, 매개 변수 탐색

// N개를 만들 수 있는 랜선의 최대 길이를 구하는 최적화 문제
// 이를 결정 문제로 바꾸려면,,
// 반대로 우리가 구해야 하는 답이 인자로 들어가고, 조건의 참/거짓 여부를 판단하는 문제로 만들어야한다.

// st, mid, en 을 놓고 범위를 줄여가며 답을 찾아본다.
// 랜선의 길이가 mid 일 때 랜선이 N개 미만 --> mid 이상은 절대 답이 될 수 없으니 en = mid - 1로 바꿈
// 랜선의 길이가 mid 일 때 랜선이 N개 이상이었다면 st = mid 로 바꿈

// 이렇게 최대 길이를 구해야하는 문제에서 랜선의 길이가 X일 때 조건을 만족하는지 확인하는 문제로 변환해서 풀이할 수 있다.
// 이분탐색을 수행할 변수를 가지고 함수를 세웠을 때 함수가 증가, 감소 함수여야한다.

// parametric search를 할 때에는 최적화 문제를 결정 문제로 바꿀 수 있는지 생각하고,
// 그 결정 문제로 얻어낸 함수가 감소 혹은 증가함수인지를 따져봐야하는 것

#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 10001
int k, n;
int arr[MAX_SIZE];

bool solve(long long length)
{
    // 잘린 랜선 개수
    long long num = 0;
    for (int i = 0; i < k; i++)
        num += arr[i] / length;

    return num >= n;
}

int main()
{
    fastio;
    cin >> k >> n;
    for (int i = 0; i < k; i++)
        cin >> arr[i];

    long long start = 1;
    long long end = 0x7fffffff; // 2^31 - 1

    while (start < end)
    {
        // mid = (st+en+1)/2 로 둬야 무한 루프에 빠지지 않는다.
        // mid = (st+en)/2 로 두면 전에 본 것 처럼 st 와 en 이 1 차이날 때 st 가 계속 값이 똑같아버릴 수 있습니다.
        long long mid = (start + end + 1) / 2;
        if (solve(mid))
            start = mid;
        else
            end = mid - 1;
    }
    cout << start;
}