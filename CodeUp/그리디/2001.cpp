#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int p1, p2, p3, j1, j2;
    cin >> p1 >> p2 >> p3 >> j1 >> j2;
    int min = 4000;

    vector<int> pasta;
    pasta.push_back(p1);
    pasta.push_back(p2);
    pasta.push_back(p3);

    vector<int> juice;
    juice.push_back(j1);
    juice.push_back(j2);

    for (int i = 0; i < pasta.size(); i++)
        for (int j = 0; j < juice.size(); j++)
        {
            if (pasta[i] + juice[j] < min)
                min = pasta[i] + juice[j];
        }
    cout << fixed;
    cout.precision(1);
    cout << min + min * 0.1;
}