// 숫자 카드 2 S4
// 자료 구조, 이분 탐색, 정렬
#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 500005
int arr[MAX_SIZE];
int n, m;
int lowerIndex(int target, int length)
{
    int start = 0;
    // 들어갈 수 있는 위치가 끝 자리도 되므로
    int end = n;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] >= target)
            end = mid;
        else
            start = mid + 1;
    }
    return start;
}
int upperIndex(int target, int length)
{
    int start = 0;
    int end = n;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] > target)
            end = mid;
        else
            start = mid + 1;
    }
    return start;
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
        cout << upperIndex(target, n) - lowerIndex(target, n) << "\n";
    }
}

/*
STL 풀이
두 함수가 반환하는 값은 위의 함수와 똑같이 target이 들어갈 수 있는 가장 왼쪽 위치와 오른쪽 위치를 반환한다.
인자는 binary_search 와 똑같이 첫 번째와 두 번째 인자로 범위
#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 500005
int arr[MAX_SIZE];
int n, m;
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
        cout << upper_bound(arr, arr + n, target) - lower_bound(arr, arr + n, target) << "\n";
    }
}
*/
