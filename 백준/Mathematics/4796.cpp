// 캠핑 B1
// 수학, 그리디
#include <iostream>
using namespace std;

int main()
{
    int i = 0, l, p, v, res = 0;
    while (true)
    {
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0)
            break;
        // min(v%p, l) 중 l 이 들어가는 경우는 5,8,7 같은 경우..
        res = (v / p) * l + min(v % p, l);
        cout << "Case " << ++i << ": " << res << "\n";
    }
    return 0;
}