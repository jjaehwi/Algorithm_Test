#include <iostream>
using namespace std;
#define MAX 1000001
long long tree[MAX];
int idx = 1;

void init()
{
    for (int i = idx - 1; i > 0; i--)
        tree[i] = tree[i * 2] + tree[(i * 2) + 1];
}

long long intervalSum(int x, int y)
{
    long long sum = 0;
    x += idx - 1;
    y += idx - 1;
    while (x <= y)
    {
        if ((x % 2) == 1) // x가 트리의 right일 때
            sum += tree[x];
        if ((y % 2) == 0) // y가 트리의 left일 때
            sum += tree[y];

        x = (x + 1) / 2;
        y = (y - 1) / 2;
    }
    return sum;
}

void update(int a, long long b)
{
    a += idx - 1;
    tree[a] = b;
    while (a /= 2)
        tree[a] = tree[a * 2] + tree[(a * 2) + 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, Q, x, y, a;
    long long b;
    cin >> N >> Q;
    while (idx < N)
        idx <<= 1;
    for (int i = idx; i < idx + N; i++)
        cin >> tree[i];
    init();
    for (int i = 0; i < Q; i++)
    {
        cin >> x >> y >> a >> b;
        if (x > y)
        {
            int temp = x;
            x = y;
            y = temp;
        }
        cout << intervalSum(x, y) << "\n";
        update(a, b);
    }
    return 0;
}