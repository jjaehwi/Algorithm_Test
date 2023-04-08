// 최대 상금 [S/W 문제해결 응용] 2일차 D3
// 브루트 포스? dfs
#include <iostream>
#include <cstring>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 1000000
int T, chance, answer;
string str;
bool selected[MAX_SIZE][11];
int invert(string str)
{
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        sum = sum + (str[i] - '0');
        if (i != str.length() - 1)
            sum = sum * 10;
    }
    return sum;
}
void dfs(string str, int cur)
{
    if (cur == chance)
    {
        int temp_answer = invert(str);
        answer = max(answer, temp_answer);
        return;
    }
    for (int i = 0; i < str.length() - 1; i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            swap(str[i], str[j]);
            int temp = invert(str);
            if (selected[temp][cur + 1] == false)
            {
                selected[temp][cur + 1] = true;
                dfs(str, cur + 1);
            }
            swap(str[i], str[j]);
        }
    }
}
int main()
{
    fastio;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        chance = 0;
        answer = 0;
        str.clear();
        memset(selected, 0, sizeof(selected));
        cin >> str >> chance;
        dfs(str, 0);
        cout << "#" << t << " " << answer << "\n";
    }
}