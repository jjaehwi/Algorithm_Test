// 트럭 S1
// 구현, 자료구조, 큐, 그리디
#include <iostream>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1001
int n, w, l;
int truck[MAX_SIZE];
queue<int> bridge;
int main()
{
    fastio;
    cin >> n >> w >> l;
    for (int i = 0; i < n; i++)
        cin >> truck[i];

    int current_weight = 0;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            // 다리에 올라간 트럭이 끝에 도달하면 큐에서 pop
            if (bridge.size() == w)
            {
                current_weight -= bridge.front();
                bridge.pop();
            }
            // 트럭이 올라 갔을 때 무게가 최대 하중보다 가벼우면 while 탈출 후 큐에 트럭 푸시
            if (current_weight + truck[i] <= l)
                break;

            // 만약 다음 트럭이 올라갈 수 없다면 큐에 0 을 푸시해서 계속 밀어냄
            bridge.push(0);
            time++;
        }
        bridge.push(truck[i]);
        current_weight += truck[i];
        time++;
    }
    cout << time + w;
}