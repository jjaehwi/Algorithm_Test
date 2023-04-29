// 종이자르기 S5
// 정렬
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int col, row, cut;
vector<int> colCut; // 가로
vector<int> rowCut; // 세로
int main()
{
    fastio;
    cin >> col >> row >> cut;
    colCut.push_back(0);
    rowCut.push_back(0);
    colCut.push_back(col);
    rowCut.push_back(row);
    while (cut--)
    {
        int zeroOrOne, num;
        cin >> zeroOrOne >> num;
        // 0 과 가로로 자르는 점, 1 과 세로로 자르는 점
        if (zeroOrOne == 0)
            rowCut.push_back(num);
        else
            colCut.push_back(num);
    }

    // 오름차순 정렬
    sort(rowCut.begin(), rowCut.end());
    sort(colCut.begin(), colCut.end());

    int colMax = 0, rowMax = 0;
    for (int i = 1; i < colCut.size(); i++)
    {
        int temp = colCut[i] - colCut[i - 1];
        colMax = max(colMax, temp);
    }
    for (int i = 1; i < rowCut.size(); i++)
    {
        int temp = rowCut[i] - rowCut[i - 1];
        rowMax = max(rowMax, temp);
    }

    cout << colMax * rowMax;
}