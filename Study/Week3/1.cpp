// 백준 2110번 G4
// 이분탐색
#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

using namespace std;

int N, C;
vector<long long> v;

int max_dist()
{
    int left = 0;
    int right = v[N - 1] - 1; // 처음부터 끝까지 간격
    int interval;             // 결과를 저장하기 위함
    while (left <= right)
    {
        // 설치된 공유기 수
        int count = 1;
        // mid 간격 갱신
        int mid = (left + right) / 2;

        long long start = v[0]; // 시작 공유기 위치

        for (int i = 1; i < N; i++)
        {
            long long end = v[i];
            // 공유기 간격이 기준 간격을 넘는지 확인, 넘는 다면 공유기를 설치하고, 그 때 공유기가 놓인 위치를 시작 위치로 변경
            if (end - start >= mid)
            {
                count++;
                start = end;
            }
        }
        // 공유기 간격 탐색이 끝난 뒤(for문 끝난 뒤), 설치한 공유기 개수가 C개 이상이라면,
        if (count >= C)
        {
            // 공유기 설치에 사용된 간격을 저장
            interval = mid;
            // 이분법을 사용한 간격 갱신 시, 이전보다 넓은 간격을 사용하기 위해, L 수정
            left = mid + 1;
        }
        else
        {
            // 이분법을 사용한 간격 갱신 시, 이전보다 좁은 간격을 사용하기 위해, R 수정
            right = mid - 1;
        }
    }
    return interval;
}

int main()
{
    fastio;
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        int router_idx;
        cin >> router_idx;
        v.push_back(router_idx);
    }
    sort(v.begin(), v.end());
    cout << max_dist();
}