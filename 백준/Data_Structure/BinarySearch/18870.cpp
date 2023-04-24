// 좌표 압축 S2
// 자료 구조, 이분 탐색, 값 / 좌표 압축 (중복 제거)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1000010
int arr[MAX_SIZE];
int copyArr[MAX_SIZE];
vector<int> uni;
int n;
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        copyArr[i] = arr[i];
    }

    sort(copyArr, copyArr + n);
    // 중복 제거
    uni.push_back(copyArr[0]);
    for (int i = 1; i < n; i++)
    {
        if (copyArr[i - 1] == copyArr[i])
            continue;
        else
            uni.push_back(copyArr[i]);
    }

    // for (int i = 0; i < n; i++)
    //     cout << uni[i] << " ";
    // cout << "\n";

    for (int i = 0; i < n; i++)
        cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin() << " ";
}

/*
STL unique 함수로 중복 제거
unique는 정렬된 배열에서 실행을 시켜야하고, 이렇게 말그대로 중복이 제거된 원소들을 앞으로 모아줌.
뒤쪽에는 쓰레기 값들이 들어감.
쓰레기 값이 시작되는 구간을 return
vector의 erase를 이용해서 뒤쪽을 날림

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        uni.push_back(arr[i]);
    }
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    for (int i = 0; i < n; i++)
        cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin() << " ";
}
*/