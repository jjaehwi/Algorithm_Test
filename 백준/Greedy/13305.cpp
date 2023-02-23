// 주유소 S3
// 그리디
#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000000000 // 10억
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int n;
long long sum;
long long temp = MAX;
int main()
{
    fastio;
    cin >> n;
    vector<long long> distance(n);
    vector<long long> price(n);
    // 거리 저장
    for (int i = 1; i < n; i++)
        cin >> distance[i];
    // 도시 별 기름 가격 저장
    for (int i = 1; i <= n; i++)
        cin >> price[i];
    for (int i = 1; i < n; i++)
    {
        if (price[i] < temp)
            temp = price[i];
        sum += temp * distance[i];
    }
    cout << sum;
}