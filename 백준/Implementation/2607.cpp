// 비슷한 단어 S3
// 구현, 문자열

// 비교 문자열은 기존 문자열과 길이가 같거나 한 글자 차이여야한다.
// 두 문자열에 같은 문자가 몇 개 있는지 저장

// 1. 문자열 길이가 같은 경우 같은 문자를 저장한 변수의 값이 0, 1 이면 가능
// 아예 구성이 같아도 되고, 한 글자만 달라도 되는 것

// 2. 기준 문자열의 길이 - 1 == 비교 문자열의 길이
// 기준 문자열 길이가 1 크다. --> 비교 문자열에 문자 하나를 추가해야한다.
// 추가하기 이전의 구성이 기준 문자열의 구성과 하나 차이가 나야 한다 --> 같은 문자의 수를 저장한 변수의 값이 1 보다 작아야한다.

// 3.  기준 문자열의 길이 + 1 == 비교 문자열의 길이
// 삭제하기 이전의 구성이 기준문자열의 구성과 동일하면서 다른 문자가 하나 추가된 경우여야 하기 때문에,
// 같은 문자가 몇 개 있는지 저장한 변수의 값이 기준 문자열과 동일해야 한다.

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int n, res;
string stand, comp;
int alpha[26];     // 알파벳 구성
int copyAlpha[26]; // alpha 복사본
int main()
{
    fastio;
    cin >> n;
    cin >> stand;
    // stand 입력의 알파벳 개수를 A ~ Z 까지 (0 ~ 26) 의 배열로 저장
    for (int i = 0; i < stand.length(); i++)
        alpha[stand[i] - 'A'] += 1;

    for (int i = 0; i < n - 1; i++)
    {
        copy(alpha, alpha + 26, copyAlpha);
        cin >> comp;

        int same = 0;
        for (int j = 0; j < comp.length(); j++)
        {
            if (copyAlpha[comp[j] - 'A'] > 0)
            {
                copyAlpha[comp[j] - 'A']--;
                same++;
            }
        }

        // 두 길이가 같을 때
        if (stand.length() == comp.length())
        {
            // 구성이 같거나, 한 글자만 다른 경우
            if (same == stand.length() || same == stand.length() - 1)
                res++;
        }

        // 기준 문자가 한 글자 길 때
        else if (stand.length() - 1 == comp.length() && stand.length() - same <= 1)
            res++;

        // 기준 문자가 한 글자 짧을 때
        else if (stand.length() + 1 == comp.length() && same == stand.length())
            res++;

        else
            continue;
    }
    cout << res << "\n";
}