// Sum [S/W 문제해결 기본] 2일차 D3
// 구현
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 100
int T, answer;
int map[MAX_SIZE][MAX_SIZE];
vector<int> tempSum;
void rowSum()
{
    for (int i = 0; i < 100; i++)
    {
        int sum = 0;
        for (int j = 0; j < 100; j++)
        {
            sum += map[i][j];
        }
        tempSum.push_back(sum);
    }
}
void colSum()
{
    for (int i = 0; i < 100; i++)
    {
        int sum = 0;
        for (int j = 0; j < 100; j++)
        {
            sum += map[j][i];
        }
        tempSum.push_back(sum);
    }
}
void rightDiaSum()
{
    int i = 0, j = 0;
    int sum = 0;
    for (int k = 0; k < 100; k++)
    {
        sum += map[i][j];
        i++;
        j++;
    }
    tempSum.push_back(sum);
}
void leftDiaSum()
{
    int i = 0, j = 99;
    int sum = 0;
    for (int k = 0; k < 100; k++)
    {
        sum += map[i][j];
        i++;
        j--;
    }
    tempSum.push_back(sum);
}
int main()
{
    fastio;
    for (int t = 1; t <= 10; t++)
    {
        answer = 0;
        tempSum.clear();
        memset(map, 0, sizeof(map));
        cin >> T;
        for (int i = 0; i < MAX_SIZE; i++)
            for (int j = 0; j < MAX_SIZE; j++)
                cin >> map[i][j];
        rowSum();
        colSum();
        rightDiaSum();
        leftDiaSum();
        for (int i = 0; i < tempSum.size(); i++)
        {
            answer = max(answer, tempSum[i]);
        }
        cout << "#" << t << " " << answer << "\n";
    }
}