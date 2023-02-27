// 음계 B2
// 구현
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int resultCase = 0;
    vector<int> v(8);
    for (int i = 0; i < 8; i++)
        cin >> v[i];
    if (v[0] == 1 && v[7] == 8)
    {
        for (int i = 0; i < 7; i++)
        {
            if (v[i + 1] - v[i] == 1)
            {
                resultCase = 1;
                continue;
            }
            else
            {
                resultCase = 0;
                break;
            }
        }
    }
    if (v[0] == 8 && v[7] == 1)
    {
        for (int i = 0; i < 7; i++)
        {
            if (v[i + 1] - v[i] == -1)
            {
                resultCase = 2;
                continue;
            }
            else
            {
                resultCase = 0;
                break;
            }
        }
    }
    if (resultCase == 1)
        cout << "ascending";
    else if (resultCase == 2)
        cout << "descending";
    else
        cout << "mixed";
}