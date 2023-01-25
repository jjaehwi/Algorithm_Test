// 거스름돈 B2
// 그리디 알고리즘
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int money, cnt;
int main()
{
    fastio;
    cin >> money;
    money = 1000 - money; // 620원
    cnt += money / 500;
    money = money % 500;
    cnt += money / 100;
    money = money % 100;
    cnt += money / 50;
    money = money % 50;
    cnt += money / 10;
    money = money % 10;
    cnt += money / 5;
    money = money % 5;
    cnt += money / 1;
    cout << cnt;
}