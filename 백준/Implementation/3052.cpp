// 나머지 B2
// 구현, 수학
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int main()
{
    fastio;
    vector<int> vNum;
    vector<int> vAns(10);
    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        int num;
        cin >> num;
        vNum.push_back(num);
        vAns[i] = -1;
    }

    for (int i = 0; i < 10; i++)
    {
        bool check = true;
        int remain = vNum[i] % 42;
        // cout << "remain : " << remain << "\n";
        for (int j = 0; j < 10; j++)
        {
            if (vAns[j] == remain)
            {
                check = false;
                break;
            }
        }
        // cout << "check : " << check << "\n";
        if (check)
            vAns[i] = remain;
    }

    // for (int i = 0; i < 10; i++)
    //     cout << vAns[i] << " ";
    for (int i = 0; i < 10; i++)
    {
        if (vAns[i] != -1)
            count++;
        else
            continue;
    }
    cout << count;
}