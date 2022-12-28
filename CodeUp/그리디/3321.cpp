#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, A, B, C;
    cin >> N;
    cin >> A >> B;
    cin >> C;
    vector<int> topping;
    int totalKcal = C;
    int price = A;
    int perKcal = totalKcal / price;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        topping.push_back(a);
    }
    // 내림차순으로 정렬
    sort(topping.rbegin(), topping.rend());

    for (int i = 0; i < N; i++)
    {
        if (perKcal < (topping[i] / B))
        {
            price += B;
            totalKcal += topping[i];
            perKcal = totalKcal / price;
        }
        else
            break;
    }
    cout << perKcal;
}