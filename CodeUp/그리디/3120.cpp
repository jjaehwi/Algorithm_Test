#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int count;
    count = abs(a - b) / 10;
    int remains = abs(a - b) % 10;

    if (remains == 1 || remains == 5)
        count += 1;
    else if (remains == 2 || remains == 4 || remains == 6 || remains == 9)
        count += 2;
    else if (remains == 3 || remains == 7 || remains == 8)
        count += 3;

    cout << count;
}