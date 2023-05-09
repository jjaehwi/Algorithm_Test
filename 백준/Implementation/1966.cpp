// 프린터 큐 S3
// 구현, 시뮬레이션, 자료구조, 큐
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
// 테스트 케이스, 문서의 개수, 궁금한 문서
int t, n, m;
struct doc
{
    int priority;
    int index;
};

int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        queue<doc> q;
        vector<int> v;
        int maxPr = 0;
        int count = 0;
        int result = 0;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            int pr;
            cin >> pr;
            q.push({pr, i});
            v.push_back(pr);
        }

        sort(v.begin(), v.end(), greater<>());

        for (int i = 0; i < n; i++)
        {
            while (1)
            {
                if (v[i] != q.front().priority)
                {
                    q.push({q.front().priority, q.front().index});
                    q.pop();
                }
                else
                    break;
            }
            if (q.front().index == m)
            {
                count++;
                result = count;
                break;
            }
            q.pop();
            count++;
        }
        cout << result << "\n";
    }
}