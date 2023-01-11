// 왼쪽 힙이나 오른쪽 힙 어느 하나를 정해서 항상 원소 수가 같거나 1개 크게 유지하도록 밸런싱
#include <iostream>
#include <queue>
using namespace std;
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int> max;                            // 최대힙
    priority_queue<int, vector<int>, greater<int>> min; // 최소힙
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        // 사이즈가 같으면 최대힙에 넣고, 아니면 최소힙에 넣는다.
        if (max.size() == min.size())
            max.push(num);
        else
            min.push(num);
        if (!max.empty() && !min.empty() && max.top() > min.top())
        {
            int maxNum, minNum;
            maxNum = max.top();
            minNum = min.top();
            max.pop();
            min.pop();
            max.push(minNum);
            min.push(maxNum);
        }
        cout << max.top() << "\n";
    }
}

/* 시간초과
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, s;
priority_queue<int, vector<int>, greater<int>> pq; // 최소힙
vector<int> v;
int main()
{
    // priority_queue<int, vector<int>, less<int>> pq; // 최대 힙
    cin >> N;
    // 우선순위 큐에 원소를 삽입 (push) 한다
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        pq.push(num);
        s = pq.size();

        if (s == 1)
            cout << pq.top() << "\n";
        if (i % 2 == 0)
        {
            for (int i = 0; i < (s / 2) - 1; i++)
            {
                v.push_back(pq.top());
                pq.pop();
            }
            cout << pq.top() << "\n";

            for (int i = 0; i < v.size(); i++)
                pq.push(v[i]);
            v.clear();
        }
        else
        {
            for (int i = 0; i < (s / 2); i++)
            {
                v.push_back(pq.top());
                pq.pop();
            }
            cout << pq.top() << "\n";

            for (int i = 0; i < v.size(); i++)
                pq.push(v[i]);
            v.clear();
        }
    }
} */