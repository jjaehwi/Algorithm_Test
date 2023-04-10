// 걷기 S4
// 그리디
#include <iostream>
using namespace std;

int main()
{

    long long X, Y, W, S;
    cin >> X >> Y >> W >> S;

    long long case_A = (X + Y) * W;
    long long case_B = min(X, Y) * S;
    case_B += min(abs(X - Y) * W, (abs(X - Y) % 2 == 1 ? (abs(X - Y) - 1) * S + W : abs(X - Y) * S));

    cout << min(case_A, case_B);
}
