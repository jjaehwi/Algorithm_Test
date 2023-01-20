// #include <iostream>
// #include <vector>
// #include <algorithm>

// #define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)

// using namespace std;

// int N, M;
// vector<int> v;

// int main()
// {
//     fastio;
//     cin >> N >> M;
//     for (int i = 0; i < N; i++)
//     {
//         int num;
//         cin >> num;
//         if (find(v.begin(), v.end(), num) != v.end())
//             continue;
//         else
//             v.push_back(num);
//     }

//     sort(v.begin(), v.end());

//     do
//     {
//         for (int i = 0; i < M; i++)
//         {
//             cout << v[i] << " ";
//         }
//         cout << '\n';

//     } while (next_permutation(v.begin(), v.end()));
// }
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, arr[8], res[8]; // arr : 입력받은 수열, res : 길이m인 수열(출력)
bool chk[8] = {false};    // 중복확인

void func(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", res[i]);
        printf("\n");
        return;
    }
    int xx = 0;
    for (int i = 0; i < n; i++)
    {
        if (!chk[i] && arr[i] != xx)
        {
            res[cnt] = arr[i];
            xx = res[cnt];
            chk[i] = true;
            func(cnt + 1);
            chk[i] = false;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    func(0);
}