#include <iostream>
using namespace std;
int main()
{
    int remain, count;
    cin >> remain;
    count = remain / 50000;
    remain %= 50000;
    count += remain / 10000;
    remain %= 10000;
    count += remain / 5000;
    remain %= 5000;
    count += remain / 1000;
    remain %= 1000;
    count += remain / 500;
    remain %= 500;
    count += remain / 100;
    remain %= 100;
    count += remain / 50;
    remain %= 50;
    count += remain / 10;

    cout << count;
}