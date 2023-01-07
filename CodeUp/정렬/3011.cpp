/* 거품 정렬
거품 정렬은 인접한 인덱스를 비교하여 더 큰 인덱스를 뒤로 보내는 정렬이다.
단계 수가 올라갈 수록 i++이고, i 만큼의 뒷 쪽 배열들이 정렬되어 있다는 것을 의미한다.
따라서 j=n-1-i 만큼만 비교를 하여 이미 정렬 된 배열과 비교를 통해 check 를 증가시키면 되고 check가 n-1-i와 같다면 정렬이 완료됐음을 알 수 있다.
정렬 단계를 올릴 때마다 count를 증가시켜서 몇 단계 까지 정렬이 완료되었는지 알 수 있다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // 이미 오름차순이 완료 된 벡터 하나를 더 만든다. 지금부터 이 벡터와 비교 할 것이다.
    vector<int> v2(v);
    sort(v2.begin(), v2.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        // check는 단계 시작 전에 0으로 초기화 된다.
        int check = 0;
        // i만큼 뒷 부분은 정렬이 완료 되었으므로 n-1-i 까지
        for (int j = 0; j < n - 1 - i; j++)
        {
            // 오른쪽보다 왼쪽이 더 크다면 위치를 바꾼다.
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
            // 정렬 완료된 벡터와 비교하여 check 를 센다.
            if (v[j] == v2[j])
                check++;
        }
        // 단계를 올릴 때 count 를 증가시킨다.
        count++;
        if (check == n - 1 - i)
            break;
    }
    cout << count;
}