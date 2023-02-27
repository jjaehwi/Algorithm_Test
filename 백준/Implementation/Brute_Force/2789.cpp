// 블랙잭 B2
// 알고리즘 분류 - 브루트포스 알고리즘
#include <iostream>
#define MAX 100
using namespace std;

int main()
{
    int num, target, goal, sum = 0;
    int min = 9999999;
    int arr[MAX] = {
        0,
    };
    cin >> num >> target;
    for (int i = 0; i < num; i++)
        cin >> arr[i];

    for (int i = 0; i < num - 2; i++)
        for (int j = i + 1; j < num - 1; j++)
            for (int k = j + 1; k < num; k++)
            {
                sum = arr[i] + arr[j] + arr[k];
                if (target - sum < min && target - sum >= 0)
                {
                    min = target - sum;
                    goal = sum;
                }
            }
    cout << goal;
}