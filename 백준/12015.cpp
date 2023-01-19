// 가장 긴 증가하는 부분 수열 2 LIS (최장증가수열)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nowNum;
    int n;
    cin >> n;
    int ans = 0;
    vector<int> vecLIS;
    vecLIS.push_back(-987654321); // 아무것도 없는 상황에서도 이진탐색은 돌아야하니까 엄청 작은 값을 넣어둠

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nowNum);
        // 벡터의 끝 값 < 현재 수열의 값
        // -> vector에 현재 값 push, ans++
        if (vecLIS.back() < nowNum)
        {
            vecLIS.push_back(nowNum);
            ans++;
        }
        // 벡터의 끝 값 >= 현재 수열의 값
        // -> 이진탐색으로 vector에 들어갈 수 있는 최적 위치를 찾은 후
        // -> 그 vector의 자리 값을 현재 수열의 값(arr[i])으로 바꾼다!
        else
        {
            // vector에는 LIS가 되는 값들이 들어오므로.. 정렬이 된 상태
            // 그래서 이진탐색이 가능하다.
            auto it = lower_bound(vecLIS.begin(), vecLIS.end(), nowNum); // 현재 위치 나옴
            *it = nowNum;
        }
    }
    printf("%d\n", ans);
}

/* dp로 작성하기. (마무리 안됨)
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 501
using namespace std;
int main(){
    int n;
    int arr[MAX_SIZE];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",arr[i]);

}
1. 수열을 처음부터 끝까지 순서대로 1개씩 탐색한다. (현재 위치는 i)
2. dp[i]에 넣을 값을 초기화함. (0으로))
3. 현재 위치보다 이전에 있는 원소(j) 중에서 현재 원소보다 작은지 체크한다. (크거나 같으면 LIS 불가능함)
4. 현재 원소보다 작다면 dp[j]가 val 보다 큰지 체크
    --> 이 때 dp[j]가 val 보다 크다면 (dp[j] > val)
    --> j번째 원소를 포함했을 때가 지금까지의 LIS보다 더 길다는 뜻!
    --> val 에 dp[j]를 할당해준다.
5. 현재 원소도 포함해주어야하므로 최종적으로 dp[i]에 val + 1 을 할당해준다.
6. dp 배열의 원소 중에서 가장 큰 값을 출력한다.

dp[0] = 1;
for(int i=0; i<n; i++){
    int val = 0;

    // i 번째 인덱스에서 끝나는 최장 부분수열의 길이를 구하는 것!
    for(int j=0; j<i; j++){
        if(arr[j] < arr[i]){
            val = max(val, dp[j]); // dp[j]는 1 ~ i-1까지의 LIS 최장 길이 값
        }
    }
    dp[i] = val + 1; // 자신 포함
}
int ans = 0;
...
*/
