// 세 수의 합 G4
// 자료 구조, 이분 탐색

/*
a[i] + a[j] + a[k] = a[l]
4중 for 문으로 해결 --> 시간 초과 (N^4)

3중 for 문 (i,j,k 로 합 구하고), 이분 탐색 (총 합이 배열에 존재하는지) --> 시간초과 (N^3lgN)

a[i] + a[j] = two[m] 로 설정하고 --> two[m] + a[k] = a[l]
2중 for문 a[l] - a[k], 이분 탐색 two[m] 에 존재하는지 --> (N^2lgN^2 = 2N^2lgN)
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1010
int arr[MAX_SIZE];
vector<int> twoSum;
int n;
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    // 두 수의 합에 대한 배열
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            twoSum.push_back(arr[i] + arr[j]);
    sort(twoSum.begin(), twoSum.end());

    // 두 수의 차가 두 수의 합 배열에 존재하는지 이분 탐색
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            if (binary_search(twoSum.begin(), twoSum.end(), arr[i] - arr[j]))
            {
                cout << arr[i];
                return 0;
            }
}