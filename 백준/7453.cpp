// 합이 0 인 네 정수 G2
// 투포인터, 정렬, 이분 탐색
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[4001][4];
vector<int> a, b;

int main()
{
    long long count = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 4; j++)
            cin >> arr[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            a.push_back(arr[i][0] + arr[j][1]);
            b.push_back(arr[i][2] + arr[j][3]);
        }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // for (int i = 0; i < a.size(); i++)
    // {
    //     for (int j = 0; j < b.size(); j++)
    //     {

    //     }
    // }
    int first = 0, end = a.size() - 1;
    while (first < a.size() && end >= 0)
    {
        if (a[end] + b[first] == 0)
        {
            int targetA = 0, targetB = 0;
            int temp = b[first];
            while ((-a[end] == temp) && end >= 0)
                targetA++, end--;
            while ((b[first] == temp && first < a.size()))
                targetB++, first++;
            // 쌍으로 곱해서 세는 것
            count += (long long)targetA * targetB;
        }
        // 절댓값 비교
        else if (-a[end] < b[first])
            end--;
        else
            first++;
    }
    cout << count;
}