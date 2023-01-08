#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v(7);
    for (int i = 0; i < 7; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<>());

    cout << v[0] << "\n"
         << v[1];
}