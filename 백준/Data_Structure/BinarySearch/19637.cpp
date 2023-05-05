// IF문 좀 대신 써줘 S3
// 자료구조, 이분탐색
#include <iostream>
#include <cstring>
#define INF 987654321
using namespace std;

int n, m;
int power[100000];
string title[100000];

int binsearch(int p)
{
    int mid = 0, left = 0, right = n - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (p <= power[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    if (p > power[mid])
        return mid + 1;
    else
        return mid;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> title[i] >> power[i];
    int p;
    for (int i = 0; i < m; i++)
    {
        cin >> p;
        cout << title[binsearch(p)] << "\n";
    }
    return 0;
}