#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int a = num / 10000;
    int b = (num - a * 10000) / 1000;
    int c = (num - a * 10000 - b * 1000) / 100;
    int d = (num - a * 10000 - b * 1000 - c * 100) / 10;
    int e = (num - a * 10000 - b * 1000 - c * 100) % 10;
    cout << "[" << a * 10000 << "]\n";
    cout << "[" << b * 1000 << "]\n";
    cout << "[" << c * 100 << "]\n";
    cout << "[" << d * 10 << "]\n";
    cout << "[" << e << "]\n";
}