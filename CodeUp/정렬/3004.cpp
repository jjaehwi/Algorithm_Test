#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 데이터 오름차순 정렬
bool compare1(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.first < b.first;
}

// 입력받은 순서 오름차순 정렬
bool compare2(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.second.first < b.second.first;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;     // 데이터 입력
        v[i].second.first = i; // 입력 받은 순서
    }

    sort(v.begin(), v.end(), compare1);

    // 오름차순으로 정렬된 데이터에 순위 입력
    for (int i = 0; i < n; i++)
        v[i].second.second = i;

    // 입력 받은 순서대로 다시 오름차순 정렬
    sort(v.begin(), v.end(), compare2);

    for (int i = 0; i < n; i++)
    {
        cout << v[i].second.second << " ";
    }
}

/* 시간 초과 나온 코드 --> 이중 for 문을 썻기 때문.. 더 효율적으로 O(N) 이나 O(NlogN) 알고리즘으로 설계 해야함.
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
vector<int> ranking;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
        ranking.push_back(0);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (v[i] > v[j])
                ranking[i]++;

    for (int i = 0; i < n; i++)
        cout << ranking[i] << " ";
}

*/