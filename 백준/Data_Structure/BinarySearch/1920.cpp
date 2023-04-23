// 수 찾기 S4
// 자료 구조, 이분 탐색, 정렬
#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 100005
int arr[MAX_SIZE];
int n, m;
int binarySearch(int target)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] < target)
            start = mid + 1;
        else if (arr[mid] > target)
            end = mid - 1;
        else
            return 1;
    }
    return 0;
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int target;
        cin >> target;
        cout << binarySearch(target) << "\n";
    }
}

/* STL 의 binary_search 함수 사용
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int target;
        cin >> target;
        cout << binary_search(arr, arr + n, target) << "\n";
    }
}
*/