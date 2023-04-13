// 집합 S5
// 구현, 비트마스킹
#include <iostream>
#include <cstring>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 21
int M;
int arr[MAX_SIZE];
int main()
{
    fastio;
    cin >> M;
    while (M--)
    {
        int num;
        string str;
        cin >> str;

        if (str == "add")
        {

            cin >> num;
            if (arr[num] == 1)
                continue;
            arr[num] = 1;
        }
        else if (str == "remove")
        {
            cin >> num;
            if (arr[num] == 0)
                continue;
            arr[num] = 0;
        }
        else if (str == "check")
        {
            cin >> num;
            if (arr[num] == 0)
                cout << "0\n";
            else
                cout << "1\n";
        }
        else if (str == "toggle")
        {
            cin >> num;
            if (arr[num] == 1)
                arr[num] = 0;
            else
                arr[num] = 1;
        }
        else if (str == "all")
        {
            for (int i = 1; i <= 20; i++)
                arr[i] = 1;
        }
        else if (str == "empty")
        {
            memset(arr, 0, sizeof(arr));
        }
    }
    return 0;
}