#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x = ((a < b) ? a : b);
    cout << ((x < c) ? x : c);
}