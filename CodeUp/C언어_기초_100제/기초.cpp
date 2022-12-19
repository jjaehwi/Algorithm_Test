#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cout << fixed;
    cout.precision(2);
    cin >> a >> b;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << a % b << endl;
    cout << (float)a / b << endl;
}