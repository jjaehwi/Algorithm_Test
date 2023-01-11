// 삼성 강사님 코드
// 1991 트리순회 풀기
// 예를 들어 치킨집이 10개인데 이중에 7개를 골라야 한다고 가정하면 for 루프로는 어렵고, 이럴 때는 dfs를 쓰면 편하다.
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#define MAX 105
#define NMAX 100000

using namespace std;

int N, M, ans;
struct st
{
    int y, x;
};
vector<st> h, c; // 하우스의 좌표와 치킨집의 좌표를 벡터로

// &로 받는 이유.. 이전 값들을 기억해서 쌓아두기 위해
void dfs(int cur, int g, vector<int> &v)
{
    if (cur == c.size() || g > ans)
        return;
    if (v.size() == M)
    {
        int x[MAX];
        memset(x, 0x3f, sizeof(x));
        for (int cv : v)
            for (int i = 0; i < (int)h.size(); i++)
                x[i] = min(x[i], abs(c[cv].y - h[i].y) + abs(c[cv].x - h[i].x));
        int sum = 0;
        for (int i = 0; i < (int)h.size(); i++)
            sum += x[i];
        ans = min(ans, sum);
        return;
        // 여기를 구현해라.. for문으로 최소값을 구함
        // for (int cv : v)
        //     printf("%d", cv);
        // printf("\n");
        // return;
    }
    // 해당 치킨집을 선택하거나, 생략하고 다음 치킨집을 선택하거나
    dfs(cur + 1, g, v);
    v.push_back(cur + 1);
    dfs(cur + 1, g, v);
    v.pop_back();
}

int main()
{
    scanf("%d%d", &N, &M);
    int a;
    h.clear(), c.clear();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &a);
            // 치킨 집이랑 배달할 집을 쌓음
            if (a == 1)
                h.push_back({i, j});
            else if (a == 2)
                c.push_back({i, j});
        }
    }
    ans = NMAX;
    vector<int> visit;
    // 치킨 집이 h0 부터 시작해서 시작점을 -1로 잡음
    dfs(-1, 0, visit);
    printf("%d\n", ans);
}