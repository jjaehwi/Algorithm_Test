// 게리멘더링 G4
// 그래프 이론, 조합론, bfs, 수학
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 11
int N, res = 987654321;
int person[MAX];
bool connection[MAX][MAX]; // connection [i][j] ==> i 와 j 는 연결되어 있다.
bool selected[MAX];        // 조합 구현 시 뽑았는지 안뽑았는지 판단
bool visited[MAX];         // BFS탐색 시, 방문 탐색을 체크하기 위한 배열

// 인구수 차이를 구하기 위한 함수
void calculate()
{
    int aNum, bNum, diff;
    aNum = bNum = 0;
    for (int i = 1; i <= N; i++)
    {
        // true 인 애들은 a 구역에 false 인 애들은 b 구역이므로
        if (selected[i] == true)
            aNum += person[i];
        else
            bNum += person[i];
    }
    diff = abs(aNum - bNum);
    res = min(diff, res);
}

// 2번 조건 : 선거구에 포함된 구역들끼리 모두 연결되어 있는지를 체크해주기 위한 BFS 함수
bool check_Connection(vector<int> v, bool b)
{
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(v[0]);
    visited[v[0]] = true;
    int count = 1;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        /*
        BFS 탐색 조건 3개
            조건 1 : 현재 구역과 탐색하려는 구역이 연결되어 있는지 ?
            조건 2 : 탐색하려는 구역이 선거구에 맞는 놈인지 ?
            조건 3 : 아직 방문하지 않은 구역인지 ?
        */
        for (int i = 1; i <= N; i++)
        {
            if (connection[current][i] == true && selected[i] == b && !visited[i])
            {
                visited[i] = true;
                q.push(i);
                count++;
            }
        }
    }
    // BFS에서 Count한 값과 Vector의 Size가 같다. = 2번 조건에 위배 되지 않는다
    if (v.size() == count)
        return true;
    return false;
}

/*
선거구가 가질 수 있는 조건들에 대해서 Check 해주는 함수.
    조건 1 : 선거구에 포함된 구역의 갯수가 1개 이상인지 ?
    조건 2 : 선거구에 포함된 구역들 끼리 모두 연결되어 있는지 ?
*/
bool check()
{
    vector<int> A, B;
    // 1, 2 선거구를 나눈다.
    for (int i = 1; i <= N; i++)
    {
        if (selected[i] == true)
            A.push_back(i); // 뽑힌 애들을 A 에 넣고
        else
            B.push_back(i); // 아닌 애들을 B 에 넣음
    }
    /* 1번 조건 Check */
    if (A.size() == 0 || B.size() == 0)
        return false;

    /* 2번 조건 Check */
    // 조합 뽑을 때 true 였던 놈이 A 에 들어갔고 false 였던 놈이 B 에 들어 갔기 때문에 같은 선거구 안에서 연결되어있는지도 확인을 해야하기 때문에 bool 값이 들어간다.
    bool AState = check_Connection(A, true);
    if (AState == false)
        return false;

    bool BState = check_Connection(B, false);
    if (BState == false)
        return false;

    // 위 조건에 다 걸리지 않았으면 true
    return true;
}

// 조합 구현 --> 뽑힌 순서 상관없이 뽑힌 애들로 이뤄진 집합은 다 같은 것이기 때문 --> 뽑힌 놈들과 안뽑힌 놈들로 나눠지게 된다.
void dfs(int startNum, int cur)
{
    // return 을 하지 않는다. 모든 경우에 대해 계속 비교를 하기 때문에
    if (cur >= 1)
    {
        if (check() == true)
            calculate();
    }
    for (int i = startNum; i <= N; i++)
    {
        // 이미 뽑힌 놈이라면 건너뜀
        if (selected[i])
            continue;
        selected[i] = true;
        dfs(i, cur + 1);
        selected[i] = false;
    }
}
int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int peopleNum;
        cin >> peopleNum;
        person[i] = peopleNum;
    }
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            int near;
            cin >> near;
            connection[i][near] = true;
            connection[near][i] = true;
        }
    }
    // 조합
    dfs(1, 0);

    if (res == 987654321)
        cout << "-1\n";
    else
        cout << res << "\n";
}