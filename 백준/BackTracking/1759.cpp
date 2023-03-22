// 암호 만들기 G5
// 백트래킹, 브루트포스, 조합론, 수학
// 중복 없이, 알파벳 증가하는 순서로 조합
#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 15
int L, C;
char arr[MAX_SIZE];
char res[MAX_SIZE];
bool check[MAX_SIZE];
bool vowelCheck()
{
    int moum = 0;
    for (int i = 0; i < L; i++)
    {
        if (res[i] == 'a' ||
            res[i] == 'e' ||
            res[i] == 'i' ||
            res[i] == 'o' ||
            res[i] == 'u')
            moum++;
    }
    if (moum >= 1 && L - moum >= 2)
        return true;
    return false;
}
void func(int startNum, int cur)
{
    if (cur == L)
    {
        if (vowelCheck())
        {
            for (int i = 0; i < L; i++)
                cout << res[i];
            cout << "\n";
        }
        return;
    }
    for (int i = startNum; i < C; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            res[cur] = arr[i];
            func(i + 1, cur + 1);
            check[i] = false;
        }
    }
}
int main()
{
    fastio;
    cin >> L >> C;
    for (int i = 0; i < C; i++)
        cin >> arr[i];
    sort(arr, arr + C);
    func(0, 0);
}