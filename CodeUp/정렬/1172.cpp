#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v;
    for (int i = 0; i < 3; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end()), greater<>();
    for (int i = 0; i < 3; i++)
        cout << v[i] << " ";
}