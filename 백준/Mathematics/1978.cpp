// 소수 찾기 S5
// 수학, 정수론, 소수 판정, 에라토스테네스의 체
#include <iostream>
using namespace std;

int main()
{
    int N, result = 0;
    int temp, cnt = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        for (int div = 1; div <= temp; div++)
            if (temp % div == 0)
                cnt++;
        if (cnt == 2) // temp가 소수
            result++;
        cnt = 0;
    }
    cout << result << '\n';
}