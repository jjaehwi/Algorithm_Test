// 놀라운 문자열 S3
// 구현, 자료구조, 문자열, 해시를 이용한 집합과 맵
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int>> min; // 최소힙
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long long num;
        cin >> num;
        if (num == 0)
        {
            if (min.empty())
            {
                cout << "0\n";
                continue;
            }
            cout << min.top() << "\n";
            min.pop();
        }
        else
            min.push(num);
    }
}
