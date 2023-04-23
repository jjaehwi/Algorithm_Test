// 틀림
// 사탕상자 P5
// 자료구조, 세그먼트 트리, 이분 탐색
#include <iostream>

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
#define MAX 1 << 21

using namespace std;

long long tree[MAX];
int idx = 1;

void update(long long b, long long c)
{
    b += idx - 1;
    tree[b] += c;
    while (b /= 2)
    {
        tree[b] = tree[b * 2] + tree[(b * 2) + 1];
    }
}

long long search(long long b, long long c)
{
    if (c >= idx)
    {
        update(c - idx + 1, -1);
        return c - idx + 1;
    }
    if (b <= tree[2 * c])
        return search(b, c * 2);
    else
        return search(b - tree[2 * c], c * 2 + 1);
}

int main()
{
    fastio;

    int N, a;
    long long b, c;
    cin >> N;
    while (idx < N)
        idx <<= 1;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            cout << search(b, 1) << "\n";
        }
        else
        {
            cin >> b >> c;
            update(b, c);
        }
    }
}