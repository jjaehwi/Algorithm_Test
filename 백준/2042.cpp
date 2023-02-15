// 구간 합 구하기 G1
// 세그먼트 트리
#include <iostream>
using namespace std;
#define MAX 1000001
int N, M, K;
int idx = 1;
long long tree[MAX * 4];

// 트리 만들기
void init()
{
    // 부모 = 왼쪽 자식 + 오른쪽 자식
    for (int i = idx - 1; i > 0; i--)
        tree[i] = tree[i * 2] + tree[(i * 2) + 1];
}

// a가 1인 경우 b번째 수를 c로 바꾸는 함수
void change(int b, long long c)
{
    // b번째 위치의 index를 알아낸다.
    b += idx - 1;
    tree[b] = c;
    // 부모까지 갱신
    while (b /= 2) // 부모로 올라가는 조건
        tree[b] = tree[b * 2] + tree[(b * 2) + 1];
}

// a가 2인 경우 b번째 부터 c번째 까지의 구간 합을 반환하는 함수
long long intervalSum(int b, long long c)
{
    long long sum = 0;
    // b 와 c 의 index를 알아낸다.
    b += idx - 1;
    c += idx - 1;
    while (b <= c)
    {
        if ((b % 2) == 1) // b가 트리의 right일 때
            sum += tree[b];
        if ((c % 2) == 0) // c가 트리의 left일 때
            sum += tree[c];

        b = (b + 1) / 2;
        c = (c - 1) / 2;
    }
    return sum;
}

int main()
{
    cin >> N >> M >> K;

    while (idx < N)
        idx <<= 1;
    for (int i = idx; i < N + idx; i++)
        cin >> tree[i];
    init();

    int a, b;
    long long c;
    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
            change(b, c);
        if (a == 2)
            cout << intervalSum(b, c) << "\n";
    }
    return 0;
}