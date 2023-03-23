// 계란으로 계란치기 G5
// 백트래킹, 브루트포스
/*
가장 왼쪽의 계란을 든다.

손에 들고 있는 계란으로 깨지지 않은 다른 계란 중에서 하나를 친다.
단, 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 치지 않고 넘어간다.
이후 손에 든 계란을 원래 자리에 내려놓고 3번 과정을 진행한다.

가장 최근에 든 계란의 한 칸 오른쪽 계란을 손에 들고 2번 과정을 다시 진행한다.
단, 가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우 계란을 치는 과정을 종료한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_SIZE 8
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int N, maxVal;
struct egg
{
    int durability;
    int weight;
};
vector<egg> v(MAX_SIZE);

void func(int depth)
{
    if (depth == N)
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            if (v[i].durability <= 0)
                sum++;
        maxVal = max(maxVal, sum);

        return;
    }

    // 손에 든 계란이 깨졌으면 치지 않고 넘어간다.
    if (v[depth].durability <= 0)
        return func(depth + 1);

    // 깨지지 않은 다른 계란이 없으면 (다 깨졌으면) 치지 않고 넘어간다.
    bool crash = false;

    for (int i = 0; i < N; i++)
    {
        // i 가 현재 집은 계란이거나 이미 깨졌으면 지나간다.
        if (i == depth || v[i].durability <= 0)
            continue;

        // 깨지지 않았으면 계란을 깼음을 저장하고, 각 계란의 내구도를 낮춘다.
        crash = true;
        v[i].durability -= v[depth].weight;
        v[depth].durability -= v[i].weight;

        func(depth + 1);

        v[i].durability += v[depth].weight;
        v[depth].durability += v[i].weight;
    }

    // 더 이상 깰 계란이 없으면 다음 계란으로 계속 넘어가서 갯수를 센다.
    if (!crash)
        return func(depth + 1);
}
int main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> v[i].durability >> v[i].weight;
    func(0);
    cout << maxVal << "\n";
    return 0;
}