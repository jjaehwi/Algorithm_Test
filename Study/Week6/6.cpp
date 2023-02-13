// 탑승구
// 서로소 집합, 그리디

#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
#define MAX_SIZE 100001
int g, p;
int parent[MAX_SIZE];
int result;

int find(int index)
{
    if (parent[index] == index)
        return index;

    int ans = find(parent[index]);
    parent[index] = ans;
    return ans;
    // return parent[index] = find(parent[index]);
}

void Union(int a, int b)
{
    // 두 개의 루트를 각각 찾는다.
    a = find(a);
    b = find(b);

    // a의 루트를 b로 설정해준다. (거꾸로 해도 상관 x)
    parent[a] = b;
}

int main()
{
    fastio;
    cin >> g >> p;

    // 초기화
    for (int i = 1; i <= g; i++)
        parent[i] = i;

    while (p--)
    {
        int plane;
        cin >> plane;

        // 도킹이 불가능한 상황이라면 종료
        if (find(plane) == 0)
            break;
        else
        {
            result++;
            Union(find(plane), find(plane) - 1);
        }
    }
    cout << result;
}