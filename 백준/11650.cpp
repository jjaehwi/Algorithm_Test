// 좌표 정렬하기 S5
// 정렬, 구조체 comparator
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
struct coordinate
{
    int x;
    int y;
};
vector<coordinate> v;
int n;
bool compare(coordinate v1, coordinate v2)
{
    if (v1.x == v2.x)
        return v1.y < v2.y;
    return v1.x < v2.x;
}
int main()
{
    fastio;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].x >> v[i].y;
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++)
        cout << v[i].x << " " << v[i].y << "\n";
}