// 배 G5
// 그리디, 정렬
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int N, M, cnt;
vector<int> crane;
vector<int> box;

int main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        crane.push_back(n);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int m;
        cin >> m;
        box.push_back(m);
    }

    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());

    // 불가능한 경우
    if (crane.back() < box.back())
    {
        cout << -1;
        return 0;
    }

    while (!box.empty())
    {
        cnt++;
        // 크레인 가장 큰 무게 부터
        for (int i = crane.size() - 1; i >= 0; i--)
            // 상자 가장 큰 무게 부터
            for (int j = box.size() - 1; j >= 0; j--)
                // 옮길 수 있으면 삭제하고 다음 크레인으로
                if (crane[i] >= box[j])
                {
                    box.erase(box.begin() + j);
                    break;
                }
    }

    cout << cnt;
    return 0;
}