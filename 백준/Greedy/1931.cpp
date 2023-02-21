// 회의실 배정 S1
// 그리디, 정렬
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
struct booking
{
    int start;
    int end;
};

bool compare(booking a, booking b)
{
    // 중요
    if (a.end == b.end) // 같으면 시작시간 빠른 것 부터 나열
        return a.start < b.start;
    return a.end <= b.end;
}
int main()
{
    fastio;
    int n;
    cin >> n;
    vector<booking> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    // 마감 시간 기준 오름차순 정렬
    sort(v.begin(), v.end(), compare);
    int startTime = v[0].end;
    int count = 1;
    for (int i = 1; i < n; i++)
        if (startTime <= v[i].start)
        {
            count++;
            startTime = v[i].end;
        }
    cout << count;
}