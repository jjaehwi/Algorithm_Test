// 나무 자르기 S2
// 이분 탐색, 매개 변수 탐색
#include <iostream>
#include <algorithm>
#include <vector>

#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
using namespace std;

int main()
{
    fastio;
    long long N, M;
    cin >> N >> M;
    vector<long long> tree(N);
    for (int i = 0; i < N; i++)
        cin >> tree[i];
    sort(tree.begin(), tree.end()); // 오름차순 정렬
    long long low = 0;
    long long high = tree[N - 1];
    long long mid;
    long long tree_length;
    long long result = 0;
    while (low <= high)
    {
        // mid 값 초기화
        mid = (low + high) / 2;
        tree_length = 0;

        // 나무 자르기
        for (int i = 0; i < N; i++)
        {
            // 절단기가 나무 크기보다 작은 경우 잘림
            if (mid < tree[i])
                tree_length += tree[i] - mid;
        }
        // 요구하는 길이와 딱 맞는 경우 최적의 해 이므로 종료
        if (tree_length == M)
        {
            result = mid;
            break;
        }
        // 자른 나무 길이가 요구하는 길이보다 더 큰 경우
        if (tree_length > M)
        {
            // 나무길이를 최소화 하려면 절단기의 설정 길이를 최대로 해야한다
            if (result < mid)
                result = mid;
            low = mid + 1;
        }
        // 자른 나무 길이가 요구하는 길이보다 더 작은 경우
        if (tree_length < M)
            high = mid - 1;
    }
    cout << result;
}