/*
각 자리가 숫자(0부터 9)로만 이뤄진 문자열 S가 주어졌을 때, 왼쪽부터 오른쪽으로 하나씩 모든 숫자를 확인하며 숫자 사이에 'x' 혹은 '+' 연산자를 넣어 결과적으로 만들어질 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.
단, +보다 x를 먼저 계산하는 일반적인 방식과는 달리, 모든 연산은 왼쪽에서부터 순서대로 이뤄진다고 가정합니다.
예를 들어, 02984 라는 문자열로 만들 수 있는 가장 큰 수는 ((((0+2)x9)x8)x4) = 576 이다.
또한 만들어 질 수 있는 가장 큰 수는 항상 20억 이하의 정수가 되도록 입력이 주어진다.
문자열 참고 : https://rebro.kr/53
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    // 첫 번째 문자를 숫자로 변경한 값을 대입
    long long result = s[0] - '0';
    for (int i = 1; i < s.size(); i++)
    {
        // 두 수 중에서 하나라도 0 혹은 1 인 경우, 곱하기 대신 더하기를 수행
        int num = s[i] - '0';
        if (num <= 1 || result <= 1)
            result += num;
        else
            result *= num;
    }
    cout << result << "\n";
}