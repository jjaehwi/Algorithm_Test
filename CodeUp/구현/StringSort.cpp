/* 문자열 재정렬
알파벳 대문자와 숫자(0~9)로만 구성된 문자열이 입력으로 주어집니다. 이때 모든 알파벳을 오름차순으로 정렬하여 이어서 출력한 뒤에, 그 뒤에 모든 숫자를 더한 값을 이어서 출력합니다.
예를 들어, K1KA5CB7이라는 값이 들어오면 ABCKK13을 출력합니다.

문자열이 입력되었을 때 문자를 하나씩 확인합니다.
    - 숫자인 경우 따로 합계를 계산합니다.
    - 알파벳의 경우 별도의 리스트에 저장합니다.

결과적으로 리스트에 저장된 알파벳을 정렬해 출력하고, 합계를 뒤에 붙여 출력하면 정답입니다.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    vector<char> result;
    int value = 0;

    cin >> str;
    // 문자를 하나씩 확인하며
    for (int i = 0; i < str.size(); i++)
    {
        // 알파벳인 경우 결과 리스트에 삽입 --> isalpha 함수 사용
        if (isalpha(str[i]))
            result.push_back(str[i]);
        // 숫자는 따로 더하기
        else
            value += str[i] - '0';
    }

    // 알파벳을 오름차순으로 정렬 --> sort 함수 사용
    sort(result.begin(), result.end());

    // 알파벳을 차례대로 출력
    for (int i = 0; i < result.size(); i++)
        cout << result[i];

    // 숫자가 하나라도 존재하는 경우 가장 뒤에 출력
    if (value != 0)
        cout << value;
    cout << '\n';
}