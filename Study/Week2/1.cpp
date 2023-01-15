/*
뒤집은 소수
N개의 자연수가 입력되면 각 자연수를 뒤집은 후 그 뒤집은 수가 소수 이면 그 수를 출력하는 프로그램을 작성하세요.
예를 들어 32를 뒤집으 면 23이고, 23은 소수이다. 그러면 23을 출력 한다. 단 910를 뒤집으면 19로 숫자화 해야 한다. 첫 자리부터의 연속된 0은 무시한다.
뒤집는 함 수인 def reverse(x) 와 소수인지를 확인하는 함수 def isPrime(x)를 반드 시 작성하 여 프로그래밍 한다.

▣ 입력설명
첫 줄에 자연수의 개수 N(3<=N<=100)이 주어지고, 그 다음 줄에 N개 의 자연수가 주어진다. 각 자연수의 크기는 100,000를 넘지 않는다.

▣ 출력설명
첫 줄에 뒤집은 소수를 출력합니다. 출력순서는 입력된 순서대로 출력합 니다.

▣ 입력예제 1
5
32 55 62 3700 250
▣ 출력예제 1
23 73

▣ 입력예제 2
27
▣ 출력예제 2
469 84 8851 189 69 1210 682 57 6217 484 8 3590 662 36 8275 887 17 1254 462 67 8969 141 70 5603 958 100 3843
*/
#include <iostream>
using namespace std;
int reverse(int num)
{
    int res = 0;
    while (num > 0)
    {
        int temp = num % 10;
        res = res * 10 + temp;
        num = num / 10;
    }
    return res;
}
bool isPrime(int num)
{
    bool check = true;
    if (num == 1)
        return false;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            check = false;
            break;
        }
    }
    return check;
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        int reverseNum;
        cin >> num;
        reverseNum = reverse(num);
        if (isPrime(reverseNum))
            cout << reverseNum << " ";
    }
}