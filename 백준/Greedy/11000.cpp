// 강의실 배정 G5
// 그리디, 정렬, 자료구조, 우선 순위 큐
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int n, cnt;
struct lecture
{
    int start;
    int end;
};
bool compare(lecture a, lecture b)
{
    return a.start < b.start;
}
int main()
{
    fastio;
    cin >> n;
    vector<lecture> v(n);
    // 오름차순 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
        cin >> v[i].start >> v[i].end;

    // 시작 시간 순으로 정렬
    sort(v.begin(), v.end(), compare);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i].start << " " << v[i].end << "\n";
    // }
    pq.push(v[0].end);
    for (int i = 1; i < n; i++)
    {
        if (v[i].start >= pq.top())
        {
            pq.pop();
            pq.push(v[i].end);
        }
        else
            pq.push(v[i].end);
    }

    cout << pq.size() << "\n";
}

// 시작 시간이 끝나는 시간보다 빠르면 push
// 시작 시간이 끝나는 시간보다 느리면 갱신