// 하노이 탑 이동 순서 S1
// 재귀
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
void hanoi(int n, int start, int to, int bypass)
{
    if (n == 1)
        cout << start << " " << to << "\n";
    else
    {
        hanoi(n - 1, start, bypass, to);
        cout << start << " " << to << "\n";
        hanoi(n - 1, bypass, to, start);
    }
}
int main()
{
    fastio;
    int num;
    cin >> num;
    // 2^num - 1
    cout << (1 << num) - 1 << "\n";
    hanoi(num, 1, 3, 2);
}