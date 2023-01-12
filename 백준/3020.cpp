// lower, upper bound 이해 : https://breakcoding.tistory.com/188
#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

using namespace std;

int main()
{
    fastio;
    int N, H;
    cin >> N >> H;
    // 석순, 종유석을 따로 저장
    vector<int> bottom, top;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (i % 2 == 0)
            bottom.push_back(num);
        else
            top.push_back(num);
    }
    sort(bottom.begin(), bottom.end(), greater<>());
    sort(top.begin(), top.end(), greater<>());

    int result = 200001;
    int count = 0;

    for (int i = 1; i <= H; i++)
    {
        // 오름차순이기 때문에 개똥벌레의 높이인 i까지의 인덱스를 알아내고 처음부터 거기까지의 개수를 알면 된다.
        // 부셔지는 석순 = 전체 석순 개수 - i까지의 인덱스 개수
        int barrier = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());

        // 부셔지는 종유석 = 전체 종유석 개수 - H-i까지의 인덱스 개수
        barrier += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());

        // 현재 높이에서 부신 장애물과, 이전까지의 부신 장애물의 최소와 같다면 count 증가
        if (result == barrier)
            count++;

        // 부셔진 게 가장 적은걸로 초기화 되면 count도 초기화
        if (result > barrier)
        {
            result = barrier;
            count = 1;
        }
    }
    cout << result << " " << count << "\n";
    return 0;
}

// 2중 for 문으로 시간초과 난 코드
/*
#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

using namespace std;

int main()
{
    fastio;
    int N, H;
    cin >> N >> H;
    // 석순, 종유석을 따로 저장
    vector<int> s, j;
    vector<int> interval;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (i % 2 == 0)
            s.push_back(num);
        else
            j.push_back(num);
    }
    // 몇개 부셨는지, 구간은 몇갠지

    int min = 200000;
    int count = 0;

    // i = 개똥벌레 높이
    for (int i = 1; i <= H; i++)
    {
        int barrier = 0;
        for (int idx = 0; idx < N / 2; idx++)
        {
            // 석순을 부심
            if (i <= s[idx])
                barrier++;
            // 종유석을 부심
            if (H - j[idx] < i)
                barrier++;
        }
        interval.push_back(barrier);
        if (barrier < min)
            min = barrier;
    }
    for (int i = 0; i < H; i++)
        if (interval[i] == min)
            count++;

    cout << min << " " << count;
}
*/