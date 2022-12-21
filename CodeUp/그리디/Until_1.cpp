/* 어떤 수 N 이 1이 될 때까지 다음의 두 과정 중 하나를 반복적으로 선택하여 수행하려고 한다. 단, 두 번째 연산은 N이 K로 나누어 떨어질 때만 선택할 수 있다.
1. N에서 1을 뺀다.
2. N을 K로 나눈다.
문제 : N과 K가 주어질 때 N이 1이 될 때까지 1번 혹은 2번의 과정을 수행해야 하는 최소 횟수를 구하는 프로그램을 작성해라.. */

#include <iostream>
using namespace std;
int main()
{
    int N, K;
    int count = 0;
    cin >> N >> K;
    while (N != 1)
    {
        if (N % K == 0)
        {
            N /= K;
            count++;
        }
        else
        {
            N -= 1;
            count++;
        }
    }
    cout << count;
}

/*
강의 답안

#include <iostream>

using namespace std;

int n, k;
int result;

int main()
{
    // N, K를 공백을 기준으로 구분하여 입력 받기
    cin >> n >> k;

    while (true)
    {
        // N이 K로 나누어 떨어지는 수가 될 때까지만 1씩 빼기
        int target = (n / k) * k;
        result += (n - target);
        n = target;
        // N이 K보다 작을 때 (더 이상 나눌 수 없을 때) 반복문 탈출
        if (n < k)
            break;
        // K로 나누기
        result += 1;
        n /= k;
    }

    // 마지막으로 남은 수에 대하여 1씩 빼기
    result += (n - 1);
    cout << result << '\n';
}
*/