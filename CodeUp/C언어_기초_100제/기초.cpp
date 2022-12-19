#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int year, month, day;
    char dot1, dot2;
    cin >> year >> dot1 >> month >> dot2 >> day;
    cout.width(4);
    cout.fill('0');
    cout << year << dot1;
    cout.width(2);
    cout.fill('0');
    cout << month << dot2;
    cout.width(2);
    cout.fill('0');
    cout << day;
}