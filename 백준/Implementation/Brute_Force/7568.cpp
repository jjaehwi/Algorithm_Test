// 덩치 S5
// 브루트 포스, 구현
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
struct body
{
    int weight;
    int height;
    int rank;
};
int n;
vector<body> v;
int main()
{
    fastio;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        v[i].rank = 1;
        cin >> v[i].weight >> v[i].height;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 본인
            if (v[i].height == v[j].height && v[i].weight == v[j].weight)
                continue;
            else if (v[i].height < v[j].height && v[i].weight < v[j].weight)
                v[i].rank++;
            else
                continue;
        }
    }
    for (int i = 0; i < n; i++)
        cout << v[i].rank << " ";
}