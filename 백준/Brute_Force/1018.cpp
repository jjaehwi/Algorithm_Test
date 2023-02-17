// 체스판 다시 칠하기 S4
// 브루트 포스
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_SIZE 51
string map[MAX_SIZE];
string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"};
string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"};

int WB_count(int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (map[x + i][y + j] != WB[i][j])
                count++;
    return count;
}
int BW_count(int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (map[x + i][y + j] != BW[i][j])
                count++;
    return count;
}
int main()
{
    fastio;
    int n, m;
    int min_val = 3000;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> map[i];
    for (int i = 0; i + 8 <= n; i++)
        for (int j = 0; j + 8 <= m; j++)
            min_val = min(min_val, min(WB_count(i, j), BW_count(i, j)));

    cout << min_val;
}