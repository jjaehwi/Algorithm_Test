// 빗물 G5
// 시뮬레이션, 구현
#include <iostream>
#include <vector>

int main()
{
    int T;
    int N, M, K;
    int X, Y;
    int answer = 0;

    cin >> N >> M;
    vector<int> v(M);

    for (int i = 0; i < M; i++)
        cin >> v[i];

    for (int i = 1; i < M - 1; i++)
    {
        int left = 0;
        int right = 0;
        // 왼쪽 최대 값
        for (int j = 0; j < i; j++)
            left = max(left, v[j]);
        // 오른쪽 최대 값
        for (int j = M - 1; j > i; j--)
            right = max(right, v[j]);
        // 빗물 계산
        answer += max(0, min(left, right) - v[i]);
    }

    cout << answer << endl;
    return 0;
}