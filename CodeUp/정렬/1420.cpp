#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<pair<string, int>> v;

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int score;
        cin >> name >> score;
        v.push_back(pair<string, int>(name, score));
    }
    sort(v.begin(), v.end(), compare);
    cout << v[2].first;
}
