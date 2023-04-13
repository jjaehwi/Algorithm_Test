// N번째 큰 수 S2
// 자료 구조, 정렬, 우선순위 큐

//  우선순위 큐에 N 개를 추가하고 N 개를 제거하는 방식 --> 메모리를 아낄 수 있다.
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int N;
int main()
{
    fastio;
    cin >> N;
    // 우선순위 큐 오름차순 정렬
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++)
    {
        // 입력 받고
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            pq.push(num);
        }
        // 상위 N 개만 남기도록
        while (pq.size() > N)
            pq.pop();
    }
    cout << pq.top() << "\n";
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 2250001
int N;
vector<int> v(MAX_SIZE);
int main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N * N; i++)
        cin >> v[i];
    sort(v.begin(), v.begin() + N * N);
    cout << v[N * N - N] << "\n";
}
*/