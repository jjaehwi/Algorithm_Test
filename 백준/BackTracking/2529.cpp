// 부등호 S1
// 백트래킹
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 10
int k;
char sign[MAX_SIZE];  // 부등호 배열
bool check[MAX_SIZE]; // 숫자 중복 방지
string num[MAX_SIZE];
vector<string> result;

bool singCheck(char a, char b, char op)
{
    if (op == '<')
    {
        if (a > b)
            return false;
    }
    else
    {
        if (a < b)
            return false;
    }
    return true;
}

void combination(int index, string num)
{
    if (index == k + 1)
    {
        result.push_back(num);
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (check[i])
            continue;
        // 처음이거나, 마지막으로 선택된 숫자와, 현재 선택하는 숫자, 부등호 체크
        if (index == 0 || singCheck(num[index - 1], i + '0', sign[index - 1]))
        {
            check[i] = true; // 숫자 선택
            combination(index + 1, num + to_string(i));
            check[i] = false;
        }
    }
}

int main()
{
    fastio;
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> sign[i];

    combination(0, "");

    sort(result.begin(), result.end());

    cout << result[result.size() - 1] << "\n"
         << result[0];
}