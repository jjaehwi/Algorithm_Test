/* 풀이 1
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
*/

// 풀이 2
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n;
    vector<string> name;
    vector<int> score;
    vector<int> rank;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a;
        int b;
        cin >> a >> b;
        name.push_back(a);
        score.push_back(b);
        rank.push_back(1);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (score[i] < score[j])
                rank[i]++;
    for (int i = 0; i < n; i++)
        if (rank[i] == 3)
            cout << name[i];
}