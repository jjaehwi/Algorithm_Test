// 올림픽 S5
// 구현, 정렬

// 1. 금메달 수가 더 많은 나라
// 2. 금메달 수가 같으면, 은메달 수가 더 많은 나라
// 3. 금, 은메달 수가 같으면 동메달 수가 더 많은 나라
// 금, 은, 동메달 수가 모두 같다면 두 나라의 등수는 같다.

// 한 국가의 등수는 (자신보다 더 잘한 나라 수) + 1로 정의된다.

#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1001
int N, K, res, same;
struct medal
{
    int countryNum;
    int gold;
    int silver;
    int bronze;
};
medal country[MAX_SIZE];

bool compare(medal a, medal b)
{
    if (a.gold > b.gold)
        return true;
    if (a.gold == b.gold)
    {
        if (a.silver > b.silver)
            return true;
        if (a.silver == b.silver)
        {
            if (a.bronze > b.bronze)
                return true;
        }
    }
    return false;
}

int main()
{
    fastio;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> country[i].countryNum >> country[i].gold >> country[i].silver >> country[i].bronze;

    sort(country, country + N, compare);

    // 원하는 나라의 등수 체크
    for (int i = 0; i < N; i++)
        if (country[i].countryNum == K)
            res = i;

    // 동일한 등수에 대해 카운트
    for (int i = res - 1;; i--)
    {
        if (country[i].gold != country[res].gold || country[i].silver != country[res].silver || country[i].bronze != country[res].bronze)
            break;
        same++;
    }
    cout << res - same + 1 << "\n";
}